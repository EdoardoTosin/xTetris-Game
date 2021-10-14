#include <stdio.h>
#include <wchar.h>
#include "common.h"

void printIntro(void){
  wprintf(L"======================\n");
  wprintf(L"        xTetris       \n");
  wprintf(L"======================\n");
  delayTimer(1);
}

void printBoard(void){
  //setlocale(LC_CTYPE, "");
  wchar_t emptySquare = 0x2B1C;
  wchar_t fullSquare = 0x2B1B;
  int i, j;
  for (i=0; i<12; i++){
    wprintf(L"%lc", fullSquare);
    for (j=0; j<10; j++){
      wprintf(L"%lc", emptySquare);
    }
    wprintf(L"%lc", fullSquare);
    wprintf(L"\n");
  }
  for (i=0; i<12; i++){
    wprintf(L"%lc", fullSquare);
  }
  wprintf(L"\n");
  wprintf(L"Test success.\n");
}
