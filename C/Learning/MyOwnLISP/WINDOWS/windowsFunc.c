#include <stdio.h>
#include <stdlib.h>

// fake readline func
char* readline(char* prompt, char buf[MAX_INPUT_SIZE]){
  printf("%s", prompt);
  fgets(buf, MAX_INPUT_SIZE, stdin);
  char* cpy = malloc(strlen(buf) + 1); //+1 for null char
  strcpy(cpy, buf);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}


void add_history(char* unused){}
