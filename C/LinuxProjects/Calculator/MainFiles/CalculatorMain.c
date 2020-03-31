#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//file Imports
#include "../InputCapture/InputCapture.h"


void printDebug(numtok** string);

// main

int main(void){
	printf("LEts start\n");
	printDebug(captureInput());


	return EXIT_SUCCESS;
}


void printDebug(numtok** string){
	int i = 0;
	printf("{");
	while(strcmp(string[i]->integer, "\0"))
		printf("\"%s\", ",string[i++]->integer);
	printf("}\n");
}
