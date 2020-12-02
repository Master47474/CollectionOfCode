#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* readlines(FILE *f);
int chrpos(char* s, int c);
int toint(char* num);


FILE *file;

int main(){
  int target = 2020;
  int c;

  file = fopen("input.txt", "r");
  if(!file){
    printf("unable to open file\n");
    return 0;
  }
  // read the first int
  int* res = readlines(file);
  int n = 0;
  while(res[n] != -1)
    n++;

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      for(int k = j+1; k < n; k++)
      if(res[i] + res[j] + res[k] == 2020){
        printf("%d\n", res[i] * res[j] * res[k]);
      }
    }
  }
  return 0;
}


int* readlines(FILE *f){
  char* buf = malloc(sizeof(char) * 16);
  int* numbers = (int*)malloc(sizeof(int));
  int i = 0,k = 1;
  int c;
  while((c = fgetc(f)) != EOF){
    if(c == '\n'){
      buf[i++] = ' ';
      buf[i] = '\0';
      numbers = (int*)realloc(numbers, sizeof(int) * (k+1));
      numbers[k-1] = toint(buf);
      free(buf);
      buf = malloc(sizeof(char) * 16);
      k++;
      i = 0;
    }else{
      buf[i++] = c;
    }
  }
  numbers[k] = -1;
  return numbers;
}


//return the position of charcter c in string s
// or -1 if c not found
// will regokise '\0' as a 0
int chrpos(char* s, int c){
  char *p;

  p = strchr(s,c);
  return (p ? p-s : -1);
}

int toint(char* num){
  int k, val = 0;
  int i = 0;
  int c = num[i++];
  while((k = chrpos("0123456789", c)) >= 0){
    val = val*10 + k;
    c = num[i++];
  }
  return val;
}
