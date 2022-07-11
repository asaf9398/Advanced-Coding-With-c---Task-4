#include "Tree.h"
#include "TreeNode.h"
#include <stdlib.h>
#include<stdio.h>

/*The following function gets an array + size and returns tree(struct) "in order"
by the center of each sub-array*/
Tree BuildTreeFromArray(int* arr, int  size)
{
	Tree tree;
	tree.root = BuildTreeFromArrayHelper(arr, size);
	return tree;
}

//The following function gets a Tnode* and returns a tree(struct)
Tree CreateTree(TreeNode* tNode)
{
	Tree tr;
	tr.root = tNode;
	return tr;
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
		TreeNode* root=createTreeNode(arr[size / 2]);
		root->right = BuildTreeFromArrayHelper(arr+(size/2)+1,(size/2));
		root->left = BuildTreeFromArrayHelper(arr,(size/2));
		return root;
	}
}

//The followng function prints the tree in-order (LDR)
void printTreeInorder(Tree tr)
{
	printTreeInorderHelper(tr.root);
}

//The followng function is an helper for printing tree in-order (LDR)
void printTreeInorderHelper(TreeNode * root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printTreeInorderHelper(root->left);//print left sub tree
		printf("%d ", root->data);//print root's value
		printTreeInorderHelper(root->right);//print right sub tree
	}
	
}

//The following function frees the nodes in the tree
void freeTree(Tree tr)
{
	freeTreeHelper(tr.root);
}

//The following function is a helper for free the nodes in the tree
void freeTreeHelper(TreeNode * root)
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
