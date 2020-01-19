#include <stdio.h>
#include <windows.h>

int main(){
  // first iteration
  /*
  int dotlength = 0;
  while(1){ // infinite loop for loading
    putchar('.');
    dotlength++;
    if(dotlength == 6){
      printf("\r      \r");
      dotlength = 0;
    }
    Sleep(400);
  }
  */

  // second version
  for (int dotlength = 0; dotlength < 7; dotlength++){
    putchar('.');
    if(dotlength == 6){
      printf("\r       \r");
      dotlength = 0;
    }
    Sleep(400);
  }

  return 0;
}
