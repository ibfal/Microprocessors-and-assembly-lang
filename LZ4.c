#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  int c,i,j,z,cp=0, ascii = 257, counter=0,next;
  char * dict[257];
  for (z=0; z< ascii; z++){
    dict[z]= malloc(257*sizeof(char));}//malloc(257*sizeof(char));}
  for (i = 0; i < ascii; i++){
    for (j = 0; j < ascii; j++){
      dict[i][j] = '-';}}

  FILE *infile;
  infile=fopen(argv[1], "r");

  if (infile != NULL){
    while(fscanf(infile, "%d", &c)!= EOF){
        //printf("%s\n", "here ");
        if (c == 0){
          cp=0;
          fscanf(infile,"%d", &c);                                                    
          counter++;
          while (dict[counter][cp]!= '-'){
            cp++;}
            dict[counter][cp]= c;   
          printf("%c", dict[counter][cp]);
        }
        else{
          cp = 0;
          counter++; 
          char chara = dict[c][cp]; 
          dict[counter][cp]= chara;
          cp++;
          fscanf(infile,"%d", &c);
          dict[counter][cp] = c;
          cp=0;
          while (dict[counter][cp]!= '-'){
           printf("%c", dict[counter][cp]); 
           cp++;
          }
        }
    }
    fclose(infile);
  }
  return 0;}
  