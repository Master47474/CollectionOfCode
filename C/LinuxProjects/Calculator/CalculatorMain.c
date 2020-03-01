#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputParsing.h"

#define INPUTBUFSIZE 1048
#define INPUTWORDBUFSIZE 256
#define TRUE 1
#define FALSE 0




char** captureInput(void);
void printDebug(char** string);

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
int isActualEndBracket(const int openBracket, const int closeBracket);
int isEndBracket(const int bracket);
int isOpenBracket(const int bracket);

	

	
	
// main

int main(void){

	printDebug(captureInput());		

	
	return EXIT_SUCCESS;
}

// redo capture input
// only works with Ints no floats as of yet
char** captureInput(void){
	int bufsize = INPUTBUFSIZE;
	int pos = 0;
	char** input = (char**)malloc(sizeof(char*) * bufsize);
	int c;
	char* tempString = malloc(sizeof(char) * bufsize);
	int tempPos = 0;
	char* BracketChecking = malloc(sizeof(char) * bufsize);
	int BracketCheckingPos = 0;

	if(!input || !tempString || !BracketChecking){
		printf("Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	while(1){
		c = getchar();
		// printf("Tokenizing \"%c\"\n", c);
		switch(GetInputIdentifier(c)){
			case INPUT_ERROR:
				printf("Error Tokenizing char \"%c\"", c);
			break;
			case INPUT_END:
			{
				if(tempPos != 0){
					tempString[tempPos++] = '\0';
					input[pos] = (char*)malloc(sizeof(char) * tempPos);
					strcpy(input[pos++], tempString);
					tempPos = 0;
				}
				tempString[0] = '\0';
				input[pos] = (char*)malloc(sizeof(char));
				strcpy(input[pos], tempString);	
				return input;
			}		
			break;
			case INPUT_SPACE:
				continue;
			break;
			case INPUT_CHAR:
				continue;
				//fill this in
			break;
			case INPUT_DIGIT:
				tempString[tempPos++] = c;
				pos--;
				// fill this in
			break;
			case INPUT_OPERATION:
			{
				if(tempPos != 0){
					tempString[tempPos++] = '\0';
					input[pos] = (char*)malloc(sizeof(char) * tempPos);
					strcpy(input[pos++], tempString);
					tempPos = 0;
				}
				tempString[0] = c;
				tempString[1] = '\0';
				input[pos] = (char*)malloc(sizeof(char) * 4);
				strcpy(input[pos], tempString);	
			}					
			break;
			case INPUT_BRACKET:
			{
				if(tempPos != 0){
					tempString[tempPos++] = '\0';
					input[pos] = (char*)malloc(sizeof(char) * tempPos);
					strcpy(input[pos++], tempString);
					tempPos = 0;
				}
				tempString[0] = c;
				tempString[1] = '\0';
				input[pos] = (char*)malloc(sizeof(char) * 4);
				strcpy(input[pos], tempString);	

				//assume BracketChecking never reaches its max allocation size
				//check that bracket that was added is valid
				//check if opening bracket first
				if(isOpenBracket(c)){
					BracketChecking[BracketCheckingPos++] = c;
					break;
				}
				if(BracketCheckingPos == 0 && isEndBracket(c)){
					printf("Syntax Error No Opening Corresponding Bracket\n");
					return input;
				}
				if(!(isActualEndBracket(BracketChecking[BracketCheckingPos-1] ,c))){
					printf("Doesnt Correspond ti opening Bracket Error\n");
					return input;	
				}else{ // then is is an actual end bracket
					BracketCheckingPos--;
				}
			}
			break;
			default:
				continue;
		}
		
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

	free(tempString);
	free(BracketChecking);
	return input;
}


void printDebug(char** string){
	int i = 0;
	printf("{");
	while(strcmp(string[i], "\0"))
		printf("\"%s\", ",string[i++]);
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

int isEndBracket(const int bracket){
	for(int i = 0; i < sizeof(ENDBRACKET)/sizeof(char); ++i)
		if(bracket == ENDBRACKET[i])
			return TRUE;
	return FALSE;
}

int isOpenBracket(const int bracket){
	for(int i = 0; i < sizeof(OPENBRACKET)/sizeof(char); ++i)
		if(bracket == OPENBRACKET[i])
			return TRUE;
	return FALSE;
}


int isActualEndBracket(const int openBracket, const int closeBracket){
	switch(closeBracket){
		case ')':
			if(openBracket == '(')
				return TRUE;
			return FALSE;
		break;
		case ']':
			if(openBracket == '[')
				return TRUE;
			return FALSE;
		break;
		case '}':
			if(openBracket == '{')
				return TRUE;
			return FALSE;
		break;
		default:
			return FALSE;
	}
}




