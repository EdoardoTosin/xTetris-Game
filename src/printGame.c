#include <stdio.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"

wchar_t eSq = 0x2B1C; // emptySquare
wchar_t fSq = 0x2B1B; // fullSquare

void printIntro(void){
  system(CLEAR);
  wprintf(L"\n");
  wprintf(L"\n");
  wprintf(L"           _|_|_|_|_|            _|                _|\n");
  wprintf(L" _|    _|      _|      _|_|    _|_|_|_|  _|  _|_|        _|_|_|\n");
  wprintf(L"   _|_|        _|    _|_|_|_|    _|      _|_|      _|  _|_|\n");
  wprintf(L" _|    _|      _|    _|          _|      _|        _|      _|_|\n");
  wprintf(L" _|    _|      _|      _|_|_|      _|_|  _|        _|  _|_|_|\n");
  wprintf(L"\n");
  wprintf(L"\n");
  delayTimer(2);
}

void printEmptyBoard(void){
  //system(CLEAR);
  //setlocale(LC_CTYPE, "");
  int i, j;
  for (i=0; i<HEIGHT+1; i++){
    if (i<HEIGHT){
      for (j=0; j<WIDTH+2; j++){
        if (j==0 || j==WIDTH+1)
          wprintf(L"%lc", fSq);
        else
          wprintf(L"%lc", eSq);
      }
      wprintf(L"\n");
    }
    else{
      for (j=0; j<WIDTH+2; j++)
        wprintf(L"%lc", fSq);
    }
  }
  wprintf(L"\n");
  wprintf(L"\nTest success.\n");
}
