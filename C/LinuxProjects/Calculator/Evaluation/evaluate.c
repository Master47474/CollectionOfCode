//Evaluating the tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//imports
#ifndef FILE_DEFINITIONS
#define FILE_DEFINITIONS
#include "../MainFiles/definitions.c"
#endif

term* EvalueateTree(struct node* current){
	term* x, y;
	
	// left is x
	// check if left is an operation
	if(current->left->value->boolisOperation == 1){
		printf("going Left Because Operation\n");
		x = EvalueateTree(current->left);
	} else{
		x = current->left->value ;
	}

	//right is y
	//check if right is an operation
	if(current->right->value->boolisOperation == 1){
		printf("going right Because Operation\n");
		y = EvalueateTree(current->right);
	}else{
		y = current->right->value;
	}
	//printf("this is X, %f \n", x);
	//printf("this is Y, %f \n", y);
	//printf("GOING UP\n");
	// return x (operation) right
	if(!strcmp(current->value, "+"))
		return x + y;
	if(!strcmp(current->value, "-"))
		return x - y;
	if(!strcmp(current->value, "*"))
		return x * y;
	if(!strcmp(current->value, "/"))
		return (x/y);
}







