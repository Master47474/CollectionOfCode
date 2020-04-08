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
		printInOrder(getRight(tree));
		printf(" %s ", tree->value);
	}
}



struct node* buildParseTree(char** tokenExp){
	struct node* head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	struct node* current = head;
	int expi = 0;
	
	while(strcmp(tokenExp[expi], "\0")){
		printf("WE EXEXUCITNG %s \n", tokenExp[expi]);
		if(isOpenBracket(tokenExp[expi][0])){
			insertRight(current);
			current = current->left;
		}else if(isOperation(tokenExp[expi][0])){
			printf("-This is a operation\n");
			setValue(current, tokenExp[expi]);
			printf("-Set the Value\n");
			insertRight(current);
			current = current->right;
		}else if(isDigit(tokenExp[expi][0]) || tokenExp[expi][0] == '.'){
			printf("-THIS IS A DIGIT\n");
			setValue(current, tokenExp[expi]);
			printf("-After setting a value\n");
			current = current->parent;
		}else if(isEndBracket(tokenExp[expi][0])){
			current= current->parent;
		}
		expi++;
	}
	return head;
}

void insertLeft(struct node* head){
	struct node* new = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	head->left = new;
}

void insertRight(struct node* head){
	struct node* new = NULL;
	new = (struct node*)malloc(sizeof(struct node));
	head->right = new;
}

void setValue(struct node* current, char* value){
	printf("Inside the func    %ld \n", sizeof(value));
	current->value = (char*)malloc(sizeof(value));
	printf("After memory\n");
	strcpy(current->value, value);
	printf("Set it\n");
}

struct node* getLeft(struct node* current){
	return current->left;
}

struct node* getRight(struct node* current){
	return current->right;
}

char* getValue(struct node* current){
	return current->value;
}

