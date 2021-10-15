#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "common.h"
#include "printGame.h"

/*!
   \brief Main entry point of the program.
*/
int main (void) {
  setlocale(LC_CTYPE, "");
  printIntro();
  printEmptyBoard();
  delayTimer(1);
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
