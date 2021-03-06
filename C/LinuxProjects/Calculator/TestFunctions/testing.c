#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//file imports
#include "../MainFiles/defintions.c"
#include "../InputCapture/InputCapture.h"
#include "../MainFiles/MathChars.h"

void debug(term* expression, int pos){
	printf("Pos %d :: ", pos);
	for(int i = 0; i < pos; i++){
		term curTerm = expression[i];
		printf(" ");
		if(curTerm.boolisOperation == 1 || curTerm.boolhascoeff == 1){
			printf("%s", curTerm.coefficient);
		}
		if(curTerm.boolhasalpha == 1){
			printf("%s",curTerm.alphanumeric);
		}
	}
	printf("\n");
}

int main(){
	printf("Sup \n");
	char* iterate = "1a+2b + c\n";
	int i = 0;
	term* expression = malloc(sizeof(term) * 1024);//allocate 1024 of space
	int pos = 0;
	char* temp = malloc(sizeof(char)*128);
	int temppos = 0;
	char* alpha = malloc(sizeof(char)*128);
	int tempchar = 0;
	printf("I Wanna Loop \n");
	
	
	int loop = 1;
	while(loop){
		int c = iterate[i++];
		printf("Current State: \n");
		debug(expression, pos); 
		printf("We Doing %c \n", c);
		//proof of concett
		switch(GetInputIdentifier(c)){
			case INPUT_ERROR:
				printf("Error Tokenising char \"%c\"", c);
			break;
			case INPUT_END:
			{
				printf("We in the END GAME NOW\n");
				temp[temppos] = '\0';
				alpha[tempchar] = '\0';
				term toAdd;
				toAdd.boolisOperation = 0;
				if (temppos == 0){
					toAdd.boolhascoeff = 0;
				}else{
					toAdd.coefficient = (char*)malloc(sizeof(char)+1);
					strcpy(toAdd.coefficient, temp);
					toAdd.boolhascoeff = 1;
				}

				if(tempchar == 0){
					toAdd.boolhasalpha = 0;
				}else{
					toAdd.alphanumeric = (char*)malloc(sizeof(temp)+1);
					strcpy(toAdd.alphanumeric, alpha);
					toAdd.boolhasalpha = 1;
				}
				printf("at POS %d\n", pos);
				expression[pos] = toAdd;
				debug(expression, pos);
				temppos = 0;
				tempchar = 0;
				
				loop = 0;	
			}
			break;
			case INPUT_SPACE:
				continue;
			break;
			case INPUT_CHAR:
			{
				alpha[tempchar++] = c;
				pos--;
			}
			break;
			case INPUT_DIGIT:
				temp[temppos++] = c;
				pos--;
			break;
			case INPUT_OPERATION:
			{
				printf("WE in OPERATIONS\n");
				temp[temppos] = '\0';
				alpha[tempchar] = '\0';
				term toAdd;
				toAdd.boolisOperation = 0;
				printf("We Just Created a Term\n");
				if (temppos == 0){
					toAdd.boolhascoeff = 0;
				}else{
					toAdd.coefficient = (char*)malloc(sizeof(temp)+1);
					strcpy(toAdd.coefficient,temp);
					toAdd.boolhascoeff = 1;
				}
				printf("WE in the Middle \n");
				if(tempchar == 0){
					toAdd.boolhasalpha = 0;
				}else{
					toAdd.alphanumeric = (char*)malloc(sizeof(alpha) + 1);
					strcpy(toAdd.alphanumeric, alpha);
					toAdd.boolhasalpha = 1;
				}
				printf("Just Inisialied all Varibales\n");
				expression[pos++] = toAdd;
				temppos = 0;
				tempchar = 0;

				//deal with operation
				term operation;
				operation.boolhascoeff = 0;
				operation.boolhasalpha = 0;
				operation.boolisOperation = 1;
				operation.coefficient = (char*)malloc(sizeof(c)+1);
				operation.coefficient[0] = c;
				operation.coefficient[1] = '\0';
				printf("%s \n", operation.coefficient);
				expression[pos] = operation;
			}
			break;
			default:
				continue;
		
		} 
		pos++;	
	}
	debug(expression, pos);
	printf("WE MADE IT WITH %d terms\n", pos);
	return 0;
}


