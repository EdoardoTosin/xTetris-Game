#ifndef STRUCT_H
#define STRUCT_H

struct Cell {
  char status;
};
typedef struct Cell ** BoardPtr;

struct Position {
  int row;
  int col;
};
typedef struct Position * PositionPtr;

struct Move {
  int piece;
  int rotation;
  PositionPtr startPos;
  PositionPtr endPos;
};
typedef struct Move * MovePtr;

struct TetrominoCell {
  char status;
};
typedef struct TetrominoCell **** TetrominoPtr;

#endif
