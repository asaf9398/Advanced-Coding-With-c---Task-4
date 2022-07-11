#ifndef __TREE_NODE_H
#define __TREE_NODE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;

TreeNode* createTreeNode(int num);
void checkAllocTreeNode(TreeNode* trNodeP);

#endif // !__TREE_NODE_H
