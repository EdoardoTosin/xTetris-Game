#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h> /* sleep function */


#include "common.h"
#include "definitions.h"
#include "printGame.h"
#include "gameMenu.h"

#include "struct.h"
#include "manageStruct.h"

/*!
   \brief Main entry point of the program.
*/
int main (int argc, char *argv[]) {
  int nChoices[2][4];
  int menu, opt, key=2;

  PlNamePtr pl1, pl2;
  BoardPtr board_1, board_2;

  pl1 = initializePlName();
  pl2 = initializePlName();
  board_1 = initializeBoard();
  board_2 = initializeBoard();

  setlocale(LC_CTYPE, "");
  do{
    welcome();
    key = waitUserInput();
  }
  while(/*key!=ESCAPE && */key!=CARRIAGE_RETURN);

  nChoices[0][0]=2;   /* Menu #1 -> Start Menu */
  nChoices[1][0]=5;
  nChoices[0][1]=6;   /* Menu #2 -> Start Game */
  nChoices[1][1]=8;
  nChoices[0][2]=nChoices[1][2]=9;    /* Menu #3 -> Rules */
  nChoices[0][3]=nChoices[1][3]=10;   /* Menu #4 -> Credits */
  menu=1;
  do{
    if(menu!=6 && menu!=7){
      if(menu>=8 && menu<=10){
        opt=menu-6;
        menu=1;
      }
      else
        opt=nChoices[0][menu-1];
      menu = choiceCtrl(menu, opt, nChoices[0][menu-1], nChoices[1][menu-1]);
    }
    else{/*
      secondPlayerName(pl1, pl2, menu-6);*/
      printBoard(board_1, board_2, pl1, pl2);

      delayTimer(2);
      menu=5;
    }
  }
  while(menu!=5);

  goodbye();

  destroyPlName(pl1);
  destroyPlName(pl2);
  destroyBoard(board_1);
  destroyBoard(board_2);

  clearCLI();
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
