#include <stdio.h>
#include <stdlib.h>


int strlength(char string[]);
int newNumber(char string[], int len);
int powerOf(int base, int exp);



int main(int argc, char *argv[]){
  //argv[0] is file name
  int number = atoi(argv[1]);
  int length = strlength(argv[1]);

  if(number == newNumber(argv[1], length)){
    printf("%d is an amstrong Number \n", number);
  }else{
    printf("%d is not an armstrong number \n", number);
  }
  return 0;
}



int strlength(char string[]){
  int length = 0;
  for(length; string[length] != '\0'; ++length)
    ;
  return length;
}

int newNumber(char string[], int len){
  int newNo = 0;
  for(int i = 0; string[i] != '\0'; i++){
    // convert from ascII(CHAR) to integer
    newNo += powerOf((string[i]-48), len);
  }
  return newNo;
}


 int powerOf(int base, int exp){
   int result = 1;
   while (exp != 0) {
     result *= base;
     --exp;
   }
 }
