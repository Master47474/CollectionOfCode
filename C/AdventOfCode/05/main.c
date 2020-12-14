#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "fsmainp.h"
#include "fsmainp.c"


int main(){
  int max = 0;
  int total = 0;
  int total1 = 0;
  int c;

  printf("fuck\n");
  // read the first int
  char** res = freadlines("input.txt");
  printf("READ IT\n");

  int n = 0;
  while(!(res[n][0] == '\0' && res[n][1] == '\0')){
    //printf("\'%s\'\n", (res[n][0] == '\n') ? '\0' : res[n]);
    n++;
  }
  int shit[823]; //
  printf("We got %d lines\n", n);
  for(int i = 0; i < n; i++){
    int index = 6; // 0 - 6 i.e 7 total
    int exp = 0;
    while(index >= 0){
      if(res[i][index] == 'B')
        total += pow(2, exp);
      index--;
      exp++;
    }
    index = 6 + 3;
    exp = 0;

    while(index > 6){
      if(res[i][index] == 'R')
        total1 += pow(2, exp);
      index--;
      exp++;
    }


    max = total*8 + total1;
    shit[max] = max;
    total = 0;
    total1 = 0;
  }

  for(int i = 0; i <= 822; i++){
    if(i != shit[i]){
      total = i;
      printf("\'%d\'\n", i);
    }
  }


  printf("LOGIC\n");

  printf("we made it?\n");
  printf("%d\n", total);
  return 0;
}
