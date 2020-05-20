#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//file Imports
#include "../InputCapture/InputCapture.h"
#include "../Parsing/parsetree.c"
#include "../Evaluation/evaluate.c"



void printDebug(char** string);

// main

int main(void){
	char** stringy = captureInput();
	printDebug(stringy);
	printf("before Building\n");
	struct node* tree = buildParseTree(stringy);
	printf("after Buidlsing\n");
	printInOrder(tree);
	printf("\n");	
	float result = EvalueateTree(tree);
	printf("THIS IS THE RESULT %f\n", result);
	return EXIT_SUCCESS;
}


void printDebug(char** string){
	int i = 0;
	printf("{");
	while(strcmp(string[i], "\0"))
		printf("\"%s\", ",string[i++]);
	printf("}\n");
}
