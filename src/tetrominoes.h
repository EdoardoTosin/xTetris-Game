#ifndef TETROMINOES_H
#define TETROMINOES_H

#include "struct.h"

/* Rappresentazione di un tetramino */
struct s_tetromino {
	int container[4][4];
	int exists;
};
typedef struct s_tetromino* t_tetromino;

#endif
