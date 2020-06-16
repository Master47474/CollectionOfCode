//for converting data types
#include <math.h>





int strToint(char* string){
	//for each char turn into int
	int converted = 0;
	for(int i = 0; string[i] != '\0'; i++){
		converted += (string[i]-48) * pow(10,i);
	}
	return converted;
}


char* intTostr(int invalue, int base){
	//iterate by base^i to get each value
	//get digits for size of char
	int digits = 0;
	for(digits = 0; invalue/(pow(base,digits)) != 0; digits++)
		;

	char* converted = (char*)malloc(sizeof(char) * (digits+1));
	int difference = 0;
	for(int i = 0; i < digits; i++){
		int power = pow(base,(digits-1)-i);
		converted[i] = ((invalue-difference)/power) -48; //to make sure its the int
		difference += (converted[i]+48) * base;
	}
	converted[digits] = '\0';
	return converted;
}
