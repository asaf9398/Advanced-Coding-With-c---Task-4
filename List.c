#include "List.h"

//The following function creates empty list
List createEmptyList()
{
	List lst;
	lst.head = NULL;
	lst.tail = NULL;
}

//The following function adds data it to the end of the list 
void insertDataToEndList(List* lst, int data)
{
	ListNode * newTail=createNewListNode(data, NULL);
	checkAllocLNode(newTail);
	insertNodeToEndList(lst, newTail);
}

//The following function adds node to end list
void insertNodeToEndList(List* lst, ListNode* tail)
{
	if (isEmptyList(lst) == true) {
		lst->head = lst->tail = tail;
	}
	else {
		lst->tail->next = tail;
		lst->tail = tail;
	}
	tail->next = NULL;
}

//The following function checks if the list is empty or not
bool isEmptyList(List* lst)
{
	if (lst->head == NULL)
		return true;
	else
		return false;
}

//The following function checks alloctino for ListNode
void checkAllocListNode(ListNode* node)
{
	if (node == NULL)
	{
		printf("Memory allocation failed! Exiting");
		exit(1);
	}
}