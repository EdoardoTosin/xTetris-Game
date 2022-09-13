#include <stdio.h>
#include <wchar.h>

#include "printGame.h"
#include "common.h"
#include "definitions.h"
#include "struct.h"


void printSpacing(){
  
  int i;

  for (i=0; i<SPACING; i++)
    wprintf(L" ");
}

void printPlayersName(int points_1, int points_2, int mode){

  int i, length, n;
  
  n = intLen(points_1);
  
  wprintf(PLAYER_1);
  wprintf(L": %d", points_1);
  length = wcslen(PLAYER_1) + wcslen(L": ") + n;
  for (i=0; i<12*2-length; i++)
    wprintf(L" ");
  printSpacing();
  if (mode == MULTIPLAYER)
    wprintf(PLAYER_2);
  else
    wprintf(BOT);
  wprintf(L": %d", points_2);
  wprintf(L"\r\n");
}

void printBoard(BoardPtr mat_1, BoardPtr mat_2, int points_1, int points_2, int mode){

  int i, j, k;

  clearCLI();

  for (i=0; i<HEIGHT+2; i++){
    if (i==0 || i==HEIGHT+1){
      if (i==0)
        printPlayersName(points_1, points_2, mode);
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
        else if (mat_1[i-1][j-1].status > EMPTY_BOX)
          wprintf(L"%lc", fSq);
        else
          wprintf(L"%lc", eSq);
      }
      for (j=0; j<WIDTH+2; j++){
        if (j==0 || j==WIDTH+1)
          wprintf(L"%lc", fSq);
        else if (mat_2[i-1][j-1].status > EMPTY_BOX)
          wprintf(L"%lc", fSq);
        else
          wprintf(L"%lc", eSq);
      }
      wprintf(L"\r\n");
    }
  }
}

void gameOver(int points_1, int points_2, int mode){
  
  clearCLI();
	
	if(points_1 != points_2){
    
    heightSpacing(7);
	
    printCentered(L"WINNER:");
    
    wprintf(L"\r\n");
    
    if (points_1>points_2 && mode==SINGLEPLAYER)
      printCentered(PLAYER_1);
    else if (points_2>points_1 && mode==SINGLEPLAYER)
      printCentered(BOT);
    else if (points_1>points_2 && mode==MULTIPLAYER)
      printCentered(PLAYER_1);
    else if (points_2>points_1 && mode==MULTIPLAYER)
      printCentered(PLAYER_2);
	}
	else if(points_1 == points_2){
		heightSpacing(6);
    printCentered(L"TIE!!!");
	}
	
	wprintf(L"\r\n\r\n");
	
	printCentered(L"🕹 Press ENTER to continue...");
	
	waitUser();
	
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
}
