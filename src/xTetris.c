#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "definitions.h"
#include "common.h"

/*!
   \brief Main entry point of the program.
*/
int main (void) {
  setlocale(LC_CTYPE, "");
  system(CLEAR);
  /*
  puts("/====================/");
  puts("        xTetris       ");
  puts("/====================/");
  */
  wchar_t ch = 0x1f533;
  int i, j;
  for (i=0; i<10; i++){
    for (j=0; j<10; j++){
      wprintf(L"%lc", ch);
    }
    wprintf(L"\n");
  }
  wprintf(L"Test success.\n");
  delayTimer(1);
  return 0;
}

/*!
@mainpage xTetris-Game Documentation



*/
