#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definitions
#define INPUTBUFSIZE 1048
#define INPUTWORDBUFSIZE 256
#define TRUE 1
#define FALSE 0

//imports
#include "../MainFiles/MathChars.h"


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
	{MULTIPLICATION, '*'  },
	{DIVISION, '/'  },
	{ADDITION   , '+'  },
	{SUBTRACTION, '-'  },
};


char** captureInput(void);

//identify function declarations
OperationsPrec operation2Enum(int symbol);
int isOperation(int symbol);
int hasPrecedence(int oper1, int oper2);

//input identifiers
int GetInputIdentifier(char c);
int isLetter(const int letter);
int isBracket(const int bracket);
int isDigit(const int digit);
int isActualEndBracket(const int openBracket, const int closeBracket);
int isEndBracket(const int bracket);
int isOpenBracket(const int bracket);


//appending to number
void appendNumber(char** string, int* posi, char* temp, int* tempi);


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
	int decimalNumber = FALSE;
	


	if(!input || !tempString || !BracketChecking){
		printf("Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	
	//always encapsulate with brackets
	tempString[0] = '(';
	tempString[1] = '\0';
	input[pos] = (char*)malloc(sizeof(char) * 4);
	strcpy(input[pos], tempString);
	pos++;

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
					if(decimalNumber == TRUE){
						tempString[tempPos++] = 'f';
						decimalNumber = FALSE;
					}
					appendNumber(input, &pos, tempString, &tempPos);
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
				if(c == DECIMALPOINT) decimalNumber = TRUE;
				tempString[tempPos++] = c;
				pos--;
				// fill this in
			break;
			case INPUT_OPERATION:
			{
				if(tempPos != 0){
					if(decimalNumber == TRUE){
						tempString[tempPos++] = 'f';
						decimalNumber = FALSE;
					}
					appendNumber(input, &pos, tempString, &tempPos);
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
					if(decimalNumber == TRUE){
						tempString[tempPos++] = 'f';
						decimalNumber = FALSE;
					}
					appendNumber(input, &pos, tempString, &tempPos);
				}
				tempString[0] = c;
				tempString[1] = '\0';
				input[pos] = (char*)malloc(sizeof(char) * 4);
				strcpy(input[pos], tempString);

				//assume BracketChecking never reaches its max allocation size
				//check that bracket that was added is valid
				//check if opening bracket first
				//allow un closed open brackets
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






OperationsPrec operation2Enum(int symbol){
	int j;
	for(j = 0; j< sizeof(conversion)/sizeof(conversion[0]); ++j)
		if(symbol == conversion[j].symbol)
			return conversion[j].oper;
	return OPERERROR;
}


int isOperation(int symbol){
	if(operation2Enum(symbol) >= 0)
		return TRUE;
	return FALSE;
}

int hasPrecedence(int oper1, int oper2){
	if(operation2Enum(oper1) > operation2Enum(oper2))
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
	if(isDigit(c) || c == DECIMALPOINT) return INPUT_DIGIT;
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



void appendNumber(char** string, int* posi, char* temp, int* tempi){
	temp[(*tempi)++] = '\0';
	string[*posi] = (char*)malloc(sizeof(char) * (*tempi));
	strcpy(string[(*posi)++], temp);
	*tempi = 0;
}









