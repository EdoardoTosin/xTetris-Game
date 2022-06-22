#include <stdio.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"
#include "manageStruct.h"
#include "printGame.h"

int clearFullRows(BoardPtr board){
	int i, j, points, count;
	int totPoints = 0;
	int consecutive = 1;
	int row = 1;
	int fullRow[HEIGHT];

	for(i=0; i<HEIGHT; i++){
		fullRow[i] = 0;
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status==EMPTY_BOX){
				row = 0;
				consecutive = 1;
			}
		}
		if(row>0){
			consecutive = consecutive * 2;
			fullRow[i] = 1;
		}
		totPoints += consecutive * row;
	}

	row = HEIGHT-1;
	for(i=HEIGHT-1; i>=0; i--){
		if(fullRow[row]==1){
			row--;
		}
		if (row!=i){
			for(j=0; j<WIDTH; j++){
				if(row>=0)
					board[i][j].status=board[row][j].status;
				else
					board[i][j].status=EMPTY_BOX;
			}
		}
	}

	return totPoints;
}

void makeMove(BoardPtr board, MovePtr moveSpec){
	return;
}

int tetroIsInsideBoard(BoardPtr board, TetrominoPtr tetro, int piece, int rotation, int row, int col){
	return 0;
}

int validRotation(BoardPtr board, TetrominoPtr tetro, int piece, int rotation, int row, int col){
	int i, j, k, l;

	for(i=row, k=0; k<TETRO_DIM; i++, k++){
		for(j=col, l=0; l<TETRO_DIM; j++, l++){
			if(i>0 && i<WIDTH && j>0 && j<HEIGHT){
				if(board[i][j].status==BOARD_BOX && tetro[piece][rotation][k][l].status==TETRO_BOX){
					return INVALID;
				}
			}
			else if(i>=WIDTH || j<0 || j>=HEIGHT){
				if(tetro[piece][rotation][k][l].statu==TETRO_BOX){
					return INVALID;
				}
			}
		}
	}

	return VALID;
}

int validMove(BoardPtr board, int move){

	int i, j;

	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status==TETRO_BOX && (j+move<0 || j+move>=WIDTH))
				return INVALID;
			else if(board[i][j].status==TETRO_BOX && board[i][j+move].status==BOARD_BOX)
				return INVALID;
		}
	}

	return VALID;
}

void landingTetro(BoardPtr){
	return;
}

int validFall(BoardPtr board){

	int i, j;

	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status==TETRO_BOX && i+1>=HEIGHT)
				return INVALID;
			if(board[i][j].status==TETRO_BOX && board[i+1][j].status==BOARD_BOX)
				return INVALID;
		}
	}

	return VALID;
}

void startGame(int mode){

	BoardPtr board_1, board_2;
 	TetrominoPtr tetro;

	board_1 = initializeBoard();
	board_2 = initializeBoard();
	tetro = initializeTetrominoes();

	printBoard(board_1, board_2, mode);

	destroyBoard(board_1);
	destroyBoard(board_2);
	destroyTetrominoes(tetro);

}