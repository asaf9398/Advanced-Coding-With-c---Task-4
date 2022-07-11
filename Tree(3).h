#ifndef __TREE_H
#define __TREE_H
#include <stdlib.h>

typedef struct tree {
	TreeNode* root;
} Tree;

void printByLevels(Tree tr);
Tree BuildTreeFromArray(int* arr, int  size);
TreeNode* BuildTreeFromArrayHelper(int* arr, int  size);
void freeTree(Tree tr);
void freeTreeHelper(TreeNode* root);
void printByLevelsHelper(TreeNode* root);


#endif // !__TREE_H
