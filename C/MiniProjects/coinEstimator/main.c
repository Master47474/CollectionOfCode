#include <stdio.h>
#include <stdlib.h>

/*
  5c w - 2.825g
  10c w - 5.65g
  20c w - 11.3g
  50c w - 15.55g
  1 w - 9g
  2 w - 6.6g
*/
int printStatement(float weightOfCoin, int wrapperSize);


int main(){
  float total = 0;
  printf("enter weight of coins you have (5c)>> ");
  total += 0.05 * printStatement(2.825, 40);
  printf("enter weight of coins you have (10c)>> ");
  total += 0.1 * printStatement(5.65, 40);
  printf("enter weight of coins you have (20c)>> ");
  total += 0.2 * printStatement(11.3, 20);
  printf("enter weight of coins you have (50c)>> ");
  total += 0.5 *printStatement(15.55, 20);
  printf("enter weight of coins you have ($1)>> ");
  total += 1 *printStatement(9, 25);
  printf("enter weight of coins you have ($2)>> ");
  total += 2 *printStatement(6.6, 25);

  printf("you have about $%0.2f \n", total);
}



int printStatement(float weightOfCoin, int wrapperSize){
  char weight[10];
  int c, i = 0;
  while((c=getchar()) != EOF){
    if( c == '\n')
      break;
    weight[i++] = c;
  }
  float wrapperValue = (atoi(weight)/weightOfCoin);
  printf("you have %.0f coins and need %.0f wrappers\n", atoi(weight)/weightOfCoin, (int)wrapperValue == (int)wrapperSize ? wrapperValue/wrapperSize : wrapperValue/wrapperSize +1);
  return wrapperValue;
}
