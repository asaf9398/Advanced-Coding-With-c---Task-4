#define _CRT_SECURE_NO_WARNINGS
#include "TreeNode.h"
#include "Tree.h"
#include<stdio.h>

#define SIZE 100

void main()
{
    int size, i;
    int arr[SIZE];
    Tree tr;
    printf("Please enter the number of items: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    tr = BuildTreeFromArray(arr, size);
    printf("The tree in inorder (LDR) format:\n");
    printTreeInorder(tr); //Print the tree in-order (LDR)
    freeTree(tr);

}