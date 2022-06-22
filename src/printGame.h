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
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void printPlayersName(int mode);
/*!
   \brief Print the game with object in the terminal.
   @param[in] mat_1 Pointer of struct board of player 1.
   @param[in] mat_2 Pointer of struct board of player 2.
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void printBoard(BoardPtr mat_1, BoardPtr mat_2, int mode);

#endif
