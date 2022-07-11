#ifndef __TreeNode_H
#define __TreeNode_H


typedef struct treeNode
{
    unsigned int data;
    struct treeNode* left;
    struct treeNode* right;
}TreeNode;

TreeNode * createTreeNode(int num);
void checkAllocTreeNode(TreeNode* trNodeP);

#endif 


 
