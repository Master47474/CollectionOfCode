//this will bne the file where a parsetree is written and implemented
#include <stdio.h>
#include <stdlib.h>


//file imports
#ifndef FILE_DEFINITIONS
#define FILE_FEDINITIONS
#include "../MainFiles/definitions.c"
#endif

typedef struct node{
	struct node* parent;
	struct node* left;
	struct node* right;
	term* value; //list of terms
	int length;
}node;


//setting
void insertLeft(struct node* head);
void insertRight(struct node* head);
void setValue(struct node* current, term value);
//getting
struct node* getLeft(struct node* current);
struct node* getRight(struct node* current);
term* getValue(struct node* current);

//printing
void printInOrder(struct node* tree){
	if(tree != NULL){
		printInOrder(getLeft(tree));
		if(tree->value != NULL) {
			if(valueincoeff(tree->value[0]))
				printf(" %s", tree->value->coefficient);
			if(valueinalpha(tree->value[0]))
				printf("%s", tree->value->alphanumeric);	
		printInOrder(getRight(tree));	
		}
	}
}


struct node* buildParseTree(term* tokenExp){
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* current = head;
	int expi = 0;

	while(1){ // loop forever
		term curTerm = tokenExp[expi];
		if(curTerm.isTermination == 1)
			break;
		
		//printf(doing c)
		printf("Doing ");
		if(valueincoeff(curTerm))
			printf("%s", curTerm.coefficient);
		if(valueinalpha(curTerm))
			printf("%s", curTerm.alphanumeric);	
		printf("\n");
		
		if(curTerm.boolBracket == 1){ //if it is a bracket
			printf("A Bracket\n");
			char bracket = curTerm.coefficient[0];
			if(isOpenBracket(bracket)){
				insertLeft(current);
				current = current->left;
				//printf("---- INSERT LEFT NODE AND GO LEFT\n");
			}else if(isEndBracket(bracket)){
				//printf("----------GO UP TO PARENT\n");
				current = current->parent;
			}
		}else if(curTerm.boolisOperation == 1){
		       printf("An Operation \n");	
			if(current->value != NULL){
				if(hasPrecedence(curTerm.coefficient[0], current->value->coefficient[0])){
					printf("----> has Precedence \n");
					current = current->right;
					term* temp = current->value;
					insertLeft(current);
					current = current->left;
					setValue(current, temp[0]);
					current = current->parent;
				}
				if(current->right != NULL){
					//therefor both childs are used i.e make new node the head and make this the left node
					struct node* newhead = (struct node*)malloc(sizeof(struct node));
					newhead->left = head;
					head-> parent = newhead;
					head = head-> parent;
					current = current->parent;
				}
			}
			//printf("---- This is a operation, ");
			setValue(current, curTerm);
			//printf("---- set the value ,");
			insertRight(current);
			//printf("---- insert a right node, and go to right node\n");
			current = current->right;
		}else if(curTerm.boolhascoeff == 1 || curTerm.boolhasalpha == 1){
			printf("A Digit or a Number Or Both \n");
			//printf("---- THIS IS A DIGIT, or char or a mix of both \n");
			setValue(current, curTerm);
			//printf("-After setting a value, and go UP!!!!!!!!!!!!\n");
			current = current->parent;
		}		
		expi++;
	}
	return head;
}



void insertLeft(struct node* head){
	struct node* new;
       	new = (struct node*)malloc(sizeof(struct node));
	new->parent = head;

	head->left = (struct node*)malloc(sizeof(struct node));
	head->left = new;
}

void insertRight(struct node* head){
	struct node* new;
       	new = (struct node*)malloc(sizeof(struct node));
	new->parent = head;

	head->right = (struct node*)malloc(sizeof(struct node));
	head->right = new;
}

//only set using one term value
void setValue(struct node* current, term value){ 
	current->value = (term*)malloc(sizeof(value));
	current->value[0] = value;
	current->length = 1;
}

struct node* getLeft(struct node* current){
	//printf("Getting LEft\n");
	return current->left;
}


struct node* getRight(struct node* current){
	//printf("getting right\n");
	return current->right;
}

term* getValue(struct node* current){
	return current->value;
}



