#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//file Imports
#ifndef FILE_DEFINITIONS
#define FILE_DEFINITIONS
#include "definitions.c"
#endif
#include "../InputCapture/InputCapture.h"
#include "../Parsing/parsetree.c"

//#include "../Evaluation/evaluate.c"




void Debug(term* expression);
// main

int main(void){
	printf("we Capture \n");
	term* expression = captureInput();
	printf("done Capture\n");
	Debug(expression);
	printf("Build Tree Starting\n");
	struct node* tree = buildParseTree(expression);
	printf("Build Tree Done \n");
	printInOrder(tree);
	printf("\n");
	//char** stringy = captureInput();
	//printDebug(stringy);
	//printf("before Building\n");
	//struct node* tree = buildParseTree(stringy);
	//printf("after Buidlsing\n");
	//printInOrder(tree);
	//printf("\n");	
	//float result = EvalueateTree(tree);
	//printf("THIS IS THE RESULT %f\n", result);
	return EXIT_SUCCESS;
}

void Debug(term* expression){
	int i = 0;
	printf("{ ");
	while(1){
		term curTerm = expression[i++];
		printf("\"");
		if(curTerm.isTermination){
			printf("NULL\" }\n");
			break;
		}else if(curTerm.boolisOperation == 1 || curTerm.boolhascoeff == 1 || curTerm.boolBracket == 1){
			printf("%s", curTerm.coefficient);
		}else if(curTerm.boolhasalpha == 1){
			printf("%s", curTerm.alphanumeric);
		}
		printf("\", ");
	}
}
