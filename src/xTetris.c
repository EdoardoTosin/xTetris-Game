#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "common.h"
#include "printGame.h"

#include "struct.h"
#include "initBoard.h"

/*!
   \brief Main entry point of the program.
*/
int main (void) {
  BoardPtr board_1, board_2;
  wchar_t* pl1;
  wchar_t* pl2;
  setlocale(LC_CTYPE, "");
  printIntro();
  pl1 = L"Player AAAAA";
  pl2 = L"Player BBBBB";
  board_1 = board_2 = initialize();
  printBoard(board_1, board_2, pl1, pl2);
  /*
  delayTimer(1);
  */
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
