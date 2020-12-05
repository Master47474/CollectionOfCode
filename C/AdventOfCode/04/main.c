#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fsmainp.h"
#include "fsmainp.c"


int main(){
  int total = 0;
  int c;

  printf("fuck\n");
  // read the first int
  char** res = freadlines("input.txt");
  printf("READ IT\n");

  int n = 0;
  while(res[n][0] != '\0'){
    printf("\'%s\'\n", res[n]);
    n++;
  }


  printf("LOGIC\n");

  printf("we made it?\n");
  printf("%d\n", total);
  return 0;
}
