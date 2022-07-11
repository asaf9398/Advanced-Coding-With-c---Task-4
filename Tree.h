#ifndef __Tree_H
#define __Tree_H

#include "TreeNode.h"

typedef struct tree
{
    TreeNode* root;
}Tree;

Tree CreateTree(TreeNode * tNode);
Tree BuildTreeFromArray(int* arr, int  size);
TreeNode* BuildTreeFromArrayHelper(int* arr, int  size);
void printTreeInorder(Tree tr);
void printTreeInorderHelper(TreeNode* root);
void freeTree(Tree tr);
void freeTreeHelper(TreeNode* root);


#endif 



