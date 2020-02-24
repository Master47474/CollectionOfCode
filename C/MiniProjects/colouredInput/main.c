#include <stdio.h>

#include "../prettyf/prettyf.h"



int main(){
  while(1){
    printf("What would you like to print >> ");
    int c, i = 0;
    char input[MAX_LINE_SIZE];
    while((c=getchar()) != EOF){
      if(c == '\n')
        break;
      input[i++] = c;
    }
    input[i] = '\0';
    printf("\r");
    prettyf(input);
  }

  return 0;
}
