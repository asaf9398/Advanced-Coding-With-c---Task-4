#include "Tree.h"

//The following function gets a string and builds a tree by the definition
//The function returns 1/0 if the expression tree is legal or not
int buildExpressionTree(char* str, Tree* tr)
{
	int legal;
	tr->root = NULL;
	legal = checkIfLegalBrackets(str);
	if (legal != 0)
	{ //if the string is valid -> build the tree
		*tr = createExpressionTree(str,&legal);
	}
	return legal;
}

/*The following function gets a string and returns if the string has the same number of '(' and ')' */
int checkIfLegalBrackets(char* str)
{
	int index = 0;//running on the string
	int counterLeftBrackets = 0;//counting '('
	int counterRightBrackets = 0;//counting ')'
	while (str[index] != '\0')//run on str and count the number of brackets
	{
		if (str[index] == '(')
		{
			counterLeftBrackets++;//count '('
		}
		else if (str[index] == ')')
		{
			counterRightBrackets++;//count ')'
		}
		index++;
	}
	if (counterLeftBrackets == counterRightBrackets)
		return 1;//true
	else
		return 0;//false
}




//The following function builds the tree(by the definition) and returns it
Tree createExpressionTree(char* str,int * legal)
{
	Tree tr;
	tr.root = createExpressionTreeHelper(str,legal);
	return tr;
}

//The following function is a helper for buildTree
TreeNode* createExpressionTreeHelper(char* str,int * legal)
{
	bool legalChOperator = true;
	int operatorLocation;
	char tempCh;
	TreeNode* root = createTreeNode('\0');
	TreeNode* leftSon, * rightSon;
	if (str[1] == '\0')
	{ //if str is empty -> root's data is '\0'(and no sons)
		root->data = str[0];
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		//if there is an exression -> find the operator
		operatorLocation = findOperator(str);
		root->data = str[operatorLocation];
		if (str[operatorLocation] == '(' || str[operatorLocation] == ')')
		{
			*legal = 0;
			legalChOperator = false;
		}
		if (legalChOperator == true)
		{
			//create left tree's root and put as left son
			tempCh = str[operatorLocation];//save operator's value
			str[operatorLocation] = '\0';//put \0 on the operator to get left sub string
			leftSon = createExpressionTreeHelper(str + 1,legal);//build left tree(left son of root) by the left sub string
			root->left = leftSon;

			//create right tree's root and put as right son
			str[operatorLocation] = tempCh;//return the saved operator's value
			tempCh = str[strlen(str) - 1];//save last char 
			str[strlen(str) - 1] = '\0';//put \0 on the operator to get right sub string
			rightSon = createExpressionTreeHelper(str + operatorLocation + 1,legal);//build right tree(right son of root) by the right sub string
			root->right = rightSon;
			str[strlen(str) + 1] = '\0';
			str[strlen(str)] = tempCh;//return the saved operator's value
		}
		else
		{
			return NULL;
		}
		
	}
	return root;



}


//The following function returns the index of the chOperator insinde str
//if there is no legal operator ->return -1(not found)
int findOperator(char* str)
{
	int bracketscounter = 0;
	int operatorChCoutner = 0;
	int ind = 0;//place indicator
	bool found = false;
	while ((str[ind] != '\0') && (found == false))//scan the string for the operator until you found it or if you end it
	{
		if (str[ind] == '(')
		{
			bracketscounter++;
		}
		else if (isLegalChOperator(str[ind]))//checking if the operator is legal
		{
			operatorChCoutner++;
		}
		if (operatorChCoutner == bracketscounter)
		{
			//found the operator + the brackes are closed(we found the operator) -> update found to be true
			found = true;
		}
		ind++;
	}
	return ind - 1;
}


//The following function checks if the chOperator is legal and returns true/false 
bool isLegalChOperator(char chOperator)
{
	switch (chOperator)
	{
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	case '%':
		return true;
		break;
	default:
		return false;
		break;
	}
}


//The following function calculates the tree's outcome
double calcExpression(Tree tr)
{
	return calcExpressionHelper(tr.root);
}

//The following function is a helper for calcExpression
double calcExpressionHelper(TreeNode* node)
{
	double outcome, leftOutcome, rightOutcome;
	if (isLegalNumber(node->data))//checking if root has a legal number, if true -> return it's value
	{
		outcome = (node->data - '0');
	}
	else//root is an operator
	{
		if (isLegalNumber(node->left->data))
		{
			leftOutcome = node->left->data - '0';//if the left son is legal number -> return it's value
		}
		else
		{
			leftOutcome = calcExpressionHelper(node->left);//if the left son is not legal number -> check left tree's value
		}
		if (isLegalNumber(node->right->data))//if the right son is legal number -> return it's value
		{
			rightOutcome = node->right->data - '0';
		}
		else
		{
			rightOutcome = calcExpressionHelper(node->right);//if the right son is not legal number -> check left tree's value
		}
		outcome = calculateOutcome(leftOutcome, rightOutcome, node->data);//calculate the total outcome 
	}
	return outcome;
}

//The following function returns if the node's data is a legal number
bool isLegalNumber(char ch)
{
	int value = ch - '0';
	return(value <= 9 && value >= 0 ? true : false);
}

//The following function calculates and returns the outcome by the chOperator that given
double calculateOutcome(double leftOucome, double rightOucome, char chOperator)
{
	double totalOutcome;
	switch (chOperator)
	{
	case '+':
		totalOutcome = leftOucome + rightOucome;
		break;
	case '-':
		totalOutcome = leftOucome - rightOucome;
		break;
	case '*':
		totalOutcome = leftOucome * rightOucome;
		break;
	case '/':
		totalOutcome = leftOucome / rightOucome;
		break;
	case '%':
		totalOutcome = (int)leftOucome % (int)rightOucome;// % only on whole numbers
		break;
	default:
		break;
	}
	return totalOutcome;
}

//The following function free the tree 
void freeTree(Tree tr)
{
	freeTreeHelper(tr.root);
}

//The following function is a helper for freeTree
void freeTreeHelper(TreeNode* node)
{
	if (node != NULL)
	{
		freeTreeHelper(node->left);
		freeTreeHelper(node->right);
		free(node);
	}
}
