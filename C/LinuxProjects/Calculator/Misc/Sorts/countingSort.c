//counting sort

//imports
#ifndef FILE_DEFINITIONS
#define FILE_DEFINITIONS
#include "../../MainFiles/definitions.c"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>







char* CountingSortNC(char* alphanumeric){
	//couttning sort
	//With No count in output
	//input is with \0

	int length = strlen(alphanumeric);
	char* returnAlpha = (char*)malloc(sizeof(alphanumeric));

	int countingList[26] = {0};
	int positionList[26] = {0};	
	
	for(int i = 0; i < length; i++){
		countingList[alphanumeric[i]-97]++;
	}

	for(int i = 1; i < 26; i++){
		positionList[i] = positionList[i-1] + countingList[i-1];
	}

	for(int i = 0; i < length; i++){
		returnAlpha[positionList[alphanumeric[i]-97]] = alphanumeric[i];
		positionList[alphanumeric[i]-97]++;
	}		
	returnAlpha[length] = '\0';
	return returnAlpha;
}

char* CountingSortC(char* alphanumeric){
	//counting sort
	//with Count in the output
	//with \0
	int length = strlen(alphanumeric);
	
	int countingList[26] = {0};	
	
	for(int i = 0; i < length; i++){
		countingList[alphanumeric[i]-97]++;
	}

	int retLength = 0;
	for(int i = 0; i < 26; i++){
		if(countingList[i] != 0)
			retLength++;
	}

	char* returnAlpha = (char*)malloc( (sizeof(char)*retLength * 2) + sizeof(char));
	for(int i = 0; i < 26; i++){
		if(countingList[i] != 0){
			printf(" -----> %d \n", countingList[i]);
			returnAlpha[2*i] = countingList[i]+48;
			returnAlpha[2*i + 1] = (char)(i+97);
		}
	}
	returnAlpha[retLength*2 + 1] = '\0';
	
	
	return returnAlpha;
}



/*

int main(){
	
	char* sorted1 = "bca";
	char* sorted = CountingSortNC(sorted1);
	printf("Sup\n");
	printf("TEST -> ");
	for(int i = 0; i < ( (sizeof(sorted)/sizeof(char) ) - 1); i++)
		printf("%c", sorted[i]);
	printf("\n");
		
	return 0;

}
*/


