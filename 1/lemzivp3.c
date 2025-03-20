#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  int c, counter, chara;
  int dict[257];
  int maxsize= 20;

  FILE *infile;
  infile=fopen(argv[1], "r");

  if (infile != NULL){
    while(fscanf(infile, "%d", &c)!= EOF){

        if (c == 0){
          fscanf(infile,"%d", &c);
          //printf("%d",c);                                                     
          counter++;
          dict[counter]= c;
          printf("%c", c);
        }
        else{
          //printf("%s %d\n", "here ", c);                                      
          chara = c;
          printf("%c", dict[chara]);
        }
    }
    fclose(infile);
  }
  return 0;}
