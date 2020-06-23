//for converting data types
#include <math.h>





int strToint(char* string){
	//for each char turn into int
	int digits = 0;
	for(digits = 0; string[digits] != '\0'; digits++)
		;
	digits--;

	int converted = 0;
	for(int i = 0; string[i] != '\0'; i++){
		converted += (string[i]-48) * (int)pow(10,digits--);
		printf("-> %d", converted);
	}
	return converted;
}


char* intTostr(int invalue, int base){
	//iterate by base^i to get each value
	//get digits for size of char
	int digits = 0;
	for(digits = 0; invalue/((int)pow(base,digits)) != 0; digits++)
		;

	char* converted = (char*)malloc(sizeof(char) * (digits+1));
	int difference = 0;
	digits--;
	for(int i = 0; i <= digits; i++){
		int power = (int)pow(base,(digits-i));
		converted[i] = (char)((invalue-difference)/power) + 48; //to make sure its the int
		difference += (int)(converted[i]-48)*power;
	}
	converted[digits+1] = '\0';
	return converted;
}
