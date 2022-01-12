#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"

BoardPtr initialize() {
  int i, j;
  BoardPtr mat = (BoardPtr) malloc(HEIGHT * sizeof(struct Cell *));
    if(mat==NULL) {
      wprintf(L"Error! memory not allocated.\n");
      exit(EXIT_FAILURE);
    }
  for (i = 0; i < HEIGHT; i++) {
    mat[i] = (struct Cell * ) malloc(WIDTH * sizeof(struct Cell));
      if(mat[i]==NULL) {
        wprintf(L"Error! memory not allocated.\n");
        exit(EXIT_FAILURE);
      }
    for (j = 0; j < WIDTH; j++)
      mat[i][j].status = eSq;
  }
  return mat;
}
