#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h> /* sleep function */


#include "common.h"
#include "definitions.h"
#include "printGame.h"
#include "gameMenu.h"

#include "struct.h"
#include "initBoard.h"

/*!
   \brief Main entry point of the program.
*/
int main (int argc, char *argv[]) {
  int nChoices[2][4];
  int menu, opt, key=2;

  BoardPtr board_1, board_2;
  wchar_t* pl1;
  wchar_t* pl2;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  pl1 = L"\0";
  pl2 = L"\0";
  board_1 = board_2 = initialize();

  setlocale(LC_CTYPE, "");
  do{
    printIntro();
    key = waitUserInput();
  }
  while(key!=ESCAPE && key!=CARRIAGE_RETURN);

  nChoices[0][0]=2;
  nChoices[1][0]=5;
  nChoices[0][1]=nChoices[1][1]=6;
  nChoices[0][2]=nChoices[1][2]=7;
  nChoices[0][3]=nChoices[1][3]=8;
  menu=1;
  opt=nChoices[0][menu-1];
  do{
    if(menu!=2){ /* 2->Launch Gameplay */
      if(opt==6 || opt==7){
        menu=1;
        opt=opt-4;
      }
      opt = choiceCtrl(menu, opt, nChoices[0][menu-1], nChoices[1][menu-1]);
    }
    else{
      playersName(pl1, pl2);
      printBoard(board_1, board_2, pl1, pl2);
      opt=5;
    }
    menu=opt;
  }
  while(opt!=5);
  clearCLI();
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
