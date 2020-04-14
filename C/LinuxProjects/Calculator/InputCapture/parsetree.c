//this will bne the file where a parsetree is written and implemented
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node* parent;
	struct node* left;
	struct node* right;
	char* value;
};


//setting
void insertLeft(struct node* head);
void insertRight(struct node* head);
void setValue(struct node* current, char* value);
//getting
struct node* getLeft(struct node* current);
struct node* getRight(struct node* current);
char* getValue(struct node* current);

//printing
void printInOrder(struct node* tree){
	if(tree != NULL){
		printInOrder(getLeft(tree));
		if(tree->value != NULL) printf(" %s ", tree->value);	
		printInOrder(getRight(tree));	
	}
}



struct node* buildParseTree(char** tokenExp){
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* current = head;
	int expi = 0;
	

	while(strcmp(tokenExp[expi], "\0")){
		printf("WE EXEXUCITNG %s \n", tokenExp[expi]);
		if(isOpenBracket(tokenExp[expi][0])){
			insertLeft(current);
			current = current->left;
			//printf("---- INSERT LEFT NODE AND GO LEFT\n");
		}else if(isOperation(tokenExp[expi][0])){
			if(current->value != NULL){
				//if(operation2Enum((long unsigned int)tokenExp[expi]) == operation2Enum((long unsigned int)current->value)){}
				if(hasPrecedence(tokenExp[expi][0], current->value[0] )){
					current = current->right;
					char* temp = current->value;
					insertLeft(current);
					current = current->left;
					setValue(current, temp);
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
			setValue(current, tokenExp[expi]);
			//printf("---- set the value ,");
			insertRight(current);
			//printf("---- insert a right node, and go to right node\n");
			current = current->right;
		}else if(isDigit(tokenExp[expi][0]) || tokenExp[expi][0] == '.'){
			//printf("---- THIS IS A DIGIT, ");
			setValue(current, tokenExp[expi]);
			//printf("-After setting a value, and go UP!!!!!!!!!!!!\n");
			current = current->parent;
		}else if(isEndBracket(tokenExp[expi][0])){
			//printf("----------GO UP TO PARENT\n");
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

void setValue(struct node* current, char* value){ 
	current->value = malloc(sizeof(value));
	strcpy(current->value, value);
}

struct node* getLeft(struct node* current){
	//printf("Getting LEft\n");
	return current->left;
}


struct node* getRight(struct node* current){
	//printf("getting right\n");
	return current->right;
}

char* getValue(struct node* current){
	return current->value;
}


int EvalueateTree(struct node* current){
	int x, y;
	
	// left is x
	// check if left is an operation
	printf("Left -> %c \n", current->left->value[0]);
	if(isOperation(current->left->value[0])){
		printf("going Left\n");
		x = EvalueateTree(current->left);
	} else{
		x = atoi(current->left->value);
	}

	//right is y
	//check if right is an operation
	printf("Right -> %c \n", current->right->value[0]);
	if(isOperation(current->right->value[0])){
		printf("going right\n");
		y = EvalueateTree(current->right);
	}else{
		y = atoi(current->right->value);
	}
	printf("this is X, %d \n", x);
	printf("this is Y, %d \n", y);
	printf("GOING UP\n");
	// return x (operation) right
	if(!strcmp(current->value, "+"))
		return x + y;
	if(!strcmp(current->value, "-"))
		return x - y;
	if(!strcmp(current->value, "*"))
		return x * y;
	if(!strcmp(current->value, "/"))
		return (int)(x/y);
}
