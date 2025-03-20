#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
char c;
FILE *infile;
infile=fopen(argv[1], "r");
if (infile != NULL){
    while((c=fgetc(infile))!= EOF){
        printf("%c", c);
        if (c=='g'){
            printf("%s", "remlin");}
        if (c=='G'){           
            printf("%s", "REMLIN");}
    }
    printf("\n");
    fclose(infile);
}
return 0;}