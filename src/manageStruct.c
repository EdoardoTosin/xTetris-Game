#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"

BoardPtr initializeBoard() {
  int i, j;
  BoardPtr mat = (BoardPtr) malloc(HEIGHT * sizeof(struct Cell *));
    if(mat==NULL) {
      wprintf(L"Error! memory not allocated.\n");
      exit(EXIT_FAILURE);
    }
  for (i = 0; i < HEIGHT; i++) {
    mat[i] = (struct Cell *) malloc(WIDTH * sizeof(struct Cell));
      if(mat[i]==NULL) {
        wprintf(L"Error! memory not allocated.\n");
        exit(EXIT_FAILURE);
      }
    for (j = 0; j < WIDTH; j++)
      mat[i][j].status = eSq;
  }
  return mat;
}

void destroyBoard(BoardPtr board){
  int i;
  for(i=0; i<HEIGHT; i++){
    free(board[i]);
  }
  free(board);
}

PlNamePtr initializePlName(){
  PlNamePtr playerName = (PlNamePtr) malloc(sizeof(wchar_t *));
  (*playerName).name = (wchar_t *) malloc(sizeof(wchar_t)*10);
  return playerName;
}

void destroyPlName(PlNamePtr playerName){
  free(playerName->name);
  free(playerName);
}
