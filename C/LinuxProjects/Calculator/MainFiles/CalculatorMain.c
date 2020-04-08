#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//file Imports
#include "../InputCapture/InputCapture.h"


void printDebug(char** string);

// main

int main(void){
	printf("LEts start\n");
	printDebug(captureInput());


	return EXIT_SUCCESS;
}


void printDebug(char** string){
	int i = 0;
	printf("{");
	while(string[i] != '\0'))
		printf("\"%s\", ",string[i++]);
	printf("}\n");
}
