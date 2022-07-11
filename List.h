#ifndef __LIST_H
#define __LIST_H
#include "ListNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct list {
	ListNode* head;
	ListNode* tail;
} List;

List createEmptyList();
void checkAllocListNode(ListNode* node);
void insertDataToEndList(List* lst, int data);
void insertNodeToEndList(List* lst, ListNode* tail);
bool isEmptyList(List* lst);

#endif // !__LIST_H
