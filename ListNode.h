#ifndef __LIST_NODE_H
#define __LIST_NODE_H
#include <stdlib.h>
#include<stdio.h>

typedef struct listNode {
	int data;
	struct listNode* next;
} ListNode;

ListNode* createNewListNode(int data, ListNode* next);
void checkAllocLNode(ListNode* node);


#endif // !__LIST_NODE_H
