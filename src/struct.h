#ifndef STRUCT_H
#define STRUCT_H

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

#endif
