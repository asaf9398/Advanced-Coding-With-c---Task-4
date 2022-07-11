#include "TreeNode.h"
#include "Tree.h"
#include "LinkedList.h"


//The following function prints a binary tree by levels
void printByLevels(Tree tr)
{
	printByLevelsHelper(tr.root);
}

//The following function is an helper to printByLevels
void printByLevelsHelper(TreeNode* root)
{
	LIST queue;
	makeEmptyList(&queue);
	TreeNode* queueNode = root;
	insertDataToEndList(&queue, queueNode);

	while (!isEmptyList(&queue)) {
		printf("%d ", queueNode->data);

		/*pushing left child's data into list(queue)*/
		if (queueNode->left!=NULL)
			insertDataToEndList(&queue, queueNode->left);

		/*pushing right child's data into list(queue)*/
		if (queueNode->right != NULL)
			insertDataToEndList(&queue, queueNode->right);

		/*Dequeue node and make it temp_node*/
		LNODE* headToDelete = queue.head;
		queue.head = queue.head->next;
		free(headToDelete);
		if (queue.head != NULL)//avoiding access to NULL pointer
		{
			queueNode = queue.head->data;
		}
	}
}

/*The following function gets an array + size and returns tree(struct) "in order"
by the center of each sub-array*/
Tree BuildTreeFromArray(int* arr, int  size)
{
	Tree tree;
	tree.root = BuildTreeFromArrayHelper(arr, size);
	return tree;
}


/*The following function gets an array + size and returns
root of a tree (TreeNode*) that is "in order" by the center of each sub-array*/
TreeNode* BuildTreeFromArrayHelper(int* arr, int  size)
{
	if (size == 0 || arr[size / 2] == -1)
	{
		return NULL;
	}
	else
	{
		TreeNode* root = createTreeNode(arr[size / 2]);
		root->right = BuildTreeFromArrayHelper(arr + (size / 2) + 1, (size / 2));
		root->left = BuildTreeFromArrayHelper(arr, (size / 2));
		return root;
	}
}

//The following function frees the nodes in the tree
void freeTree(Tree tr)
{
	freeTreeHelper(tr.root);
}

//The following function is a helper for free the nodes in the tree
void freeTreeHelper(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		freeTreeHelper(root->left);//free left sub-tree
		freeTreeHelper(root->right);//free right sub-tree
		free(root);//free the root after free the right&left sub trees! (if we won't free it on the end we will lose the other TreeNodes)
	}

}

