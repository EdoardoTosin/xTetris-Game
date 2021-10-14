#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "definitions.h"
#include "common.h"

/*!
   \brief Main entry point of the program.
*/
int main (void) {
  system(CLEAR);
  puts("/====================/");
  puts("        xTetris       ");
  puts("/====================/");
  setlocale(LC_CTYPE, "");
  wchar_t ch = 0x254u;
  wprintf(L"%lc\n", ch);

  delayTimer(1);
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
