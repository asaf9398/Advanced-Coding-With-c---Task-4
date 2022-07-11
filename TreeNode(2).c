#include "TreeNode.h"

//The following function creates TreeNode and saves it in the heap + initializes it with value
TreeNode* createTreeNode(int num, TreeNode* parent, TreeNode* left, TreeNode* right)
{
	TreeNode* trNodeP = (TreeNode*)malloc(sizeof(TreeNode));
	trNodeP->data = num;
	trNodeP->parent = parent;
	trNodeP->left = left;
	trNodeP->right = right;
	return trNodeP;
}

//The following fucntion checks memory allocation for TreeNode
void checkAllocTreeNode(TreeNode* trNodeP)
{
	if (trNodeP == NULL)
	{
		printf("Memory Allocation failed!! Exiting");
		exit(1);
	}
}