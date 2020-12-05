

#include <stdlib.h>

// file defines
#define LINEBUF 128
#define FILEBUF 128

//split defines
#define SPLITL 16

// File Functions
char** freadlines(char* dir);


// String Functions
int toint(char* num);
char** split(char* line, char token);
