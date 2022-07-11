#ifndef __LINKED_LIST_NODE_H
#define __LINKED_LIST_NODE_H
#include <stdlib.h>
#include <stdio.h>
#include "TreeNode.h"

typedef struct linkedListNode {
	TreeNode* data;
	struct linkedListNode* next;
} LNODE;

LNODE* createNewListNode(TreeNode* root,LNODE * next);
void checkAllocListNode(LNODE* node);


#endif // !__LINKED_LIST_NODE_H
