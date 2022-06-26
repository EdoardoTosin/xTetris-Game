#ifndef GAMECTRL_H
#define GAMECTRL_H

#include <time.h>
#include "struct.h"

/*!
   \brief Generate random number given a range.
   @param[in] min Minimum number of range (inclusive).
   @param[in] max Maximum number of range (inclusive).
*/
int randGen(int min, int max);

/*!
   \brief Change tetromino position as moved by  the player.
   @param[in] board Player board that needs to be checked if rows are full and clear them.
*/
int clearFullRows(BoardPtr board);

/*!
   \brief Change tetromino position as moved by  the player.
   @param[in] board Player board where the move needs to be verified.
   @param[in] tetro Store all tetrominoes possibible shapes.
   @param[in] storeMove Struct where all  details of current move are stored.
*/
void makeMove(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove);

/*!
   \brief Check if the tetromino rotation is valid.
   @param[in] board Player board where the move needs to be verified.
   @param[in] tetro Store all tetrominoes possibible shapes.
   @param[in] storeMove Struct where all details of current move to make are store.
   @param[in] direction Value of rotation, -1 for 90° counterclockwise, 1 for 90° clockwise.
   @param[out] rotation If valid return 1, otherwise 0.
*/
int validRotation(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove, int direction);

/*!
   \brief Check if a move of the tetromino is valid.
   @param[in] board Player board where the move needs to be verified.
   @param[in] storeMove Struct where all  details of current move are stored.
   @param[in] move Direction (left -1, right 1) where the tetromino is moved.
   @param[out] move If valid 1, otherwise 0.
*/
int validMove(BoardPtr board, MovePtr storeMove, int move);

/*!
   \brief Check if tetromino has landed or will move it one step down.
   @param[in] board Player board where the tetromino is falling or landed.
   @param[in] storeMove Struct where all  details of current move are stored.
   @param[out] fall If not moved the value is 0, otherwise 1.
*/
int fallingTetromino(BoardPtr board, MovePtr storeMove);

/*!
   \brief Drop a tetromino into the board.
   @param[in] board Player board where the tetromino needs to be dropped.
   @param[in] tetro Store all tetrominoes possibible shapes.
   @param[in] storeMove Struct where all  details of current move are stored.
   @param[out] complete Return a number based on tetromino addition (0 if it was added, 1 otherwise).
*/
int addTetromino(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove);

/*!
   \brief Start the gameplay.
   @param[in] mode Singleplayer or Multiplayer (0 or 1).
*/
void startGame(int mode);

#endif
