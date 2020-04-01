#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//file imports
#include "../InputTypes/inputNumber.c"



int main(){
	opertok* operationtok = createOperationToken("Test\0");
	printf("%s\n", operationtok->operid);
	return 0;
}
