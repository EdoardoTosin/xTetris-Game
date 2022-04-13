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

struct Tetromino {
	int container[4][4];
	int exists;
};
typedef struct Tetromino* TetrominoPtr;

#endif
