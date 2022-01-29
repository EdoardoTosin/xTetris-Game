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
   \brief Allocate memory for PlNamePtr struct.
   @param[out] mat Struct empty at the start for the tetriminos cells.
*/
PlNamePtr initializePlName();

/*!
   \brief Free the PlNamePtr struct passed as parameter.
   @param[in] playerName Struct that need to be freed.
*/
void destroyPlName(PlNamePtr playerName);
/*
TetrominoPtr initializeTetrominoes();
*/
#endif
