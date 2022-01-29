#ifndef STRUCT_H
#define STRUCT_H

#include "definitions.h"

struct Cell {
  wchar_t status;
};
typedef struct Cell ** BoardPtr;

struct Position {
  int row;
  int col;
};
typedef struct Position * PositionPtr;

struct Move {
  PositionPtr startPos;
  PositionPtr endPos;
};
typedef struct Move * MovePtr;

struct NameTag {
  wchar_t *name;
};
typedef struct NameTag * PlNamePtr;

struct Piece {
  wchar_t status[TETROMINO_DIM][TETROMINO_DIM][TETROMINO_ROT];
};
typedef struct Piece * PiecePtr;

struct Tetrominoes {
  PiecePtr piece;
};
typedef struct Tetromino * TetrominoPtr;

#endif
