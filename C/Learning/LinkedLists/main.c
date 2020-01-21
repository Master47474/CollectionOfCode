#include <stdio.h>
#include <windows.h>
#include<string.h>
#include <stdlib.h>


struct Node{
  char data[45];
  struct Node* next;
};


void insertNode(struct Node* head, char val[]);
void printLL(struct Node* n);


int main(){
  struct Node* head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));

  strcpy(head->data, "NULL");
  head->next = NULL;

  /*
  struct Node* head2 = NULL;
  head2 = (struct Node*)malloc(sizeof(struct Node));

  strcpy(head2->data, "NULL2");
  head2->next = NULL;
  */

  insertNode(head, "NULL2");

  printLL(head);


  return 1;
}


void insertNode(struct Node* head, char val[]){
  struct Node *current = head;
  while(current->next != NULL)
    current = current->next;

  // add new varaible
  struct Node* temp = NULL;
  temp = (struct Node *) malloc(sizeof(struct Node));
  strcpy(temp->data, val);
  temp->next = NULL;
  current->next = temp;
}


void printLL(struct Node* n){
    struct Node *current = n;
    while (current != NULL) {
        printf(" %s \n", current->data);
        current = current->next;
    }
}
