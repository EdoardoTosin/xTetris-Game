#ifndef STRUCT_H
#define STRUCT_H


struct Cell {
  int status;
};
typedef struct Cell ** BoardPtr;

struct Move {
  int piece;
  int rotation;
  int row;
  int col;
};
typedef struct Move * MovePtr;

struct TetrominoCell {
  int status;
};
typedef struct TetrominoCell **** TetrominoPtr;


#endif
