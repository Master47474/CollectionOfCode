#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputParsing.h"
#include "Math/Solving.h"


#define INPUTBUFSIZE 1048
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

	// testing printf("%d\n" , exponent(3,3));
	return EXIT_SUCCESS;
}

// redo capture input
// only works with Ints no floats as of yet
char** captureInput(void){
	int bufsize = INPUTBUFSIZE;
	int pos = 0;
	char** input = malloc(sizeof(char) * bufsize);
	int c;
	char* tempFloatString = malloc(sizeof(char) * bufsize);
	int tempFloatPos = 0;
	char* BracketChecking = malloc(sizeof(char) * bufsize);
	int BracketCheckingPos = 0;

	if(!input){
		printf("Allocation Error\n");
		exit(EXIT_FAILURE);
	}

	if(!BracketChecking){
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
				input[pos] = malloc(sizeof(char));
				input[pos] = '\0';
				return input;
			break;
			case INPUT_SPACE:
				continue;
			break;
			case INPUT_CHAR:
				continue;
				//fill this in
			break;
			case INPUT_DIGIT:
				tempFloatString[tempFloatPos++] = c;
				pos--; // as it is going to be put back up
				// fill this in
				// only supports integers for now
			break;
			case INPUT_OPERATION:
			{
				if(tempFloatPos != 0){
					input[pos] = malloc(sizeof(char) * (tempFloatPos+1));
					strcpy(input[pos++], tempFloatString);
					tempFloatPos = 0;
					free(tempFloatString);
					char* tempFloatString = malloc(sizeof(char) * bufsize);
				}
				input[pos] = malloc(sizeof(char) * 2);
				char temp[] = {c, '\0'};
				strcpy(input[pos], temp);	
			}
			break;
			case INPUT_BRACKET:
			{
				input[pos] = malloc(sizeof(char) * 2);
				char temp[] = {c, '\0'};
				strcpy(input[pos], temp);
				
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

	free(tempFloatString);
	free(BracketChecking);
	return input;
}


void printDebug(char** string){
	int i = 0;
	int j = 0;
	printf("{");
	while(string[i][j] != '\0'){//j always 0 here
		printf("\"");
		while(string[i][j] != '\0')
			printf("%c", string[i][j++]);
		i++;
	}
		printf("\", ");
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




