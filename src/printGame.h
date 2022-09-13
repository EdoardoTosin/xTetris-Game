#ifndef PRINTGAME_H
#define PRINTGAME_H


#include <wchar.h>

#include "struct.h"


/*!
   \brief Print spaces between the two boards.
*/
void printSpacing();

/*!
   \brief Print players' name.
   @param[in] points_1 Points value of player 1.
   @param[in] points_2 Points value of player 2 ( or bot, depending on match mode).
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void printPlayersName(int points_1, int points_2, int mode);

/*!
   \brief Print the game with object in the terminal.
   @param[in] mat_1 Pointer of struct board of player 1.
   @param[in] mat_2 Pointer of struct board of player 2.
   @param[in] points_1 Points value of player 1.
   @param[in] points_2 Points value of player 2 ( or bot, depending on match mode).
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void printBoard(BoardPtr mat_1, BoardPtr mat_2, int points_1, int points_2, int mode);

/*!
   \brief Print end screen result.
   @param[in] points_1 Points value of player 1.
   @param[in] points_2 Points value of player 2 ( or bot, depending on match mode).
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void gameOver(int points_1, int points_2, int mode);

/*!
   \brief Print all tetrominoes shapes.
   @param[in] parts Struct containing all possible tetrominoes' shapes.
*/
void printTetrominoes(TetrominoPtr parts);


#endif
