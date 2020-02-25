#include <stdio.h>
#include <stdlib.h>

#define INPUTBUFSIZE 1048


char* captureInput(void);
void printDebug(char* string);


int main(void){

	char* input;
	
	input = captureInput();	
	
	printDebug(input);

	
	return EXIT_SUCCESS;
}

// redo capture input
char* captureInput(void){
	int bufsize = INPUTBUFSIZE;
	int pos = 0;
	char* input = malloc(sizeof(char) * bufsize);
	int c;

	if(!input){
		printf("Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		c = getchar();
		
		if(c == ' ') continue;
		if(c == EOF || c == '\n'){
			input[pos++] = '\0';
			return input;
		}else{
			if(anOperation(input[pos++]))
			       //do something that would be like adding it to input
			//else if it is a digit add it do a string
			//
			input[pos++] = c;
		}

		if(pos >= bufsize){
			bufsize += INPUTBUFSIZE;
			input = realloc(input, bufsize);
			if(!input) {
				printf("Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return input;
}


void printDebug(char* string){
	int i = 0;
	printf("{");
	while(string[i] != '\0')
		printf("\"%c\", ",string[i++]);
	printf("}\n");
}


















