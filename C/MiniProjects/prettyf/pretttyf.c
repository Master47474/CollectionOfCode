#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#include <string.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_SIZE 1024

typedef enum TextColour{
  TC_ERROR = -1,
  TC_BLACK = 0,
  TC_BLUE = 1,
  TC_GREEN = 2,
  TC_CYAN = 3,
  TC_RED = 4,
  TC_MAGENTA = 5,
  TC_BROWN = 6,
  TC_LIGHTGRAY = 7,
  TC_DARKGRAY = 8,
  TC_LIGHTBLUE = 9,
  TC_LIGHTGREEN = 10,
  TC_LIGHTCYAN = 11,
  TC_LIGHTRED = 12,
  TC_LIGHTMAGENTA = 13,
  TC_YELLOW = 14,
  TC_WHITE = 15
} TextColour;

const static struct{
  TextColour   col;
  char *str;
} conversion [] = {
  {TC_BLACK, "TC_BLACK"},
  {TC_BLUE, "TC_BLUE"},
  {TC_GREEN, "TC_GREEN"},
  {TC_CYAN, "TC_CYAN"},
  {TC_RED, "TC_RED"},
  {TC_MAGENTA, "TC_MAGENTA"},
  {TC_BROWN, "TC_BROWN"},
  {TC_LIGHTGRAY, "TC_LIGHTGRAY"},
  {TC_DARKGRAY, "TC_DARKGRAY"},
  {TC_LIGHTBLUE, "TC_LIGHTBLUE"},
  {TC_LIGHTGREEN, "TC_LIGHTGREEN"},
  {TC_LIGHTCYAN, "TC_LIGHTCYAN"},
  {TC_LIGHTRED, "TC_LIGHTRED"},
  {TC_LIGHTMAGENTA, "TC_LIGHTMAGENTA"},
  {TC_YELLOW, "TC_YELLOW"},
  {TC_WHITE, "TC_WHITE"}
};

//func Declarations
void setTextColour(FILE* stream, TextColour colour);
void prettyf(char output[]);
char** tokenize(char* output);
TextColour str2enum(const char* str);



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
    prettyf(input);
  }
//  prettyf("-[TC_CYAN]-[TC_RED]Hello i am -[TC_LIGHTRED] Marcus\n");

  return EXIT_SUCCESS;
}


void setTextColour(FILE* stream, TextColour colour){
  int outfd = fileno(stream);
  HANDLE out = (HANDLE)_get_osfhandle(outfd);
  DWORD outType = GetFileType(out);
  DWORD mode;
  if(outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode)){
    SetConsoleTextAttribute(out, colour);
  }
}

void prettyf(char output[]){
  char** tokens = tokenize(output);
  int n = 0;
  //10 is max tokens per line
  for(n = 0; n < 10; ++n){
    if(tokens[n][0] == '\0'){
      break;
    }
  }
  for(int i = 0; i < n; ++i){
    if(str2enum(tokens[i]) != TC_ERROR){
      setTextColour(stdout, str2enum(tokens[i]));
    }else{
      printf("%s",tokens[i]);
    }
  }
  setTextColour(stdout, TC_LIGHTGRAY);
  printf("\n");
}

char** tokenize(char* output){

  // MAX 5 Colour Changes // max sentance length is 1024 chars
  char** tokens = malloc(10 * sizeof(char*));

  char ColToken[] = "-[";
  int n = sizeof(ColToken)/sizeof(char); // should be 2
  int outputSize = sizeof(output)/sizeof(char); // sould be number of chars in output

  char temptext[MAX_LINE_SIZE];
  int i = 0, toki = 0, tempi = 0, bigi = 0;
  int In = 0; // 0 = no, 1 = yes
  int c;

  while( (c=output[i++]) != EOF ){
    if(c == '\n')
      break;
    temptext[tempi++] = c;
    if(c == ColToken[toki++]){
        if(toki == 2){
          toki = 0;
          tempi -= 2;
          temptext[tempi] = '\0';
          if(tempi != 0){ // if there was something before this
            tokens[bigi] = malloc(tempi * sizeof(char));
            strcpy(tokens[bigi++],temptext);
          }

          In = 1;
          tempi = 0;
          while((c=output[i++]) != ']'){
            temptext[tempi++] = c;
          }
          temptext[tempi] = '\0';
          tokens[bigi] = malloc(tempi * sizeof(char));
          strcpy(tokens[bigi++],temptext);
          tempi = 0;
        }
      continue;
    }
    toki = 0;
  }

  temptext[tempi] = '\0';
  tokens[bigi] = malloc(tempi * sizeof(char));
  strcpy(tokens[bigi++],temptext);

  //add null char to end of tokens
  tempi = '\0';
  temptext[tempi] = '\0';
  tokens[bigi] = malloc(tempi * sizeof(char));
  strcpy(tokens[bigi++],temptext);

  return tokens;
}

TextColour str2enum(const char* str){
  int j;
  for(j = 0; j < sizeof(conversion)/sizeof(conversion[0]); ++j)
    if(!strcmp(str, conversion[j].str))
      return conversion[j].col;
  return TC_ERROR;
}
