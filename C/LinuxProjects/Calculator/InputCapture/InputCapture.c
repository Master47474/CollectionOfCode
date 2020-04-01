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
<<<<<<< HEAD
#include "../InputTypes/inputNumber.h"
=======

>>>>>>> parent of a826f78... about to start making the structs to the capture

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


numtok** captureInput(void);

//identify function declarations
OperationsPrec operation2Enum(const int symbol);
int isOperation(const int symbol);

//input identifiers
int GetInputIdentifier(char c);
int isLetter(const int letter);
int isBracket(const int bracket);
int isDigit(const int digit);
int isActualEndBracket(const int openBracket, const int closeBracket);
int isEndBracket(const int bracket);
int isOpenBracket(const int bracket);


//appending to number
void appendNumber(numtok** string, int* posi, char* temp, int* tempi, numtok* currentToken);


// redo capture input
// only works with Ints no floats as of yet
numtok** captureInput(void){
	int bufsize = INPUTBUFSIZE;
	int pos = 0;
	//char** input = (char**)malloc(sizeof(char*) * bufsize);
	numtok** input = malloc(sizeof(numtok*) * bufsize);// [numtok, numtok, numtok, '\0']
	int c;
	char* tempString = malloc(sizeof(char) * bufsize);
	int tempPos = 0;
	char* BracketChecking = malloc(sizeof(char) * bufsize);
	int BracketCheckingPos = 0;
	int decimalNumber = FALSE;
<<<<<<< HEAD
	char* alphaLetter = malloc(sizeof(char) * bufsize);
	int alphanumeric = FALSE;

	numtok* currentToken;
       	currentToken = malloc(sizeof(numtok));
	currentToken =	&numtok_default;
	
	
	

=======
>>>>>>> parent of a826f78... about to start making the structs to the capture

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
					if(decimalNumber == TRUE){
						currentToken->boolfloat = TRUE;//tempString[tempPos++] = 'f';
						decimalNumber = FALSE;
					}	
					appendNumber(input, &pos, tempString, &tempPos, currentToken);
				}
				numtok* currentToken = malloc(sizeof(numtok));
				currentToken = &numtok_default;//tempString[0] = '\0';
				input[pos] = malloc(sizeof(numtok*));
				input[pos] = currentToken;
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
						currentToken->boolfloat = TRUE;//tempString[tempPos++] = 'f';
						decimalNumber = FALSE;
					}	
					appendNumber(input, &pos, tempString, &tempPos, currentToken);
				}
				numtok* currentToken = malloc(sizeof(numtok));
				currentToken = &numtok_default;
				currentToken->booloper = TRUE;
				opertok operationtok;
				operationtok.operid[0] = c;
				operationtok.operid[1] = '\0';
				currentToken->operation = operationtok;
				//tempString[0] = c;
				//tempString[1] = '\0';
				//(char*)malloc(sizeof(char) * 4);
				input[pos] = malloc(sizeof(numtok*));
				input[pos] = currentToken;//strcpy(input[pos], tempString);
			}
			break;
			case INPUT_BRACKET:
			{
				if(tempPos != 0){
					if(decimalNumber == TRUE){
						currentToken->boolfloat = TRUE;//tempString[tempPos++] = 'f';
						decimalNumber = FALSE;
					}	
					appendNumber(input, &pos, tempString, &tempPos, currentToken);
				}
				numtok* currentToken = malloc(sizeof(numtok));
				currentToken = &numtok_default;
				currentToken->booloper = TRUE;
				opertok operationtok;
				operationtok.operid = malloc(sizeof(char) * 4);
				operationtok.operid[0] = c; 
				operationtok.operid[1] = '\0';
				currentToken->operation = operationtok;
				//tempString[0] = c;
				 //tempString[1] = '\0';
				//(char*)malloc(sizeof(char) * 4);
				input[pos] = malloc(sizeof(numtok*));
				input[pos] = currentToken;//strcpy(input[pos], tempString);


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



void appendNumber(numtok** string, int* posi, char* temp, int* tempi, numtok* currentToken){
	temp[(*tempi)++] = '\0';
	currentToken->integer = malloc(sizeof(char) * (*tempi));
	strcpy(currentToken->integer, temp);
	string[(*posi)] = malloc(sizeof(numtok*));
	string[(*posi)++] = currentToken;
	*tempi = 0;
}
