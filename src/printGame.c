#include <stdio.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "initBoard.h"
#include "struct.h"

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
  delayTimer(2);
}

void printBoard(void){
  //system(CLEAR);
  int i, j;
  for (i=0; i<HEIGHT+2; i++){
    if (i>0 && i<HEIGHT+1){
      for (j=0; j<WIDTH+2; j++){
        if (j==0 || j==WIDTH+1)
          wprintf(L"%lc", fSq);
        else
          wprintf(L"%lc", eSq);
      }
    }
    else{
      for (j=0; j<WIDTH+2; j++)
        wprintf(L"%lc", fSq);
    }
    wprintf(L"\n");
  }
}
