#include <stdio.h>



//function declarations
void printBottle(int bottles);

int main(){
  int maxBottles = 100;
  while(maxBottles != 0){
    printBottle(maxBottles--);
  }
}


void printBottle(int bottles){
  printf("%d ", bottles);
  bottles == 1 ? printf("bottle ") : printf("bottles ");
  printf("on the wall, take one down pass it around\n");
}