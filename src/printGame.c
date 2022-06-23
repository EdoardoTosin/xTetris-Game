#include <stdio.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"

void waitDebug(){
  int key=0;
  while(key!=CARRIAGE_RETURN){
    key = waitUserInput();
  }
}

void printSpacing(){
  
  int i;

  for (i=0; i<SPACING; i++)
    wprintf(L" ");
}

void printPlayersName(int mode){

  int i, length;

  wprintf(PL1);
  length = wcslen(PL1);
  for (i=0; i<12*2-length; i++)
    wprintf(L" ");
  printSpacing();
  if (mode==MULTIPLAYER)
    wprintf(L"Player 2");
  else
    wprintf(L"Bot");
  wprintf(L"\r\n");
}

void printBoard(BoardPtr mat_1, BoardPtr mat_2, int mode){

  int i, j, k;

  clearCLI();

  for (i=0; i<HEIGHT+2; i++){
    if (i==0 || i==HEIGHT+1){
      if (i==0)
        printPlayersName(mode);
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
        else if (mat_1[i-1][j-1].status>EMPTY_BOX)
          wprintf(L"%lc", fSq);
        else
          wprintf(L"%lc", eSq);
      }
      for (j=0; j<WIDTH+2; j++){
        if (j==0 || j==WIDTH+1)
          wprintf(L"%lc", fSq);
        else if (mat_2[i-1][j-1].status>EMPTY_BOX)
          wprintf(L"%lc", fSq);
        else
          wprintf(L"%lc", eSq);
      }
      wprintf(L"\r\n");
    }
  }
  waitDebug();
}


void printTetrominoes(TetrominoPtr parts){

  int i, j, k, l;

  clearCLI();

  for(i=0; i<N_PIECES; i++){
    wprintf(L"Piece: %d\r\n", i);
    for(j=0; j<TETRO_ROT; j++){
      wprintf(L"Rotation: %d\r\n", j);
      for(k=0; k<TETRO_DIM; k++){
        for(l=0; l<TETRO_DIM; l++){
          if (parts[i][j][k][l].status>EMPTY_BOX)
            wprintf(L"%lc", fSq);
          else
            wprintf(L"%lc", eSq);
        }
        wprintf(L"\r\n");
      }
      wprintf(L"\r\n");
    }
    wprintf(L"\r\n");
  }
  waitDebug();
}