#include <stdio.h>
#include <stdlib.h>
int * board[3];
void printboard();
char checkwin();                                                   
void winnerdeclareX(char);
void winnerdeclareO(char);

int main(){
  char response, winner;
  int i,j,row, col;
  int r= 3, c=3;
  //int * board[r];                                                             
  for (i=0; i<r; i++){
   board[i]= malloc(c*sizeof(int));}
  for (i = 0; i < r; i++){
    for (j = 0; j < c; j++){
      board[i][j] = ' ';}}
  printf("Output Play (y/n):\n");
  scanf(" %c",&response);

  if (response=='y'|| response=='Y'){
    //output play                                                               
    printf("You entered %c.\n", response);
    printf("Starting game with 3 x 3 board.\n");
    printf("Each player should enter\na row and col num (eg: 2 0).\n");
    i=0;
    while (i<r*c){
      if (i%2==0){
        printf("Player 1:\n");
        scanf("%d %d",&row,&col);
        while ((row<0)||(row>=3)||(col<0)||(col>=3)||board[row][col] == 'X' || board[row][col]== 'O'){ 
          printf("Incorrect value, try again.\n");
          printf("Player 1:\n");
          scanf("%d %d",&row,&col);} 

        if(board[row][col] == ' '){
          printf("Player 1 entered %d %d.\n", row, col);
          board[row][col]='O';
          printboard();
          winner= checkwin();
          if(winner != ' '){
            winnerdeclareO(winner);
            break;}}}

      else{
        printf("Player 2:\n");
        scanf("%d %d",&row,&col);

        while ((row<0)||(row>=3)||(col<0)||(col>=3)||board[row][col] == 'X' || board[row][col]== 'O'){ 
          printf("Incorrect value, try again.\n");
          printf("Player 2:\n");
          scanf("%d %d",&row,&col);} 

        if(board[row][col] == ' '){
          printf("Player 2 entered %d %d.\n", row, col);
          board[row][col]='X';
          printboard();
          winner= checkwin();
          if(winner != ' '){
            winnerdeclareX(winner);
            break;}}}
      ++i;
    }}

  if (response=='n'|| response=='N'){
    //not output play                                                                                                                                     
    printf("You entered %c.\n", response);
    printf("Starting game with 3 x 3 board.\n");
    printf("Each player should enter\na row and col num (eg: 2 0).\n");
    i=0;
    while (i<r*c){
      if (i%2==0){
        printf("Player 1:\n");
        scanf("%d %d",&row,&col);
        while ((row<0)||(row>=3)||(col<0)||(col>=3)||board[row][col] == 'X' || board[row][col]== 'O'){
          printf("Incorrect value, try again.\n");
          printf("Player 1:\n");
          scanf("%d %d",&row,&col);} 

        if(board[row][col] == ' '){
          printf("Player 1 entered %d %d.\n", row, col);
          board[row][col]='O';
          winner= checkwin();
          if(winner != ' '){
            winnerdeclareO(winner);
            break;}}
      }
      else{
        printf("Player 2:\n");
        scanf("%d %d",&row,&col);
        while ((row<0)||(row>=3)||(col<0)||(col>=3)||board[row][col] == 'X' || board[row][col]== 'O'){
          printf("Incorrect value, try again.\n");
          printf("Player 2:\n");
          scanf("%d %d",&row,&col);} 

        if(board[row][col] == ' '){
          printf("Player 2 entered %d %d.\n", row, col);
          board[row][col]='X';
          winner= checkwin();
          if(winner != ' '){
            winnerdeclareX(winner);
            break;}}
      }
      ++i;
    }}}

  void printboard(){
    printf("-------------\n");
    printf("| %c | %c | %c |\n",board[0][0],board[0][1],board[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n",board[1][0],board[1][1],board[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n",board[2][0],board[2][1],board[2][2]);
    printf("-------------\n");}

char checkwin(){
  int j;
  for (j=0;j<3; j++){
    if (board[j][0]== board[j][1]&& board[j][0]==board[j][2]){
      return board[j][0];}}
  for (j=0; j<3; j++){
      if (board[0][j]== board[1][j]&& board[0][j]==board[2][j]){
        return board[0][j];}}
  if (board[0][0]== board[1][1]&& board[0][0]==board[2][2]){
       return board[0][0];}
  if (board[0][2]== board[1][1]&& board[0][2]==board[2][0]){
    return board[0][2];}
  return ' ';}
  

void winnerdeclareX(char winner){
    if(winner == 'X'){
      printf("Player 2 is the winner.\n");
      printboard();}}

void winnerdeclareO(char winner){
    if(winner == 'O'){
      printf("Player 1 is the winner.\n");
      printboard();
    }}

