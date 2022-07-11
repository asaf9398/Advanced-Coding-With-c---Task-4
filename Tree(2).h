#ifndef __TREE_H
#define __TREE_H
#include "TreeNode.h"
#include "List.h"
#include <stdlib.h>
#include<stdio.h>

#define LEFT  0
#define RIGHT 1

typedef struct tree {
	TreeNode* root;
	List leafList;   /*øùéîä î÷åùøú ùì ëì äòìéí áòõ*/
} Tree;




Tree BuildTreeFromArrayWithLeafList(int* arr, int  size);
Tree CreateTree(TreeNode* tNode);
TreeNode* BuildTreeFromArrayWithLeafListHelper(int* arr, int  size);
void printTreeInorder(Tree tr);
void printTreeInorderHelper(TreeNode* root);
void freeTree(Tree tr);
void freeTreeHelper(TreeNode* root);
Tree AddLeaf(Tree tr, TreeNode* p, int branchSelect, int data);
void checkAllocTreeNode(TreeNode* node);
List ListOfLeafsHelper(TreeNode* root);
void printLeafList(Tree tr);
TreeNode* findParent(Tree tr, int parentData, int branchSelect);
TreeNode* findParentHelper(TreeNode* root, int parentData, int branchSelect);
int checkHeight(TreeNode* root, TreeNode* node);

#endif // !__TREE_H
