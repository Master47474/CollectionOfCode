#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 2048
#define TRUE 1
#define FALSE 0

static char buffer[MAX_INPUT_SIZE];

#ifdef _WIN32
#include <string.h>
//windows version of functions
#include "WINDOWS/windowsFunc.h"
//otherwise
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char* argv[]){

  //print version and exit infomration
  printf("Lispss Version 0.01\n");
  printf("press Ctrl+c To Exit\n");


  //infinite loop
  while(TRUE){

    char* input = readline("lispss >> ", buffer);
    add_history(input);

    //echo back to user
    printf("No you are a %s\n", input);


    //memory managment
    free(input);
  }

  return 0;
}
