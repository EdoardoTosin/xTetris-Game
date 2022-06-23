#include <stdio.h>
#include <wchar.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"
#include "manageStruct.h"
#include "printGame.h"


int clearFullRows(BoardPtr board){

	int i, j, totPoints, consecutive, row, points;
	int fullRow[HEIGHT];

	for(i=HEIGHT-1, row=1; i>=0; i--){
		row = 1;
		fullRow[i] = 0;
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status==EMPTY_BOX){
				j = WIDTH;
				row = 0;
			}
		}
		if(row!=0){
			fullRow[i] = 1;
		}
	}

	for(i=0, consecutive=0, totPoints=0; i<HEIGHT; i++){
		if(fullRow[i]!=0){
			consecutive++;
			if((i+1<HEIGHT && fullRow[i+1]==0) || i==HEIGHT-1){
				points=1;
				if(consecutive>1)
					for(j=2, points=3; j<consecutive; j++)
						points *= 2;
				totPoints += points;
				consecutive = 0;
			}
		}
	}

	for(i=HEIGHT-1, row = HEIGHT-1; i>=0; i--, row--){
		while(fullRow[row]!=0 && row>=0){
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

int validRotation(BoardPtr board, TetrominoPtr tetro, int piece, int rotation, int row, int col){

	int i, j, k, l;

	for(i=row, k=0; k<TETRO_DIM; i++, k++){
		for(j=col, l=0; l<TETRO_DIM; j++, l++){
			if(i>0 && i<WIDTH && j>0 && j<HEIGHT){
				if(board[i][j].status>TETRO_BOX && tetro[piece][rotation][k][l].status==TETRO_BOX){
					return INVALID;
				}
			}
			else if(i<=0 || i>=WIDTH || j<0 || j>=HEIGHT){
				if(tetro[piece][rotation][k][l].status==TETRO_BOX){
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
			else if(board[i][j].status==TETRO_BOX && board[i][j+move].status>TETRO_BOX)
				return INVALID;
		}
	}

	return VALID;
}

void landedTetro(BoardPtr board){
	
	int i, j;

	for(i=0; i<HEIGHT; i++)
		for(j=0; j<WIDTH; j++)
			if(board[i][j].status==TETRO_BOX)
				board[i][j].status = BOARD_BOX;
}

int validFall(BoardPtr board){

	int i, j;

	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status==TETRO_BOX && i+1>=HEIGHT)
				return INVALID;
			if(board[i][j].status==TETRO_BOX && board[i+1][j].status>TETRO_BOX)
				return INVALID;
		}
	}

	return VALID;
}

void addTetromino(BoardPtr board, TetrominoPtr tetro, int shape, int rotation){
	int i, j, l;
	int x = -1;
	for(i=0; i<TETRO_DIM; i++){
		for(j=0; j<TETRO_DIM; j++){
			if(x==-1 && tetro[shape][rotation][i][j].status==TETRO_BOX)
				x = i;
		}
	}
	for(i=0; x<TETRO_DIM; x++, i++){
		for(j=WIDTH/2-TETRO_DIM/2, l=0; l<TETRO_DIM; j++, l++){
			if(tetro[shape][rotation][x][l].status==TETRO_BOX)
				board[i][j].status = TETRO_BOX;
		}
	}
}

int playerTurn(BoardPtr board, TetrominoPtr tetro){
	return;
}

void startGame(int mode){

	int i, j;

	int points_1=0;
	int points_2=0;

	BoardPtr board_1, board_2;
 	TetrominoPtr tetro;

	board_1 = initializeBoard();
	board_2 = initializeBoard();
	tetro = initializeTetrominoes();

	printBoard(board_1, board_2, mode);

	printTetrominoes(tetro);

	addTetromino(board_1, tetro, 0, 3);

	printBoard(board_1, board_2, mode);

	addTetromino(board_2, tetro, 0, 2);

	printBoard(board_1, board_2, mode);

	for(i=HEIGHT-1; i>=HEIGHT-7; i--){
		if(i==HEIGHT-1 || i<HEIGHT-3)
			for(j=0; j<WIDTH; j++)
				board_2[i][j].status = BOARD_BOX;
	}

	printBoard(board_1, board_2, mode);

	points_2 += clearFullRows(board_2);

	wprintf(L"%d\r\n", points_2);

	waitDebug();

	printBoard(board_1, board_2, mode);

	destroyBoard(board_1);
	destroyBoard(board_2);
	destroyTetrominoes(tetro);

}