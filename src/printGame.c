#include <stdio.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"

void printSpacing(){
  int i;
  for (i=0; i<SPACING; i++)
    wprintf(L" ");
}

void printPlayersName(wchar_t **pl1, wchar_t **pl2){
  int i, length;
  wprintf(L"%ls", *pl1);
  length = wcslen(*pl1);
  for (i=0; i<12*2-length; i++)
    wprintf(L" ");
  printSpacing();
  wprintf(L"%ls", *pl2);
  wprintf(L"\r\n");
}

void printBoard(BoardPtr mat_1, BoardPtr mat_2, wchar_t **pl1, wchar_t **pl2){
  int i, j, k;

  clearCLI();

  for (i=0; i<HEIGHT+2; i++){
    if (i==0 || i==HEIGHT+1){
      if (i==0)
        printPlayersName(pl1, pl2);
      for (k=0; k<2; k++){
        for (j=0; j<WIDTH+2; j++)
          wprintf(L"%lc", fSq);
        printSpacing();
      }
      wprintf(L"\r\n");
    }
    else{
      for (j=0; j<WIDTH+2; j++){
        if (j==0 || j==WIDTH+1){
          wprintf(L"%lc", fSq);
          if (j==WIDTH+1)
            printSpacing();
        }
        else
          wprintf(L"%lc", mat_1[15-i][10-j].status);
      }
      for (j=0; j<WIDTH+2; j++){
        if (j==0 || j==WIDTH+1){
          wprintf(L"%lc", fSq);
        }
        else
          wprintf(L"%lc", mat_2[15-i][10-j].status);
      }
      wprintf(L"\r\n");
    }
  }
}
