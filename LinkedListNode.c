#include "LinkedListNode.h"


//The following function creates new list node
LNODE* createNewListNode(TreeNode* root,LNODE * next)
{
	LNODE* node = (LNODE*)malloc(sizeof(LNODE));
	node->data = root;
	node->next = next;
	return node;
}

//The following function checks if allocation succeeded or not
void checkAllocListNode(LNODE* node)
{
	if (node == NULL)
	{
		printf("Memory allocation failed!! Exiting");
		exit(1);
	}
}