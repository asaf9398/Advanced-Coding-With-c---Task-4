#ifndef __TreeNode_H
#define __TreeNode_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode
{
    char data;
    struct treeNode* left;
    struct treeNode* right;
}TreeNode;

TreeNode* createTreeNode(char ch);
void checkAllocTreeNode(TreeNode* trNodeP);

#endif 



