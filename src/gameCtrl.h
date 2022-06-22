#ifndef GAMECTRL_H
#define GAMECTRL_H

#include "struct.h"
/*!
   \brief Change tetromino position as moved by  the player.
   @param[in] board Player board that needs to be checked if rows are full and clear them.
*/
int clearFullRows(BoardPtr board);

/*!
   \brief Change tetromino position as moved by  the player.
   @param[in] board Player board where the move needs to be verified.
   @param[in] moveSpec Struct where all  details of current move are stored.
*/
void makeMove(BoardPtr board, MovePtr moveSpec);

/*!
   \brief Check if the tetromino rotation is valid.
   @param[in] board Player board to check if tetromino fully entered it.
   @param[in] tetro Store all tetrominoes possibible shapes.
   @param[in] piece Type of tetromino piece that need the rotation check.
   @param[in] rotation Value between 0 and 3 that correspond to a certain tetromino rotation.
   @param[in] row Starting row coordinate of tetromino matrix.
   @param[in] col Starting column coordinate of tetromino matrix.
*/
int tetroIsInsideBoard(BoardPtr, TetrominoPtr tetro, int piece, int rotation, int row, int col);

/*!
   \brief Check if the tetromino rotation is valid.
   @param[in] board Player board where the move needs to be verified.
   @param[in] tetro Store all tetrominoes possibible shapes.
   @param[in] piece Type of tetromino piece that need the rotation check.
   @param[in] rotation Value between 0 and 3 that correspond to a certain tetromino rotation.
   @param[in] row Starting row coordinate of tetromino matrix.
   @param[in] col Starting column coordinate of tetromino matrix.
*/
int validRotation(BoardPtr board, TetrominoPtr tetro, int piece, int rotation, int row, int col);

/*!
   \brief Check if a move of the tetromino is valid.
   @param[in] board Player board where the move needs to be verified.
   @param[in] move Direction (left -1, right 1) where the tetromino is moved.
*/
int validMove(BoardPtr board, int move);

/*!
   \brief Convert landed Tetromino value into a new one.
   @param[in] board Player board where the tetromino landed.
*/
void landingTetro(BoardPtr board);

/*!
   \brief Check if tetromino has landed or still falling.
   @param[in] board Player board where the tetromino is falling.
*/
int validFall(BoardPtr board);

/*!
   \brief Start the gameplay.
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void startGame(int mode);

#endif
