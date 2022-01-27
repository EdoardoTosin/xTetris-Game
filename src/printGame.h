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
   @param[in] pl1 Player 1 name.
   @param[in] pl2 Player 2 name.
*/
void printPlayersName(PlNamePtr pl1,PlNamePtr pl2);
/*!
   \brief Print the game with object in the terminal.
   @param[in] mat_1 Pointer of struct board of player 1.
   @param[in] mat_2 Pointer of struct board of player 2.
   @param[in] pl1 Player 1 name.
   @param[in] pl2 Player 2 name.
*/
void printBoard(BoardPtr mat_1, BoardPtr mat_2, PlNamePtr pl1, PlNamePtr pl2);

#endif
