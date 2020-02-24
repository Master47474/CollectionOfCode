
#include <stdio.h>


int shifting(int x, int y){
  printf("%d and %d<<1 = %d\n", x, y, y<<8);
  return x | y<<8;
}


int main(){
  int number = shifting(8,8);
  printf("%d\n", number);

  return 0;
}
