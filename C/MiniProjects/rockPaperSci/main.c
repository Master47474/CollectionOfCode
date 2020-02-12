#include <stdio.h>
#include <stdlib.h>


// Try a switch statement!!!


struct Map {
  char type[8];
  int value;
};

int main(){

  struct Map map[4];
  map[0].type = "rock\0"; map[0].value = 0;
  map[1].type = "scissors\0"; map[1].value = 1;
  map[2].type = "paper\0"; map[2].value = 2;
  map[3].type = "rock\0"; map[3].value = 3;

  printf("Rock Paper Scissors? > ");

  char answer[10];

  while(1){
    int c, i = 0;
    while((c=getchar()) != EOF){
      if( c == '\n')
        break;
      answer[i++] = c;
    }
    answer[i] = '\0';
  }
  // find answer in map
  char companswer[] = "paper";
  int corresponsingKey = 2;
for(int i = 0; i < 3; i++){
  if(strcmp(companswer, answer) == 0) break;
  if(strcmp(map[i], answer) == 0 && (map[corresponsingKey].value - map[i].value == -1)){
    printf("you win\n");
    break;
  } else{
    printf("you loose \n");
    break;
  }
}


  return 0;
}
