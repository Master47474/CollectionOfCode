//Evaluating the tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



float EvalueateTree(struct node* current){
	float x, y;
	
	// left is x
	// check if left is an operation
	printf("Left -> %c \n", current->left->value[0]);
	if(isOperation(current->left->value[0])){
		printf("going Left\n");
		x = EvalueateTree(current->left);
	} else{
		x = atoi(current->left->value);
	}

	//right is y
	//check if right is an operation
	printf("Right -> %c \n", current->right->value[0]);
	if(isOperation(current->right->value[0])){
		printf("going right\n");
		y = EvalueateTree(current->right);
	}else{
		y = atoi(current->right->value);
	}
	printf("this is X, %f \n", x);
	printf("this is Y, %f \n", y);
	printf("GOING UP\n");
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
