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

	opertok** operationtokList = malloc(sizeof(opertok*) * 50);//= (opertok**)malloc(sizeof(opertok*) * 1024);
	int listi = 0;
	int j = 0;
	while(iterate[j] !=  '\0'){
		char* oper = (char*)malloc(sizeof(char) * 2);
		oper[0] = iterate[j++];
		oper[1] = '\0';
		operationtokList[listi] = malloc(sizeof(opertok));
		printf("SUP \n");
		operationtokList[listi++]->operid = oper;
	}
	operationtokList[listi] = malloc(sizeof(opertok));
	operationtokList[listi]->operid = "\0";
	printf("what about here\n");
	int loop = 0;
	printf("TRY THIS %s\n", operationtokList[0]->operid);
	while(strcmp(operationtokList[loop]->operid, "\0")){
		printf("loop working      ;\n");
		printf("%s\n", operationtokList[loop++]->operid);
	} 
	printf("WE MADE IT\n");
	return 0;
}
