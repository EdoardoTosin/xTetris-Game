#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "definitions.h"
#include "common.h"
#include "printGame.h"

/*!
   \brief Main entry point of the program.
*/
int main (void) {
  setlocale(LC_CTYPE, "");
  system(CLEAR);
  printIntro();
  delayTimer(1);
  system(CLEAR);
  printBoard();
  delayTimer(1);
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
