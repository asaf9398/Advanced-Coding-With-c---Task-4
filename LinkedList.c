#include "LinkedList.h"


//The following function creates empty List
void makeEmptyList(LIST* lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}

//The following function creates node with data ,and adds it to the end of the list 
void insertDataToEndList(LIST* lst, TreeNode* root)
{
	LNODE* newTail;
	newTail = createNewListNode(root, NULL);
	checkAllocListNode(newTail);
	insertNodeToEndList(lst, newTail);
}


//The following function checks if the list is empty or not
bool isEmptyList(LIST* lst)
{
	if (lst->head == NULL)
		return true;
	else
		return false;
}

//The following function adds node to end list
void insertNodeToEndList(LIST* lst, LNODE* tail)
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

//The following function prints the list
void printList(LIST* lst)
{
	LNODE* curr;
	curr = lst->head;
	while (curr != NULL)
	{
		printf("%d ", curr->data->data);
		curr = curr->next;
	}
	printf("\n");
}

//The following function free the list
void freeList(LIST lst)
{
	LNODE* lstHead = lst.head;
	LNODE* next = lstHead->next;
	while (lstHead != NULL)
	{
		free(lstHead);
		lstHead = next;
		next = next->next;
		lst.head = lstHead;
	}
}