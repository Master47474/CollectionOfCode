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

node* addTerms(node* xx, node* yy, int lx, int ly);
term createTerm2(char* coefficient, char* alphanumeric, int coeffPos, int alphanumPos, int boolOperation, int boolBracket, int Termination);


node* EvalueateTree(struct node* current){
	node* x;
       	node* y;
	int lx, ly;
	
	// left is x
	// check if left is an operation
	if(current->left->value->boolisOperation == 1){
		printf("going Left Because Operation\n");
		x = EvalueateTree(current->left);
		lx = x->length;
	} else{
		x = current->left;
		lx = current->left->length;
	}

	//right is y
	//check if right is an operation
	if(current->right->value->boolisOperation == 1){
		printf("going right Because Operation\n");
		y = EvalueateTree(current->right);
		ly = y->length;
	}else{
		y = current->right;
		ly = current->right->length;
	}
	//printf("this is X, %f \n", x);
	//printf("this is Y, %f \n", y);
	//printf("GOING UP\n");
	// return x (operation) right
	char* val = current->value[0].coefficient;
	printf("Lets Check Addition\n");
	if(!strcmp(val, "+")){
		printf("We Are Adding\n");
		return addTerms(x, y, lx, ly);
	}
	//if(!strcmp(current->value, "-")) //subtratcing is just adding negative lol
		//return subtractTerms(x, y);
	//if(!strcmp(current->value, "*"))
		//return multiplyTerms(x, y);
	//if(!strcmp(current->value, "/"))
		//return divideTerms(x, y);
}

int* matchingTerms(term* x, term* y, int lx, int ly){
	//returns the first pair of matching terms
	//for addition and subtraction
	
	int* pair = malloc((sizeof(int)*2)*lx*ly);
	//int* pair[lx*ly][2]; //a list of intergers where x,x+1 for each second x is related
	int index = 0;
	for(int i = 0; i < lx; i++){
		int xalp = valueinalpha(x[i]);
		//check if operation/breacket/operation
		if(x[i].boolisOperation || x[i].boolBracket || x[i].isTermination)
			continue;
		for(int j = 0; j < ly; j++){
			int yalp = valueinalpha(y[j]);
			//check if operation/bracket/termination
			if(y[i].boolisOperation || y[i].boolBracket || y[i].isTermination)
				continue;

			//if both pairs are same alphanumeric return
			if(xalp && yalp){
				//hence now we can check if they are the same
				if(!strcmp(x[i].alphanumeric, y[j].alphanumeric)){
					pair[index++] = i;
					pair[index++] = j;
				}
			}else if(!xalp && !yalp){
				pair[index++] = i;
				pair[index++] = j;

			}
			//hence no match go next
		}
	}
	pair[index++] = -1;
	pair[index++] = -1;

	return pair;	
}

node* addTerms(node* xx, node* yy, int lx, int ly){
	//add terms
	term* x = xx->value;
	term* y = yy->value;
	//first check if terms have same alphenumeric
	int* pairs = matchingTerms(x, y, lx, ly);
	printf("WE Matched Terms\n");
	int counter = 0;
	int* counted = malloc(sizeof(int) *(ly + 1));
	for(int i = 0; i < ly+1; i++)
		counted[i] = -1;
	while(pairs[counter] != -1){
		// add 0 and 1 to each other
		int i = pairs[counter];
		int j = pairs[counter+1];
		counter += 2;
		//both to int from strings
		int xi = strToint(x[i].coefficient);
		int yj = strToint(y[j].coefficient);
		int total = xi + yj;
		char* strTotal = intTostr(total, 10);
		//now reallocate memory for x[i]->coefficient
		x[i].coefficient = (char*)realloc(x[i].coefficient, sizeof(strTotal));
		strcpy(x[i].coefficient, strTotal);
		if(j > 0)
			counted[j-1] = 1; //the operation before the term is to be included and not appended
		counted[j] = 1;
	}
	counted[ly] = 0; //to mark the end of counted

	//for indicies of y that were not a match we have to append to the end of 
	int terms = 0;
	for(int i = 0; counted[i] != 0; i++){
		if(counted[terms] == -1)
			terms++;
	}

	printf("We Have %d Y Terms To Be added\n", terms);
	term* toappend = (term*)malloc(sizeof(term) * terms); 	
	int tcount = 0;
	for(int i = 0; counted[i] != 0; i++){
		if(counted[i] == -1){//addition is communitive
			toappend[tcount++] = y[i];
			printf("Addpend\n");
		}
	}
	printf("Done Checking What needs to be added to the end\n");
	//realloc memory for x terms
	xx->value = realloc(xx->value, sizeof(term) * (lx + (2*terms))); //+ term for each term
	printf("Realloced the memory\n");
	//move null term to end
	x[lx + 2*terms] = x[lx];
	char* add = malloc(sizeof(char) * 2);
	add[0] = '+';
	char* temp = malloc(sizeof(char));

	term operation = createTerm2(add, temp, 1, 0, 1, 0, 0);
	printf("Created the Term\n");
	tcount = 0;
	printf("Now to append the Terms\n");
	for(int i = lx; i < lx+(2*terms); i+= 2){ //as every 2 we want to append a new term
				xx->value[i] = operation;
				xx->value[i+1] = toappend[tcount++];
				printf("We Appended This\n");
				printf("Append At %d and %d\n", i, i+1);
	}
	xx->length = lx + 2*terms;
	printf("We are finished\n");
	free(y);
	free(yy);
	return xx;	
}



term createTerm2(char* coefficient, char* alphanumeric, int coeffPos, int alphanumPos, int boolOperation, int boolBracket, int Termination){
	//add null chars to coeff and alpha first
	printf("UGH \n");	
	coefficient[coeffPos] = '\0';
	printf("BRUH\n");
	alphanumeric[alphanumPos] = '\0';
	printf("What Happened\n");
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






