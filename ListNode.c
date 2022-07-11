#include "ListNode.h"

//The following function creates new list node
ListNode* createNewListNode(int data, ListNode* next)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->next = next;
	return node;
}

//The following function checks if allocation succeeded or not
void checkAllocLNode(ListNode* node)
{
	if (node == NULL)
	{
		printf("Memory allocation failed!! Exiting");
		exit(1);
	}
}