#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InputCapture/inputParsing.h"

void printDebug(char** string);	
	


// main
int main(void){

	printDebug(captureInput());		

	
	return EXIT_SUCCESS;
}


void printDebug(char** string){
	int i = 0;
	printf("{");
	while(strcmp(string[i], "\0"))
		printf("\"%s\", ",string[i++]);
	printf("}\n");
}

					
