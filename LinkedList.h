#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H
#include "LinkedListNode.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct linkedList {
	LNODE* head;
	LNODE* tail;
} LIST;

void makeEmptyList(LIST* lst);
void insertDataToEndList(LIST* lst, TreeNode* root);
bool isEmptyList(LIST* lst);
void insertNodeToEndList(LIST* lst, LNODE* tail);
void printList(LIST* lst);
void freeList(LIST lst);


#endif // !__LINKED_LIST_H
