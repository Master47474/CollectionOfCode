#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//file imports
#include "../InputTypes/inputNumber.c"



int main(){
	char* iterate = "12345\0";
	int i = 0;
	while(iterate[i] != '\0'){
		char* oper = malloc(sizeof(char) * 2);
		oper[0] = iterate[i++];
		oper[1] = '\0';
		opertok operationtok = createOperationToken(oper);
		printf("%s\n", operationtok.operid);
		free(oper);
	}

	opertok** operationtokList = malloc(sizeof(opertok*) * 1024);
	int listi = 0;
	int j = 0;
	while(iterate[j] !=  '\0'){
		char* oper = malloc(sizeof(char) * 2);
		oper[0] = iterate[j++];
		oper[1] = '\0';
		opertok operationtok = createOperationToken(&oper);
		operationtokList[listi] = malloc(sizeof(operationtok));
		operationtokList[listi++] = &operationtok;
		printf("what is this %s\n", operationtokList[listi-1]->operid);
	}

	printf("what about here\n");
	int loop = 0;
	printf("TRY THIS %s\n", operationtokList[0]->operid);
	while(strcmp(operationtokList[loop]->operid, "\0")){
		printf("loop working      ;");
		printf("%s\n", operationtokList[loop++]->operid);
	} 
	return 0;
}
