#include <stdlib.h>

#include "struct.h"
#include "definitions.h"
#include "tetrominoes.h"

void fill(TetrominoPtr* t, int i, int j) {
  (t->container)[i][j] = 1;
}

void iniTetrominoPtr(TetrominoPtr* t) {
	int i, j;

	for (i = 0; i < TETROMINO_ROT; ++i) {
		for (j = 0; j < TETROMINO_ROT; ++j) {
			(t->container)[i][j] = 0;
    }
  }
}

void init_tetromat(TetrominoPtr tetromat[NPIECES][TETROMINO_ROT]) {
	int i, j;

	for (i = 0; i < NPIECES; ++i) {
		for (j = 0; j < TETROMINO_ROT; ++j) {
			iniTetrominoPtr(&(tetromat[i][j]));
			(tetromat[i][j])->exists = 0;
    }
  }

	(tetromat[0][0])->exists = 1;
	(tetromat[0][1])->exists = 1;
	(tetromat[0][2])->exists = 0;
	(tetromat[0][3])->exists = 0;

	(tetromat[1][0])->exists = 1;
	(tetromat[1][1])->exists = 1;
	(tetromat[1][2])->exists = 1;
	(tetromat[1][3])->exists = 1;

	(tetromat[2][0])->exists = 1;
	(tetromat[2][1])->exists = 1;
	(tetromat[2][2])->exists = 1;
	(tetromat[2][3])->exists = 1;

	(tetromat[3][0])->exists = 1;
	(tetromat[3][1])->exists = 0;
	(tetromat[3][2])->exists = 0;
	(tetromat[3][3])->exists = 0;

	(tetromat[4][0])->exists = 1;
	(tetromat[4][1])->exists = 1;
	(tetromat[4][2])->exists = 0;
	(tetromat[4][3])->exists = 0;

	(tetromat[5][0])->exists = 1;
	(tetromat[5][1])->exists = 1;
	(tetromat[5][2])->exists = 0;
	(tetromat[5][3])->exists = 0;

	(tetromat[6][0])->exists = 1;
	(tetromat[6][1])->exists = 1;
	(tetromat[6][2])->exists = 1;
	(tetromat[6][3])->exists = 1;

	fill(&(tetromat[0][0]), 3, 0);
	fill(&(tetromat[0][0]), 3, 1);
	fill(&(tetromat[0][0]), 3, 2);
	fill(&(tetromat[0][0]), 3, 3);

	fill(&(tetromat[0][1]), 0, 0);
	fill(&(tetromat[0][1]), 1, 0);
	fill(&(tetromat[0][1]), 2, 0);
	fill(&(tetromat[0][1]), 3, 0);

	fill(&(tetromat[1][0]), 2, 0);
	fill(&(tetromat[1][0]), 2, 1);
	fill(&(tetromat[1][0]), 2, 2);
	fill(&(tetromat[1][0]), 3, 2);

	fill(&(tetromat[1][1]), 1, 1);
	fill(&(tetromat[1][1]), 2, 1);
	fill(&(tetromat[1][1]), 3, 1);
	fill(&(tetromat[1][1]), 3, 0);

	fill(&(tetromat[1][2]), 1, 0);
	fill(&(tetromat[1][2]), 1, 1);
	fill(&(tetromat[1][2]), 2, 0);
	fill(&(tetromat[1][2]), 3, 0);

	fill(&(tetromat[1][3]), 2, 0);
	fill(&(tetromat[1][3]), 3, 0);
	fill(&(tetromat[1][3]), 3, 1);
	fill(&(tetromat[1][3]), 3, 2);

	fill(&(tetromat[2][0]), 2, 0);
	fill(&(tetromat[2][0]), 2, 1);
	fill(&(tetromat[2][0]), 2, 2);
	fill(&(tetromat[2][0]), 3, 0);

	fill(&(tetromat[2][1]), 1, 0);
	fill(&(tetromat[2][1]), 1, 1);
	fill(&(tetromat[2][1]), 2, 1);
	fill(&(tetromat[2][1]), 3, 1);

	fill(&(tetromat[2][2]), 2, 2);
	fill(&(tetromat[2][2]), 3, 0);
	fill(&(tetromat[2][2]), 3, 1);
	fill(&(tetromat[2][2]), 3, 2);

	fill(&(tetromat[2][3]), 1, 0);
	fill(&(tetromat[2][3]), 2, 0);
	fill(&(tetromat[2][3]), 3, 0);
	fill(&(tetromat[2][3]), 3, 1);

	fill(&(tetromat[3][0]), 2, 0);
	fill(&(tetromat[3][0]), 2, 1);
	fill(&(tetromat[3][0]), 3, 0);
	fill(&(tetromat[3][0]), 3, 1);

	fill(&(tetromat[4][0]), 2, 1);
	fill(&(tetromat[4][0]), 2, 2);
	fill(&(tetromat[4][0]), 3, 0);
	fill(&(tetromat[4][0]), 3, 1);

	fill(&(tetromat[4][1]), 1, 0);
	fill(&(tetromat[4][1]), 2, 0);
	fill(&(tetromat[4][1]), 2, 1);
	fill(&(tetromat[4][1]), 3, 1);

	fill(&(tetromat[5][0]), 2, 0);
	fill(&(tetromat[5][0]), 2, 1);
	fill(&(tetromat[5][0]), 3, 1);
	fill(&(tetromat[5][0]), 3, 2);

	fill(&(tetromat[5][1]), 1, 1);
	fill(&(tetromat[5][1]), 2, 0);
	fill(&(tetromat[5][1]), 2, 1);
	fill(&(tetromat[5][1]), 3, 0);

	fill(&(tetromat[6][0]), 2, 0);
	fill(&(tetromat[6][0]), 2, 1);
	fill(&(tetromat[6][0]), 2, 2);
	fill(&(tetromat[6][0]), 3, 1);

	fill(&(tetromat[6][1]), 1, 1);
	fill(&(tetromat[6][1]), 2, 0);
	fill(&(tetromat[6][1]), 2, 1);
	fill(&(tetromat[6][1]), 3, 1);

	fill(&(tetromat[6][2]), 2, 1);
	fill(&(tetromat[6][2]), 3, 0);
	fill(&(tetromat[6][2]), 3, 1);
	fill(&(tetromat[6][2]), 3, 2);

	fill(&(tetromat[6][3]), 1, 0);
	fill(&(tetromat[6][3]), 2, 0);
	fill(&(tetromat[6][3]), 2, 1);
	fill(&(tetromat[6][3]), 3, 0);
}
