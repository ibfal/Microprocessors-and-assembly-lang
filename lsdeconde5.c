#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertCharsToInt(char,char);

int main(int argc, char* argv[]){
  int i,j,z,cp=0, ascii = 257, counter=0,next;
  char c,d;
  char * dict[257];
  for (z=0; z< ascii; z++){
    dict[z]= malloc(257*sizeof(char));}//malloc(257*sizeof(char));}
  for (i = 0; i < ascii; i++){
    for (j = 0; j < ascii; j++){
      dict[i][j] = '-';}}

  FILE *infile;
  infile=fopen(argv[1], "r");

  if (infile != NULL){
    while(fscanf(infile, "%c", &c)!= EOF){
        //fscanf(infile,"%c", &d); 
        //c, d = convertCharsToInt(c,d);
        //printf("%s\n", "here ");
        if (c == 0){
          cp=0;
          counter++;
        fscanf(infile,"%c", &d); 
        c, d = convertCharsToInt(c,d);
          while (dict[counter][cp]!= '-'){
            cp++;}
            dict[counter][cp]= d;   
          printf("%c", dict[counter][cp]);
        }
        else{
          cp = 0;
          counter++; 
          char chara = dict[c][cp]; 
          dict[counter][cp]= chara;
          cp++;
        fscanf(infile,"%c", &d); 
        c, d = convertCharsToInt(c,d);
          dict[counter][cp] = d;
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
  

  int convertCharsToInt(char char1, char char2) { 
    return ((unsigned char) char1) + ( ((unsigned char) char2) << 8); }