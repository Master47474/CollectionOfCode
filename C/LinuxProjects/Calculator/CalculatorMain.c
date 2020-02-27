#include <stdio.h>
#include <stdlib.h>

#define INPUTBUFSIZE 1048
#define TRUE 1
#define FALSE 0


#define DIGITS "0123456789"


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

OperationsPrec operation2Enum(const int symbol);
int isOperation(const int symbol);

//misc function declarations
int isLetter(const int letter);





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
		
		if(c == ' ') continue;
		if(isLetter(c)) continue;
		if(c == EOF || c == '\n'){
			input[pos++] = '\0';
			return input;
		}else{
			if(isOperation(c) ){//|| aParenthisis(input[pos])){
				input[pos] = c;
				printf("%c ,", c);// do something 	
			}//else if(isDigit(input[pos]) || c == '.'){
				//append to placeholder string for floats
			//}
			
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








