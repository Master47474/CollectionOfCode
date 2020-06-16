//Evaluating the tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//imports
#ifndef FILE_DEFINITIONS
#define FILE_DEFINITIONS
#include "../MainFiles/definitions.c"
#endif

#ifndef CONVERSIONS
#define CONVERSIONS
#include "../MainFiles/conversions.c"
#endif

term createTerm2(char* coefficient, char* alphanumeric, int coeffPos, int alphanumPos, int boolOperation, int boolBracket, int Termination);


term* EvalueateTree(struct node* current){
	term* x, y;
	int lx, ly;
	
	// left is x
	// check if left is an operation
	if(current->left->value->boolisOperation == 1){
		printf("going Left Because Operation\n");
		x = EvalueateTree(current->left);
		lx = x->length;
	} else{
		x = current->left->value;
		lx = current->left->length;
	}

	//right is y
	//check if right is an operation
	if(current->right->value->boolisOperation == 1){
		printf("going right Because Operation\n");
		y = EvalueateTree(current->right);
		ly = y->length;
	}else{
		y = current->right->value;
		ly = current->right->length;
	}
	//printf("this is X, %f \n", x);
	//printf("this is Y, %f \n", y);
	//printf("GOING UP\n");
	// return x (operation) right
	if(!strcmp(current->value, "+"))
		return addTerms(x, y, lx, ly);
	//if(!strcmp(current->value, "-"))
		//return subtractTerms(x, y);
	//if(!strcmp(current->value, "*"))
		//return multiplyTerms(x, y);
	//if(!strcmp(current->value, "/"))
		//return divideTerms(x, y);
}

int*[2] matchingTerms(term* x, term* y, int lx, int ly){
	//returns the first pair of matching terms
	//for addition and subtraction
	int* pair[2] = malloc(sizeof(int[2]) * lx*ly);
	int index = 0;

	for(int i = 0; i < lx; i++){
		int xalp = valueinalpha(x[i]);
		//check if operation/breacket/operation
		if(x[i]->boolisOperation || x[i]->boolBracket || x[i]->isTermination)
			continue;
		for(int j = 0; j < ly; j++){
			int yalp = valueinalpha(y[j]);
			//check if operation/bracket/termination
			if(y[i]->boolisOperation || y[i]->boolBracket || y[i]->isTermination)
				continue;

			//if both pairs are same alphanumeric return
			if(xalp && yalp){
				//hence now we can check if they are the same
				if(!srtcmp(x[i]->alphanumeric, y[j]->alphanumeric)){
					pair[index++] = {i , j};
				}
			}else if(!xalp && !yalp){
				pair[index++] = {i, j};
			}
			//hence no match go next
		}
	}
	pair[index++] = {-1, -1};

	return pair;	
}

term* addTerms(term* x, term* y, int lx, int ly){
	//add terms
	
	//first check if terms have same alphenumeric
	int* pairs[2] = matchingTerms(x, y, lx, ly);
	int counter = 0;
	int* counted[ly + 1] = {-1};
	while(pairs[counter][0] != -1){
		// add 0 and 1 to each other
		int i = pairs[counter][0];
		int j = pairs[counter][1];
		//both to int from strings
		int xi = strToint(x[i]->coefficient);
		int yj = strToint(y[j]->coefficient);
		int total = xi + yj;
		char* strTotal = intTostr(total, 10);

		//now reallocate memory for x[i]->coefficient
		x[i]->coefficient = (char*)realloc(x[i]->coefficient, sizeof(strTotal));
		strcpy(x[i]->coefficient, strTotal);
		if(j > 0)
			counted[j-1] = 1; //the operation before the term is to be included and not appended
		counted[j] = 1;
	}
	counted[ly] = 0; //to mark the end of counted

	//for indicies of y that were not a match we have to append to the end of 
	int terms = 0;
	for(int i = 0; counted[terms] != 0; i++)
	       terms++;

	term* toappend = (term*)malloc(sizeof(term) * term); 	
	int tcount = 0;
	for(int i = 0; counted[i] != 0; i++){
		if(counted[i] == 0){//addition is communitive
			toappend[tcount++] = y[i];
		}
	}
	
	//realloc memory for x terms
	x = realloc(sizeof(term) * (lx + (2*terms))); //+ term for each term
	//move null term to end
	x[lx + 2*terms] = x[lx];
	char* add = '+';
	char* temp = ' ';
	term operation = createTerm2(add, temp, 1, 0, 1, 0, 0);
	tcount = 0;
	for(int i = lx; i < lx+2*terms; i+= 2){ //as every 2 we want to append a new term
				x[i] = operation;
				x[i+1] = toappend[tcount++];
	}
	x->length = lx + 2*terms;
	return x;	
}



term createTerm2(char* coefficient, char* alphanumeric, int coeffPos, int alphanumPos, int boolOperation, int boolBracket, int Termination){
	//add null chars to coeff and alpha first
	
	coefficient[coeffPos] = '\0';
	alphanumeric[alphanumPos] = '\0';
	
	//sort alphanumeric with No count
	if(alphanumPos > 0){
		printf("Sup %d\n", alphanumPos);
		char* sorted = CountingSortNC(alphanumeric);
		strcpy(alphanumeric, sorted);
		//printf("--- %s here \n" , CountingSortC(alphanumeric));
		//printf("Create Term with Alpha ->  %s -> %s \n", alphanumericIn, alphanumeric);	
	}


	term toAdd;
	toAdd.boolisOperation = boolOperation;
	toAdd.isTermination = Termination;
	toAdd.boolBracket = boolBracket;
	if(coeffPos == 0){
		toAdd.boolhascoeff = 0; // no coefficient
	}else{
		toAdd.coefficient = (char*)malloc(sizeof(coefficient)+sizeof(char));
		strcpy(toAdd.coefficient, coefficient);
		toAdd.boolhascoeff = 1;
	}

	if(alphanumPos == 0){
		toAdd.boolhasalpha = 0;
	}else{
		toAdd.alphanumeric = (char*)malloc(sizeof(alphanumeric) + sizeof(char));
		strcpy(toAdd.alphanumeric, alphanumeric);
		toAdd.boolhasalpha = 1;
	}

	return toAdd;
}






