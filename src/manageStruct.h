#ifndef MANAGESTRUCT_H
#define MANAGESTRUCT_H

#include "struct.h"

/*!
   \brief Allocate memory for BoardPtr struct.
   @param[out] mat Struct empty at the start for the tetriminos cells.
*/
BoardPtr initializeBoard();

/*!
   \brief Free the BoardPtr struct passed as parameter.
   @param[in] board Struct that need to be freed.
*/
void destroyBoard(BoardPtr board);

/*!
   \brief Allocate memory for TetraminoPtr struct.
   @param[out] parts Struct that contains all tetrominoes shapes with all possible rotations: [N_PIECES][TETRO_ROT][TETRO_DIM][TETRO_DIM].
*/
TetrominoPtr initializeTetrominoes();

/*!
   \brief Free the TetrominoPtr struct passed as parameter.
   @param[in] board Struct that need to be freed.
*/
void destroyTetrominoes(TetrominoPtr parts);

#endif
