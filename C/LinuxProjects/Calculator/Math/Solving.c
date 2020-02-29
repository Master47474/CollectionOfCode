#include <stdio.h>




int addition(int left, int right){
	return left + right;
}

int subtraction(int left, int right){
	return left - right;
}

int multiplication(int left, int right){
	return left * right;
}

int division(int numer, int denom){
	return numer/denom;
}

int exponent(int base, int pow){
	int total = 1;
	while(--pow >= 0)
		total *= base;
	return total;
}


//simple evaluation i.e no bracets
//use ints for now












//complex evaluation i.e brackets





