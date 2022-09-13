#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "manageStruct.h"
#include "common.h"
#include "definitions.h"
#include "struct.h"

BoardPtr initializeBoard(void) {

  int i, j;

  BoardPtr mat = (struct Cell **) malloc(HEIGHT * sizeof(struct Cell *));
  
  if(mat == NULL) {
    wprintf(L"Error! memory not allocated.\n");
    exit(EXIT_FAILURE);
  }
  
  for (i = 0; i < HEIGHT; i++) {
    mat[i] = (struct Cell *) malloc(WIDTH * sizeof(struct Cell));
    if(mat[i] == NULL) {
      wprintf(L"Error! memory not allocated.\n");
      exit(EXIT_FAILURE);
    }
    for (j = 0; j < WIDTH; j++)
      mat[i][j].status = EMPTY_BOX;
  }
  
  return mat;
}

void destroyBoard(BoardPtr board){

  int i;

  for(i=0; i < HEIGHT; i++){
    free(board[i]);
  }
  
  free(board);
}


MovePtr initializeMove(void){
  
  MovePtr storeMove = (struct Move *) malloc(sizeof(struct Move));
  
  if(storeMove == NULL) {
      wprintf(L"Error! memory not allocated.\n");
      exit(EXIT_FAILURE);
  }
  
  return storeMove;
}

void destroyMove(MovePtr storeMove){
  free(storeMove);
}


TetrominoPtr initializeTetrominoes(void){

  int i, j, k, l;


  TetrominoPtr parts = (struct TetrominoCell ****) malloc(N_PIECES * sizeof(struct TetrominoCell ***));
  
  if(parts == NULL) {
      wprintf(L"Error! memory not allocated.\n");
      exit(EXIT_FAILURE);
  }
  for(i=0; i < N_PIECES; i++){
    parts[i] = (struct TetrominoCell ***) malloc(TETRO_ROT * sizeof(struct TetrominoCell **));
    if(parts[i] == NULL) {
      wprintf(L"Error! memory not allocated.\n");
      exit(EXIT_FAILURE);
    }
    for(j=0; j < TETRO_ROT; j++){
      parts[i][j] = (struct TetrominoCell **) malloc(TETRO_DIM * sizeof(struct TetrominoCell *));
      if(parts[i][j] == NULL) {
        wprintf(L"Error! memory not allocated.\n");
        exit(EXIT_FAILURE);
      }
      for(k=0; k < TETRO_DIM; k++){
        parts[i][j][k] = (struct TetrominoCell *) malloc(TETRO_DIM * sizeof(struct TetrominoCell));
        if(parts[i][j][k] == NULL) {
          wprintf(L"Error! memory not allocated.\n");
          exit(EXIT_FAILURE);
        }
        for(l=0; l < TETRO_DIM; l++){
          parts[i][j][k][l].status = EMPTY_BOX;
        }
      }
    }
  }

  /* I SHAPE */
  for (i=0; i<TETRO_DIM-1; i++){
    parts[0][0][i][2].status = TETRO_BOX;
    parts[0][1][2][i].status = TETRO_BOX;
    parts[0][2][i][2].status = TETRO_BOX;
    parts[0][3][2][i].status = TETRO_BOX;
  }

  /* J SHAPE */
  for (i=1; i<TETRO_DIM-1; i++){
    parts[1][0][2][i].status = TETRO_BOX;
    parts[1][1][i][2].status = TETRO_BOX;
    parts[1][2][2][i].status = TETRO_BOX;
    parts[1][3][i][2].status = TETRO_BOX;
  }
  parts[1][0][1][1].status = TETRO_BOX;
  parts[1][1][1][3].status = TETRO_BOX;
  parts[1][2][3][3].status = TETRO_BOX;
  parts[1][3][3][1].status = TETRO_BOX;

  /* L SHAPE */
  for (i=1; i<TETRO_DIM-1; i++){
    parts[2][0][2][i].status = TETRO_BOX;
    parts[2][1][i][2].status = TETRO_BOX;
    parts[2][2][2][i].status = TETRO_BOX;
    parts[2][3][i][2].status = TETRO_BOX;
  }
  parts[2][0][1][3].status = TETRO_BOX;
  parts[2][1][3][3].status = TETRO_BOX;
  parts[2][2][3][1].status = TETRO_BOX;
  parts[2][3][1][1].status = TETRO_BOX;

  /* O SHAPE */
  for (i=0; i<TETRO_ROT; i++){
    for (j=1; j<TETRO_DIM-2; j++){
      for (k=1; k<TETRO_DIM-2; k++){
        parts[3][i][j][k].status = TETRO_BOX;
      }
    }
  }

  /* S SHAPE */
  for (j=1; j<TETRO_DIM-2; j++){
    for (k=1; k<TETRO_DIM-1; k++){
      if(!((j==1 && k==1) || (j==2 && k==3))){
        parts[4][0][j][k].status = TETRO_BOX;
        parts[4][2][j][k].status = TETRO_BOX;
      }
    }
  }
  for (j=1; j<TETRO_DIM-1; j++){
    for (k=1; k<TETRO_DIM-2; k++){
      if(!((j==1 && k==2) || (j==3 && k==1))){
        parts[4][1][j][k].status = TETRO_BOX;
        parts[4][3][j][k].status = TETRO_BOX;
      }
    }
  }

  /* T SHAPE */
  for (i=1; i<TETRO_DIM-1; i++){
    parts[5][0][2][i].status = TETRO_BOX;
    parts[5][1][i][2].status = TETRO_BOX;
    parts[5][2][2][i].status = TETRO_BOX;
    parts[5][3][i][2].status = TETRO_BOX;
  }
  parts[5][0][1][2].status = TETRO_BOX;
  parts[5][1][2][3].status = TETRO_BOX;
  parts[5][2][3][2].status = TETRO_BOX;
  parts[5][3][2][1].status = TETRO_BOX;

  /* Z SHAPE */
  for (j=1; j<TETRO_DIM-2; j++){
    for (k=1; k<TETRO_DIM-1; k++){
      if(!((j==2 && k==1) || (j==1 && k==3))){
        parts[6][0][j][k].status = TETRO_BOX;
        parts[6][2][j][k].status = TETRO_BOX;
      }
    }
  }
  for (j=1; j<TETRO_DIM-1; j++){
    for (k=1; k<TETRO_DIM-2; k++){
      if(!((j==1 && k==1) || (j==3 && k==2))){
        parts[6][1][j][k].status = TETRO_BOX;
        parts[6][3][j][k].status = TETRO_BOX;
      }
    }
  }

  return parts;
}

void destroyTetromino(TetrominoPtr parts){

  int i, j, k;

  for(i=0; i < N_PIECES; i++){
    for(j=0; j < TETRO_ROT; j++){
      for(k=0; k < TETRO_DIM; k++){
        free(parts[i][j][k]);
      }
      free(parts[i][j]);
    }
    free(parts[i]);
  }
  free(parts);
}
