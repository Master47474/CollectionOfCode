
#include "fsmainp.h"

// Reads Lines in from a file
// Input - A File Dir
// Output - An array of strings "file split on '\n'"
char** freadlines(char* dir){
  FILE *file;

  file = fopen(dir, "r");
  if(!file){
    printf("Unable to open file %d\n", dir);
    exit(0);
  }
  int lsize = LINEBUF;
  int fsize = FILEBUF;

  char* buf = (char*)malloc(sizeof(char) * lsize);
  char** filelines = (char**)malloc(sizeof(char*)*fsize);


  int c;
  int i = 0,k = 1;
  while((c = fgetc(file)) != EOF){
    if(i+1 >= lsize){
      lsize *= 2;
      buf = (char*)realloc(buf, sizeof(char) * lsize);
      if(!buf){
        printf("Error Reallocing lbuf\n");
        exit(0);
      }
    }
    buf[i++] = c;

    if(c == '\n'){
      buf[i-1] = '\0';
      if(k >= fsize){
        fsize *= 2;
        filelines = (char**)realloc(filelines, sizeof(char*) * fsize);
        if(!filelines){
          printf("Error Reallocing filelines\n");
          exit(0);
        }
      }
      filelines[k-1] = (char*)malloc(sizeof(char) * lsize);
      strcpy(filelines[k-1], buf);
      k++;
      i = 0;
    }
  }

  if(i != 0){
    buf[i-1] = '\0';
    if(k == fsize){
      fsize *= 2;
      filelines = (char**)realloc(filelines, sizeof(char*) * fsize);
      if(!filelines){
        printf("Error Reallocing filelines\n");
        exit(0);
      }
    }
    filelines[k-1] = (char*)malloc(sizeof(char) * lsize);
    strcpy(filelines[k-1], buf);
    k++;
  }

  // The Null char to indicate the end of the array
  filelines[k-1] = (char*)malloc(sizeof(char)*2);
  filelines[k-1][0] = '\0';

  return filelines;
}

//return the position of charcter c in string s
// or -1 if c not found
// will regokise '\0' as a 0 !!!
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


// Splits a String by a certain character
char** split(char* line, char token){
  int ltemp = SPLITL;
  int lbuf = LINEBUF;

  char** temp = (char**)malloc(sizeof(char*) * ltemp);
  char* buf = (char*)malloc(sizeof(char) * lbuf);

  int k = 0;
  int bufl = 0;
  for(int i = 0; line[i] != '\0'; i++){
    if(bufl+1 >= lbuf){
      lbuf *= 2;
      buf = (char*)realloc(buf, sizeof(char) * lbuf);
      if(!buf){
        printf("Relloc of buf failed\n");
        exit(0);
      }
    }

    if(line[i] == token && bufl != 0){
      buf[bufl] = '\0';
      if(k+1 >= ltemp){
        ltemp *= 2;
        temp = (char**)realloc(temp, sizeof(char*) * ltemp);
        if(!temp){
          printf("realloc of temp failed\n");
          exit(0);
        }
      }
      temp[k] = (char*)malloc(sizeof(char)* lbuf);
      strcpy(temp[k++] , buf);
      bufl = 0;
      lbuf = LINEBUF;
      buf = (char*)realloc(buf, sizeof(char) * lbuf);
    }else{
      buf[bufl++] = line[i];
    }
  }

  if(bufl+1 >= lbuf){
    lbuf *= 2;
    buf = (char*)realloc(buf, sizeof(char) * lbuf);
    if(!buf){
      printf("Relloc of buf failed\n");
      exit(0);
    }
  }
  if(bufl != 0){
    buf[bufl] = '\0';
    if(k+1 >= ltemp){
      ltemp *= 2;
      temp = (char**)realloc(temp, sizeof(char*) * ltemp);
      if(!temp){
        printf("realloc of temp failed\n");
        exit(0);
      }
    }
    temp[k] = (char*)malloc(sizeof(char)* lbuf);
    strcpy(temp[k++] , buf);
    bufl = 0;
  }
  temp[k] = '\0';

  switch(k){
    case 0:
      strcpy(temp[0], line);
      temp[1] = '\0';
      temp = (char**)realloc(temp, sizeof(char*) * 2);
    default:
      break;
  };

  return temp;
}
