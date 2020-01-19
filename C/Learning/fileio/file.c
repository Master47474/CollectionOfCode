#include <stdio.h>


int main(int argc, char *argv[]){
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if(argc == 1) // no args
    filecopy(stdin, stdout);
  else
    while(--argc > 0)
      if((fp = fopen(*++argv, "r")) == NULL){
        printf("Cat: cant open %s\n", *argv);
        return 1;
      }else{
        filecopy(fp, stdout);
        fclose(fp);
      }
    return 0
}

 /* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp){
  int c;

  // reading from input file
  while ((c = getc(ifp)) != EOF)
    putc(c, ofp); // writing to output which is the command line
}
