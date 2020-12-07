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
  while(!(res[n][0] == '\0' && res[n][1] == '\0')){
    //printf("\'%s\'\n", (res[n][0] == '\n') ? '\0' : res[n]);
    n++;
  }
  // Failes to check last entry???
  int isValid = 0;
  int fields = 0;
  int hasCid = 0;
  int neverValid = 0;
  printf("We got %d lines\n", n);
  for(int i = 0; i <= n; i++){
    if(res[i][0] == '\n' || (res[i][0] == '\0' && res[i][1] == '\0')){ // hence there is a break line
      if(isValid){
        total++;
      }
      isValid = 0; fields = 0; hasCid = 0; neverValid = 0;
      continue;
    }

    char** line = split(res[i], ' ');
    for(int j = 0; line[j][0] != '\0'; j++){
      char** x =  split(line[j], ':');
      char* field = x[0];
      char* data = x[1];
      if(!strcmp(field, "cid"))
        hasCid = 1;
      if(!strcmp(field, "byr")){
        if(toint(data) < 1920 || toint(data) > 2002)
          neverValid = 1;
      }
      if(!strcmp(field, "iyr"))
        if(toint(data) < 2010 || toint(data) > 2020)
          neverValid = 1;
      if(!strcmp(field, "eyr"))
        if(toint(data) < 2020 || toint(data) > 2030)
          neverValid = 1;
      if(!strcmp(field, "hgt")){
        if(data[2] == 'i'){
          if(toint(split(data, 'i')[0]) < 59 || toint(split(data, 'i')[0]) > 76)
            neverValid = 1;
        } else if(data[3] == 'c') {
          if(toint(split(data, 'c')[0]) < 150 || toint(split(data, 'c')[0]) > 193)
            neverValid = 1;
        }else{
          neverValid = 1;
        }
      }
      if(!strcmp(field, "hcl")){
        if(data[0] != '#'){
          neverValid = 1;
        }else{
          int chrs = 1;
          while(data[chrs] != '\0'){
            if(!((data[chrs] >= 48 && data[chrs] <= 57) || (data[chrs] >= 97 && data[chrs] <= 102)))
              neverValid = 1;
            chrs++;
          }
          if(chrs-1 != 6)
            neverValid = 1;
        }
      }
      if(!strcmp(field, "ecl")){
        if(!(!strcmp(data, "amb") || !strcmp(data, "blu") || !strcmp(data, "brn") || !strcmp(data, "gry") || !strcmp(data, "grn") || !strcmp(data, "hzl") || !strcmp(data, "oth") ))
          neverValid = 1;
      }
      if(!strcmp(field, "pid")){
        int lks = 0;
        while(data[lks] != '\0'){
          if(!(data[lks] >= 48 && data[lks] <= 57))
            neverValid = 1;
          lks++;
        }
        if(lks != 9)
          neverValid = 1;
      }
      fields++;
    }

    if(!neverValid && (fields == 8 || (fields == 7 && hasCid != 1)))
      isValid = 1;
  }
  printf("LOGIC\n");

  printf("we made it?\n");
  printf("%d\n", total);
  return 0;
}
