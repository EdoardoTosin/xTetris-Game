#ifndef TETROMINOES_H
#define TETROMINOES_H

#include <stdlib.h>

#include "struct.h"
#include "definitions.h"
#include "tetrominoes.h"

/*!
   \brief Fill a single cell inside tetromino matrix.
   @param[in] t Struct tetromino.
	 @param[in] i Row of the cell to fill.
	 @param[in] j Column of the cell to fill.
*/
void fillTetromino(TetrominoPtr* t, int i, int j);

/*!
   \brief Fill all tetromino matrix with zeros.
   @param[in] t Struct tetromino.
*/
void iniTetrominoPtr(TetrominoPtr* t);

/*!
   \brief Initialize and allocate all tetrominoes.
   @param[in] tetromat Struct tetromino.
*/
void init_tetromat(TetrominoPtr tetromat[NPIECES][TETROMINO_ROT]);

#endif
