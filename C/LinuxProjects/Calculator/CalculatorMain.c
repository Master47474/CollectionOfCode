#include <stdio.h>
#include <stdlib.h>

#include "inputParsing.h"

#define INPUTBUFSIZE 1048
#define TRUE 1
#define FALSE 0




char* captureInput(void);
void printDebug(char* string);

// operation functions and enums
typedef enum OperationsPrec{
	OPERERROR = -1,
	EXPONENTIAL = 0,
       	MULTIPLICATION = 1,
       	DIVISION = 1,
       	ADDITION = 2,
	SUBTRACTION = 2 
} OperationsPrec;

const static struct{
	OperationsPrec oper;
	int symbol;
} conversion[] = {
	{EXPONENTIAL, '^'},
	{MULTIPLICATION, '*'},
	{DIVISION, '/'},
	{ADDITION   , '+'},
	{SUBTRACTION, '-'},
};

//identify function declarations
OperationsPrec operation2Enum(const int symbol);
int isOperation(const int symbol);

int GetInputIdentifier(char c);
int isLetter(const int letter);
int isBracket(const int bracket);
int isDigit(const int digit);



// main

int main(void){

	char* input;
	
	input = captureInput();		

	printDebug(input);

	
	return EXIT_SUCCESS;
}

// redo capture input
// only works with Ints no floats as of yet
char* captureInput(void){
	int bufsize = INPUTBUFSIZE;
	int pos = 0;
	char* input = malloc(sizeof(char) * bufsize);
	int c;
	char* tempFloatString;

	if(!input){
		printf("Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		c = getchar();
		switch(GetInputIdentifier(c)){
			case INPUT_ERROR:
				printf("Error Parsing char \"%c\"", c);
			break;
			case INPUT_END:
				input[pos++] = '\0';
				return input;
				break;
			break;
			case INPUT_SPACE:
				continue;
			break;
			case INPUT_CHAR:
				continue;
				//fill this in
			break;
			case INPUT_DIGIT:
				input[pos] = c;
				// fill this in
			break;
			case INPUT_OPERATION:
				input[pos] = c;	
			break;
			case INPUT_BRACKET:
				input[pos] = c;
				//need to fill this in
			break;
			default:
				continue;
		}	
		
		/*
		if(isOperation(c) ){//|| aParenthisis(input[pos])){
				input[pos] = c;
				printf("%c ,", c);// do something 	
			}//else if(isDigit(input[pos]) || c == '.'){
				//append to placeholder string for for temp
		*/
		
		if(pos >= bufsize){
			bufsize += INPUTBUFSIZE;
			input = realloc(input, bufsize);
			if(!input) {
				printf("Allocation Error\n");
				exit(EXIT_FAILURE);
			}
		}
		pos++;
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



OperationsPrec operation2Enum(const int symbol){
	int j;
	for(j = 0; j< sizeof(conversion)/sizeof(conversion[0]); ++j)
		if( symbol == conversion[j].symbol)
			return conversion[j].oper;
	return OPERERROR;
}


int isOperation(const int symbol){
	if(operation2Enum(symbol) >= 0)
		return TRUE;
	return FALSE;
}

int isLetter(const int letter){
	if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return TRUE;
	return FALSE;
}

int isDigit(const int digit){
	if(digit >= '0' && digit <= '9')
		return TRUE;
	return FALSE;
}

int isBracket(const int bracket){
	for(int i = 0; i < sizeof(BRACKETS)/sizeof(char); ++i)
		if(bracket == BRACKETS[i])
			return TRUE;
	return FALSE;
}


int GetInputIdentifier(char c){
	if(c == ' ') return INPUT_SPACE;
	if(isLetter(c)) return INPUT_CHAR;
	if(c == EOF || c == '\n') return INPUT_END;
	if(isOperation(c)) return INPUT_OPERATION;
	if(isDigit(c)) return INPUT_DIGIT;
	if(isBracket(c)) return INPUT_BRACKET;

	return INPUT_ERROR;
}






