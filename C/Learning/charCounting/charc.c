#include <stdio.h>



int main(){
  /*
  long nc;

  nc = 0;

  while (getchar() != EOF){
    ++nc;
  }
  printf("%ld\n", nc);
  */

  /* Version 2*/
  double nc;
  for(nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f", nc);

  // ;ine counting
  int c, nl;

  nl = 0;
  while((c= getchar()) != EOF){
    if (c == '\n')
      ++nl;
    printf("%d\n", nl);
  }
}
