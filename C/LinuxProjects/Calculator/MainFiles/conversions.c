//for converting data types
#include <math.h>





int strToint(char* string){
	//for each char turn into int
	int digits = 0;
	for(digits = 0; string[digits] != '\0'; digits++)
		;
	digits--;
	int isNegative = 0;
	int padding = 0;
	if(string[0] == '-'){
		isNegative = 1;
		padding = 1;
	}

	int converted = 0;
	for(int i = isNegative; string[i] != '\0'; i++){
		converted += (string[i]-48) * (int)pow(10,(digits--)-padding);
		printf("-> %d", converted);
	}
	printf("\n");
	if(isNegative == 1)
		converted = converted * -1;
	printf("We Converted %s to %d\n", string, converted);
	return converted;
}


char* intTostr(int invalue, int base){
	//iterate by base^i to get each value
	//get digits for size of char
		
	int digits = 0;
	for(digits = 0; invalue/((int)pow(base,digits)) != 0; digits++)
		;
	
	int isNegative = 0;
	int padding = 0;
	if(invalue < 0){
		isNegative = 1;
		invalue = invalue * -1;
		digits++;
		padding = 1;
	}


	char* converted = (char*)malloc(sizeof(char) * (digits+1));
	int difference = 0;
	digits--;
	
	if(isNegative == 1){
		converted[0] = '-';
	}
	
	for(int i = isNegative; i <= digits; i++){
		int power = (int)pow(base,(digits-i-padding));
		converted[i] = (char)((invalue-difference)/power) + 48; //to make sure its the int
		difference += (int)(converted[i]-48)*power;
	}
	
	converted[digits+1] = '\0';
	printf("We Converted %s to %d\n", converted, invalue);
	return converted;
}
