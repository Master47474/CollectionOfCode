#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readlines(FILE *f);
int chrpos(char* s, int c);
int toint(char* num);
char** split(char* line, char token);

FILE *file;

int main(){
  int total = 0;
  int c;

  file = fopen("input.txt", "r");
  if(!file){
    printf("unable to open file\n");
    return 0;
  }
  printf("fuck\n");
  // read the first int
  char** res = readlines(file);
  printf("BRUH MOMENT\n");

  int n = 0;
  while(res[n][0] != '\0'){
    printf("\'%s\'\n", res[n]);
    n++;
  }


  printf("bruh\n");
  // 63
  // 255
  // 62
  // 56
  // 30
  int i = 0, j = 0;
  while(1){
    if(j >= n)
      break;
    if(res[j][i] == '#'){
      total++;
    }

    i = (i + 5) % 31;
    j += 1;
  }

  printf("we made it?\n");
  printf("%d\n", total);
  return 0;
}


char** readlines(FILE *f){
  char* buf = (char*)malloc(sizeof(char) * 64);
  int size = 15;
  char** numbers = (char**)malloc(sizeof(char*)*size);
  int i = 0,k = 1;
  int c;
  while((c = fgetc(f)) != EOF){
    buf[i++] = c;
    if(c == '\n'){
      buf[i-1] = '\0';
      if(k == size){
        size *= 2;
        numbers = (char**)realloc(numbers, sizeof(char*) * (size));
        if(!numbers)
          printf("FUCLLLLLLL\n");
      }
      numbers[k-1] = (char*)malloc(sizeof(char) * 64);
      strcpy(numbers[k-1], buf);
      k++;
      i = 0;
    }
  }
  if(i != 0){
    buf[i-1] = '\0';
    if(k == size){
      size *= 2;
      numbers = (char**)realloc(numbers, sizeof(char*) * (size));
      if(!numbers)
        printf("FUCLLLLLLL\n");
    }
    numbers[k-1] = (char*)malloc(sizeof(char) * 64);
    strcpy(numbers[k-1], buf);
    k++;
    i = 0;
  }
  numbers[k-1] = (char*)malloc(sizeof(char)*2);
  numbers[k-1][0] = '\0';
  printf("hmmmm \'%s\'\n", numbers[k]);
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
  while(c != '\0' && (k = chrpos("0123456789", c)) >= 0){
    val = val*10 + k;
    c = num[i++];
  }
  return val;
}


char** split(char* line, char token){
  char** temp = (char**)malloc(sizeof(char*) * 4);  // indecies 0,1,2,3 (3 being '\0')
  char* buf = (char*)malloc(sizeof(char) * 64);

  int k = 0;
  int bufl = 0;
  for(int i = 0; line[i] != '\0'; i++){
    if(line[i] == token && bufl != 0){
      buf[bufl] = '\0';
      temp[k] = (char*)malloc(sizeof(char)* 64);
      strcpy(temp[k++] , buf);
      bufl = 0;
    }else{
      buf[bufl++] = line[i];
    }
  }
  if(bufl != 0){
    buf[bufl] = '\0';
    temp[k] = (char*)malloc(sizeof(char)* 32);
    strcpy(temp[k++] , buf);
    bufl = 0;
  }
  temp[k] = '\0';


  switch(k){
    case 0:
      strcpy(temp[0], line);
      temp[1] = '\0';
      temp = (char**)realloc(temp, sizeof(char*) * 2);
    break;
    case 1:
    case 2:
    case 3:
    case 4:
    default:
      break;
  };

  return temp;
}
