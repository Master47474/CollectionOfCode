#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>


void loading(int buffer);
int randInteger();



char* responses[] = {"Certin", "Plausable", "unsure", "probably not", "Impossible"};

int main(int argc, char *argv[]){
  printf("What question do you seek information about ? >> ");
  char question[50];

  while(1){
    int c, i = 0;
    while((c=getchar()) != EOF){
      if( c == '\n')
        break;
      question[i++] = c;
    }
    question[i] = '\0';
    if(strcmp("quit", question) == 0)
      break;
    loading(12);
    printf("\n>> %s \n", responses[randInteger()]);
    printf("What question do you seek information about ? >> ");
  }

}



void loading(int buffer){
  int x = 0;
  for (int dotlength = 0; dotlength < 7; dotlength++){
    x++;
    putchar('.');
    if(dotlength == 6){
      printf("\r       \r");
      dotlength = 0;
    }
    if (x == buffer)
      break;
    Sleep(400);
  }
}


int randInteger(){
  srand(time(0));
  return (rand() % 5);
}
