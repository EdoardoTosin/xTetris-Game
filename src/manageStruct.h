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
   \brief Allocate memory for MovePtr struct.
   @param[out] storeMove Struct that contains all the info about a single move (coordinates, shape and rotation).
*/
MovePtr initializeMove();

/*!
   \brief Free the MovePtr struct passed as parameter.
   @param[in] storeMove Struct that need to be freed.
*/
void destroyMove(MovePtr storeMove);


/*!
   \brief Allocate memory for TetraminoPtr struct.
   @param[out] parts Struct that contains all tetrominoes shapes with all possible rotations: [N_PIECES][TETRO_ROT][TETRO_DIM][TETRO_DIM].
*/
TetrominoPtr initializeTetrominoes();

/*!
   \brief Free the TetrominoPtr struct passed as parameter.
   @param[in] board Struct that need to be freed.
*/
void destroyTetromino(TetrominoPtr parts);


#endif
