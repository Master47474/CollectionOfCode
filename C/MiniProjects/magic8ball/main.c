#include <stdio.h>
#include <windows.h>


void loading(int buffer);

char responses[][] = {"Certin", "Plausable", "unsure", "probably not", "Impossible"};

int main(int argc, char *argv[]){
  
}



void loading(int buffer){
  int x = 0;
  for (int dotlength = 0; dotlength < 7; dotlength++){
    x++;
    putchar('.');
    if(dotlength == 6){
      printf("\r       \r");
      if (x == buffer)
        break;
      dotlength = 0;
    }
    Sleep(400);
  }
}
