#ifndef __Tree_H
#define __Tree_H
#define _CRT_SECURE_NO_WARNINGS
#include "TreeNode.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	TreeNode* root;
}Tree;

int buildExpressionTree(char* str, Tree* tr);
int checkIfLegalBrackets(char* str);
Tree createExpressionTree(char* str, int* legal);
TreeNode* createExpressionTreeHelper(char* str, int* legal);
int findOperator(char* str);
bool isLegalNumber(char ch);
double calcExpression(Tree tr);
bool isLegalChOperator(char chOperator);
double calcExpressionHelper(TreeNode* node);
double calculateOutcome(double leftOucome, double rightOucome, char chOperator);
void freeTree(Tree tr);
void freeTreeHelper(TreeNode* node);

#endif 



