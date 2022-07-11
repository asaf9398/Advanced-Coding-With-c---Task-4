#include "Tree.h"

/*scan the tree inorder (LDR) and find the first parent
(a node with parentData as data) that has no child in branchSelect*/
TreeNode* findParent(Tree tr, int parentData, int branchSelect)
{
	return findParentHelper(tr.root, parentData, branchSelect);
}


//The following function is a helper for findParent
TreeNode* findParentHelper(TreeNode * root, int parentData, int branchSelect)
{

	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (root->data == parentData)
				return root;
			else
			{
				return NULL;
			}
		}
		if (root->left == NULL && root->right != NULL)
		{
			if (root->data == parentData&&branchSelect==LEFT)
			{
				return root;
			}	
			else
			{
				TreeNode* rightOutcome = findParentHelper(root->right, parentData, branchSelect);
				if (rightOutcome != NULL)
				{
					return rightOutcome;
				}
				else
				{
					return NULL;
				}

			}
		}
		else
		{
			if (root->left != NULL && root->right == NULL)
			{
				if (root->data == parentData && branchSelect == RIGHT)
				{
					return root;
				}
				else
				{
					TreeNode* leftOutcome = findParentHelper(root->left, parentData, branchSelect);
					if (leftOutcome != NULL)
					{
						return leftOutcome;
					}
					else
					{
						return NULL;
					}
				}
			}
			else
			{
				if (root->left != NULL && root->right != NULL)
				{
					TreeNode* leftOutcome = findParentHelper(root->left, parentData, branchSelect);
					TreeNode* rightOutcome = findParentHelper(root->right, parentData, branchSelect);
					if (leftOutcome == NULL && rightOutcome == NULL)
					{
						return NULL;
					}
					else
					{
						if (leftOutcome != NULL && rightOutcome == NULL)
						{
							return leftOutcome;
						}
						else
						{
							if (leftOutcome == NULL && rightOutcome != NULL)
							{
								return rightOutcome;
							}
							else
							{
								if (leftOutcome != NULL && rightOutcome != NULL)
								{
									int leftOutComeHight=checkHeight(root,leftOutcome);
									int rightOutComeHight=checkHeight(root,rightOutcome);
									if (leftOutComeHight < rightOutComeHight)
									{
										return leftOutcome;
									}
									else
									{
										return rightOutcome;
									}

								}
							}

						}
					}
				}
			}
		}
	}
	
	
	
}

//The following function checks the height of node
int checkHeight(TreeNode* root,TreeNode* node)
{
	int heightLeft, heightRight;
	if (root == NULL)
		return -1;
	else
	{
		if (root == node)
		{
			return 0;
		}
		else
		{
			heightLeft = checkHeight(root->left, node);
			heightRight = checkHeight(root->right, node);
			if (heightLeft > heightRight)
			{
				return (1 + heightLeft);
			}
			else
			{
				return (1 + heightRight);
			}

		}
	}

}

/*The following function gets an array + size and returns tree(struct) "in order"
by the center of each sub-array with a list of leafs*/
Tree BuildTreeFromArrayWithLeafList(int* arr, int  size)
{
	Tree tree;
	List lst = createEmptyList();
	tree.root = BuildTreeFromArrayWithLeafListHelper(arr, size);
	lst = ListOfLeafsHelper(tree.root);
	tree.leafList = lst;
	return tree;
}


//The following function returns a list of the leafs of the tree that has this root
List ListOfLeafsHelper(TreeNode* root)
{
	if (root == NULL)
	{
		List lst = createEmptyList();
		return lst;
	}
	if (root != NULL && root->left == NULL && root->right == NULL)
	{
		List lst = createEmptyList();
		insertDataToEndList(&lst,root->data);
		return lst;
	}
	if (root != NULL && root->left != NULL && root->right == NULL)
	{
		List lst = createEmptyList();
		lst=ListOfLeafsHelper(root->left);
		return lst;
	}
	if (root != NULL && root->left == NULL && root->right != NULL)
	{
		List lst = createEmptyList();
		lst = ListOfLeafsHelper(root->right);
		return lst;
	}
	if (root != NULL && root->left != NULL && root->right != NULL)
	{
		List lst = createEmptyList();
		List leftList=ListOfLeafsHelper(root->left);
		List rightList = ListOfLeafsHelper(root->right);
		lst.head = leftList.head;
		lst.tail = rightList.tail;
		leftList.tail->next = rightList.head;
		return lst;
	}
}

//The following function gets a Tnode* and returns a tree(struct)
Tree CreateTree(TreeNode* tNode)
{
	Tree tr;
	tr.root = tNode;
	return tr;
}
/*The following function gets an array + size and returns
root of a tree (TreeNode*) that is "in order" by the center of each sub-array,with list of his leafs*/
TreeNode* BuildTreeFromArrayWithLeafListHelper(int* arr, int  size)
{
	if (size == 0 || arr[size / 2] == -1)
	{
		return NULL;
	}
	else
	{
		TreeNode* root = createTreeNode(arr[size / 2],NULL,NULL,NULL);
		root->right = BuildTreeFromArrayWithLeafListHelper(arr + (size / 2) + 1, (size / 2));
		if (root->right != NULL)
		{
			root->right->parent = root;
		}
		root->left = BuildTreeFromArrayWithLeafListHelper(arr, (size / 2));
		if (root->left != NULL)
		{
			root->left->parent = root;
		}
		return root;
	}
}

//The followng function prints the tree in-order (LDR)
void printTreeInorder(Tree tr)
{
	printTreeInorderHelper(tr.root);
}

//The followng function is an helper for printing tree in-order (LDR)
void printTreeInorderHelper(TreeNode* root)
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


//The following function gets a tree + leaf + data and adds data to the leaf as a son
Tree AddLeaf(Tree tr, TreeNode* p, int branchSelect, int data)
{
	if (branchSelect == LEFT)
	{
		p->left = createTreeNode(data,p,NULL,NULL);
		checkAllocTreeNode(p->left);
	}
	else
	{
		p->right = createTreeNode(data,p,NULL,NULL);
		checkAllocTreeNode(p->right);
	}
	List lst = createEmptyList();
	lst = ListOfLeafsHelper(tr.root);
	tr.leafList = lst;
	return tr;

}



//The following function prints the leaf's list
void printLeafList(Tree tr)
{
	ListNode* curr = tr.leafList.head;
	while (curr!=NULL)
	{
		printf("%d ", curr->data);
		curr=curr->next;
	}
}

