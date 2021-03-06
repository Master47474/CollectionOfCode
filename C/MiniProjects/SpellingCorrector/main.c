#include <stdio.h>
#include <windows.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>



// file maxLINES
#define MAXLINES 194433 // max length of english file
#define INPP 1 //in a word
#define OUTPP 0 //outside a word



struct lineno{
  char letter;
  int fileline;
} charLine[26];

// linked list for misspelled words
struct Node{
  char data[45];
  struct Node* next;
};



void printLL(struct Node* n);
void loading();
void loadDictionary();
int isSpelledCorrectly(char word[]);
void insertNode(struct Node* head, char val[]);


char dictionary[MAXLINES][45];

int main(){
  loadDictionary();
  // let person write from command line, (ctrl z is exit from EOF)

  struct Node* head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));


  // assign head and tail to be place holders
  strcpy(head->data, "-----");
  head->next = NULL;



  int c, nl, nw, state;
  char currentword[45];
  int i = 0;

  state = OUTPP;
  nl = 0;
  while((c = getchar()) != EOF){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
      currentword[i++] = tolower(c);
    }
    if(c == '\n')
      ++nl;
    if(c == ' ' || c == '\n' || c == '\t'){
      if(state == INPP && i != 0)
        currentword[i] = '\0';
      i = 0;
      state = OUTPP;
      // test if word is spelled correctly i.e find it in the file
      if (isSpelledCorrectly(currentword) == 0){
        insertNode(head, currentword);
      }
    }else if(state == OUTPP){
      state = INPP;
    }
  }

  printf("YOU SPELLED WRONGLY :\n");
  printLL(head);

  return 0;
}


// returns 0 for false, returns 1 for true
int isSpelledCorrectly(char word[]){
  // get init range
  int min, mid, max;
  min = mid = 0;
  max = charLine[1].fileline;
  for(int i = 0; charLine[i].letter != word[0]; ++i){
    if(word[0] == 'y'){
      min = charLine[24].fileline;
      max = charLine[25].fileline;
    }else if(word[0] == 'z'){
      min = charLine[25].fileline;
      max = MAXLINES;
    }else{
      min = charLine[i+1].fileline;
      max = charLine[i+2].fileline;
    }
  }
  mid = (min + max ) / 2; // was going to add different searching algorithm

  // linear search through
  for(min; min <= max ; ++min){
    int i = 0;
    while(1){
      if(word[i] != dictionary[min][i])
        break;
      if(word[i] == '\0' && dictionary[min][i] == '\0'){
        return 1;
      }
      i++;
    }
  }
  return 0;
}


void loading(){
  for (int dotlength = 0; dotlength < 7; dotlength++){
    putchar('.');
    if(dotlength == 6){
      printf("\r       \r");
      dotlength = 0;
    }
    Sleep(400);
  }
}


void loadDictionary(){
  // read file and load to array

  FILE *fp;

  if ( (fp = fopen("english.txt", "r")) == NULL){
    printf("cant open %s\n", "english.txt");
    //return 1;
  }else{
    int c, nl, state, arraycounter;
    int oldc = 'a';

    int i = 0;
    int globali = 0;
    char string[45];

    state = OUTPP;
    nl = arraycounter = 0;

    //insert a into array
    charLine[arraycounter].letter = oldc;
    charLine[arraycounter++].fileline = nl;



    while((c = getc(fp)) != EOF){
      if(c == '\n'){
        string[i++] = '\0';
        strcpy(dictionary[globali++], string);
        ++nl;
        state = OUTPP; // this means new word is coming up next line
      }else if (state == OUTPP){
        state = INPP;
        if (c != oldc){
          oldc = c; // check if first letter of new word is new letter
          charLine[arraycounter].letter = c;
          charLine[arraycounter++].fileline = nl;
        }
        i = 0;
        string[i++] = c;
      }else{
        string[i++] = c;
      }
    }
    // print array of structs
    /*
    for(int i = 0; i < 26; i++){
      printf("%c is at line %d\n", charLine[i].letter, charLine[i].fileline);
    }
    */
  }
  fclose(fp);
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
