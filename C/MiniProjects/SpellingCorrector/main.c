#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

// file maxLINES
#define MAXLINES 194433 // max length of english file
#define INPP 1 //in a word
#define OUTPP 0 //outside a word



void loading();
void loadDictionary();

struct lineno{
  char letter;
  int fileline;
} charLine[26];

// linked list for misspelled words
struct Node{
  char *data;
  struct Node* next;
};


int main(){

  loadDictionary();

  // let person write from command line, (ctrl z is exit from EOF)
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* tail = NULL;

  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  // assign head and tail to be place holders
  head->data = "\0";
  head->next = tail;

  tail->data = '\0';
  tail->next = NULL;


  int c, nl, nw, state;
  char currentword[] = "";
  int i = 0;

  state = OUTPP;
  nl = 0;
  while((c = getchar()) != EOF){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
      currentword[i++] = c;
    if(c == '\n')
      ++nl;
    if(c == ' ' || c == '\n' || c == '\t'){
      if(state == INPP && i != 0)
        currentword[i] = '0';
      i = 0;
      state = OUTPP;
      // test if word is spelled correctly i.e find it in the file
    }else if(state == OUTPP){
      state = INPP;
    }
  }

  return 0;
}

bool isSpelledCorrectly(char word[]){
  // get init range
  int min, mid, max;
  for(int i = 0; charLine[i].letter != word[0]; ++i){
    if(word[0] == 'y'){
      min = charLine[24].fileline;
      max = charLine[25].fileline;
    }
    if(word[0] == 'z'){
      min = charLine[25].fileline;
      max = MAXLINES;
    }
    min = charLine[i+1].fileline;
    max = charLine[i+2].fileline;
  }
  mid = (min + max ) / 2; // was going to add different searching algorithm
  // linear search through
  for(min; min <= max; ++min){
    // make an array storing all words and then search through it
  }
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
  // read file

  FILE *fp;

  if ( (fp = fopen("english.txt", "r")) == NULL){
    printf("cant open %s\n", "english.txt");
    return 1;
  }else{
    int c, nl, state, arraycounter;
    int oldc = 'a';

    state = OUTPP;
    nl = arraycounter = 0;

    //insert a into array
    charLine[arraycounter].letter = oldc;
    charLine[arraycounter++].fileline = nl;

    while((c = getc(fp)) != EOF){
      if(c == '\n'){
        ++nl;
        state = OUTPP; // this means new word is coming up next line
      }else if (state == OUTPP){
        state = INPP;
        if (c != oldc){
          oldc = c; // check if first letter of new word is new letter
          charLine[arraycounter].letter = c;
          charLine[arraycounter++].fileline = nl;
        }
      }
    }
    // print array of structs
    for(int i = 0; i < 26; i++){
      printf("%c is at line %d\n", charLine[i].letter, charLine[i].fileline);
    }
  }
  fclose(fp);
}
