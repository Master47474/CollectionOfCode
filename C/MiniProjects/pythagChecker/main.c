#include <stdio.h>
#include <stdlib.h>

void ssort(int triple[]);
void swap(int* x, int *y);
int checkTriple(int s1, int s2, int s3);


int main(int argc, char *argv[]){
  if(argc == 4){
    if(checkTriple(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])) == 1){
      printf("YES IT IS\n");
    }else{
      printf("NO IT IS NOT\n");
    }
  }
  printf("please input 3 side lengths of (int int int) when running program \n");

  return 0;
}


int checkTriple(int s1, int s2, int s3){
  s1 *= s1;
  s2 *= s2;
  s3 *= s3;
  int triple[] = {s1, s2, s3};
  ssort(triple);

  if(triple[0] + triple[1] == triple[2])
    return 1;

  return 0;
}



void ssort(int triple[]){
  int minIn;
  for(int i = 0; i < 3; i++){
    minIn = i;
    for(int j = i+1; j < 3; j++){
      if(triple[j] < triple[minIn])
        minIn = j;
    }
    swap(&triple[minIn], &triple[i]);
  }
}


void swap(int* x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}
