#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//file Imports
#ifndef FILE_DEFINITIONS
#define FILE_DEFINITIONS
#include "definitions.c"
#include "../Misc/Sorts/countingSort.c"
#endif
#include "../InputCapture/InputCapture.h"
#include "../Parsing/parsetree.c"

#include "../Evaluation/evaluate.c"




void Debug(term* expression);
void PrintExpression(term* expression);
// main

int main(void){
	printf("we Capture \n");
	term* expression = captureInput();
	printf("done Capture\n");
	Debug(expression);
	printf("Build Tree Starting\n");
	node* tree = buildParseTree(expression);
	printf("Build Tree Done \n");
	printInOrder(tree);
	printf("\n");
	fflush(stdin);
	printf("About to Evaluate\n");
	node* result = EvalueateTree(tree);
	printf("Evalueate Done\n");
	//printInOrder(result);
	//printf("\n");
	//Debug(result->value);
	//printf("\n");
	PrintExpression(result->value);
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
		}
		if(valueincoeff(curTerm) == 1){
			printf("%s", curTerm.coefficient);
		}
		if(valueinalpha(curTerm) == 1){
			printf("%s", curTerm.alphanumeric);
		}
		printf("\", ");
	}
}

void PrintExpression(term* expression){
	int i = 0;
	while(1){
		term curTerm = expression[i++];
		if(curTerm.isTermination){
			printf("\n");
			break;
		}
		if(valueincoeff(curTerm) == 1){
			if(strcmp(curTerm.coefficient, "1") || valueinalpha(curTerm) == 0)
				printf("%s", curTerm.coefficient);
		}
		if(valueinalpha(curTerm) == 1)
			printf("%s", curTerm.alphanumeric);
		printf(" ");
	}
}
