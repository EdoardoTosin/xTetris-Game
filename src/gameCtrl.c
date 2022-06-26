#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "definitions.h"
#include "struct.h"
#include "manageStruct.h"
#include "printGame.h"


int randGen(int min, int max){

	unsigned long partSize, endOfLastPart, range, r;
	
	range = max - min + 1;

	partSize = ((unsigned long)RAND_MAX + 1) / range; 
	endOfLastPart = partSize * range;

	r = rand();
	while(r>=endOfLastPart){
	    r = rand();
	}

	return min + r / partSize;
}

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

void makeMove(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove){
	
	int i, j, k, l, piece, rotation;
	
	piece = storeMove->piece;
	rotation = storeMove->rotation;
	
	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status == TETRO_BOX)
				board[i][j].status = EMPTY_BOX;
		}
	}
	
	for(i=(storeMove->row), l=0; l<TETRO_DIM; i++, l++){
		for(j=(storeMove->col), k=0; k<TETRO_DIM; j++, k++){
			if(tetro[piece][rotation][l][k].status == TETRO_BOX)
				board[i][j].status = TETRO_BOX;
		}
	}
	
}

int validRotation(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove, int direction){

	int i, j, k, l;
	int piece, rotation;
	
	rotation = storeMove->rotation + direction;
	if(rotation<0 || rotation>3){
		rotation = rotation - (direction) * 3;
	}
	
	piece = storeMove->piece;

	for(i=storeMove->row, k=0; k<TETRO_DIM; i++, k++){
		for(j=storeMove->col, l=0; l<TETRO_DIM; j++, l++){
			if(i>0 && i<WIDTH && j>0 && j<HEIGHT && board[i][j].status>TETRO_BOX && tetro[piece][rotation][k][l].status==TETRO_BOX){
				return INVALID;
			}
			else if((i<=0 || i>=WIDTH || j<0 || j>=HEIGHT) && tetro[piece][rotation][k][l].status==TETRO_BOX){
				return INVALID; /* i<=0 evaluation ?? */
			}
		}
	}
	
	storeMove->rotation = rotation;
	
	return VALID;
}

int validMove(BoardPtr board, MovePtr storeMove, int move){

	int i, j;

	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(board[i][j].status==TETRO_BOX && (j+move<0 || j+move>=WIDTH))
				return INVALID;
			else if(board[i][j].status==TETRO_BOX && board[i][j+move].status>TETRO_BOX)
				return INVALID;
		}
	}
	
	storeMove->col += move;
	
	return VALID;
}

int fallingTetromino(BoardPtr board, MovePtr storeMove){

	int i, j;
	int fall;

	for(i=0, fall=VALID; i<HEIGHT; i++){
		for(j=0; j<WIDTH && fall==VALID; j++){
			if(board[i][j].status==TETRO_BOX && i+1>=HEIGHT){
				fall = INVALID;
			}
			else if(board[i][j].status==TETRO_BOX && board[i+1][j].status>TETRO_BOX){
				fall = INVALID;
			}
		}
	}

	if(fall==VALID){
		for(i=HEIGHT-1; i>=0; i--){
			for(j=0; j<WIDTH; j++){
				if(board[i][j].status==TETRO_BOX){
					board[i+1][j].status = TETRO_BOX;
					board[i][j].status = EMPTY_BOX;
				}
			}
		}
		(storeMove->row)++;
	}
	else{
		for(i=0; i<HEIGHT; i++){
			for(j=0; j<WIDTH; j++){
				if(board[i][j].status==TETRO_BOX){
					board[i][j].status = BOARD_BOX;
				}
			}
		}
	}

	return fall;
}

int addTetromino(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove){
	
	int i, j, l, y;
	int shape, rotation, row, col;
	
	storeMove->piece = randGen(0, N_PIECES-1);
	storeMove->rotation = randGen(0, TETRO_ROT-1);
	
	col = WIDTH/2 - TETRO_DIM/2;
	
	shape = storeMove->piece;
	rotation = storeMove->rotation;
	
	for(i=0, row=-1; i<TETRO_DIM; i++){
		for(j=0; j<TETRO_DIM; j++){
			if(row==-1 && tetro[shape][rotation][i][j].status==TETRO_BOX)
				row = i;
		}
	}
	for(i=0, y = row; y<TETRO_DIM; y++, i++){
		for(j=col, l=0; l<TETRO_DIM; j++, l++){
			if(tetro[shape][rotation][y][l].status==TETRO_BOX && board[i][j].status==BOARD_BOX)
				return 1;
		}
	}
	for(i=0, y = row; y<TETRO_DIM; y++, i++){
		for(j=col, l=0; l<TETRO_DIM; j++, l++){
			if(tetro[shape][rotation][y][l].status==TETRO_BOX)
				board[i][j].status = TETRO_BOX;
		}
	}
	
	storeMove->row = row;
	storeMove->col = col;
	
	return 0;
}

void startGame(int mode){

	int skip, prevPoints, fall, move, complete;
	
	int key = RESET;
	int points_1 = 0;
	int points_2 = 0;

	clock_t start, timeDiff;

	BoardPtr board_1, board_2;
	MovePtr storeMove;
	TetrominoPtr tetro;

	board_1 = initializeBoard();
	board_2 = initializeBoard();
	storeMove = initializeMove();
	tetro = initializeTetrominoes();

	prevPoints = 0;
	fall = 0;
	move = 1;
	complete = 0;
	prevPoints = 0;
	while(complete==0){
		if(fall==0){
			complete = addTetromino(board_1, tetro, storeMove);
			move = 1;
		}
		if (complete==0){
			fall = 1;
			skip = 0;
			start = clock();
			do{
				if(move==1){
					printBoard(board_1, board_2, points_1, points_2, mode);
					move = 0;
				}
				if(u_kbhit()){
					key=u_getchar();
					if(key==LOWER_W || key==UPPER_W){
						move = validRotation(board_1, tetro, storeMove, -1);
						if (move==1){
							makeMove(board_1, tetro, storeMove);
						}
					}
					else if(key==LOWER_S || key==UPPER_S){
						move = validRotation(board_1, tetro, storeMove, 1);
						if (move==1){
							makeMove(board_1, tetro, storeMove);
						}
					}
					else if(key==LOWER_A || key==UPPER_A){
						move = validMove(board_1, storeMove, -1);
						if (move==1){
							makeMove(board_1, tetro, storeMove);
						}
					}
					else if(key==LOWER_D || key==UPPER_D){
						move = validMove(board_1, storeMove, 1);
						if (move==1){
							makeMove(board_1, tetro, storeMove);
						}
					}
					else if(key==SPACEBAR){
						move = 1;
						skip = 1;
					}
					else if(key==CTRL_C)
						exitFailure();
					nanosleep(&request, &remaining);
				}
				timeDiff = (clock()-start)*1000/CLOCKS_PER_SEC;
			}
			while(timeDiff<timeLimit && skip==0);
			fall = fallingTetromino(board_1, storeMove);
			printBoard(board_1, board_2, points_1, points_2, mode);
			if(fall==0){
				prevPoints = points_1;
				points_1 += clearFullRows(board_1);
				if (points_1 != prevPoints){
					printBoard(board_1, board_2, points_1, points_2, mode);
					move = 1;
				}
			}
		}
	}
	

	if(mode == MULTIPLAYER){
		clearCLI();
		heightSpacing(1);
		printCentered(L"🕹 Press ENTER to continue with second player...");
		waitUser();
		prevPoints = 0;
		fall = 0;
		move = 1;
		complete = 0;
		prevPoints = 0;
		while(complete==0){
			if(fall==0){
				complete = addTetromino(board_2, tetro, storeMove);
				move = 1;
			}
			if (complete==0){
				fall = 1;
				skip = 0;
				start = clock();
				do{
					if(move==1){
						printBoard(board_1, board_2, points_1, points_2, mode);
						move = 0;
					}
					if(u_kbhit()){
						key=u_getchar();
						if(key==LOWER_W || key==UPPER_W){
							move = validRotation(board_2, tetro, storeMove, -1);
							if (move==1){
								makeMove(board_2, tetro, storeMove);
							}
						}
						else if(key==LOWER_S || key==UPPER_S){
							move = validRotation(board_2, tetro, storeMove, 1);
							if (move==1){
								makeMove(board_2, tetro, storeMove);
							}
						}
						else if(key==LOWER_A || key==UPPER_A){
							move = validMove(board_2, storeMove, -1);
							if (move==1){
								makeMove(board_2, tetro, storeMove);
							}
						}
						else if(key==LOWER_D || key==UPPER_D){
							move = validMove(board_2, storeMove, 1);
							if (move==1){
								makeMove(board_2, tetro, storeMove);
							}
						}
						else if(key==SPACEBAR){
							move = 1;
							skip = 1;
						}
						else if(key==CTRL_C)
							exitFailure();
						nanosleep(&request, &remaining);
					}
					timeDiff = (clock()-start)*1000/CLOCKS_PER_SEC;
				}
				while(timeDiff<timeLimit && skip==0);
				fall = fallingTetromino(board_2, storeMove);
				printBoard(board_1, board_2, points_1, points_2, mode);
				if(fall==0){
					prevPoints = points_2;
					points_2 += clearFullRows(board_2);
					if (points_2 != prevPoints){
						printBoard(board_1, board_2, points_1, points_2, mode);
						move = 1;
					}
				}
			}
		}
	}
	
	gameOver(points_1, points_2, mode);

	destroyBoard(board_1);
	destroyBoard(board_2);
	destroyMove(storeMove);
	destroyTetromino(tetro);

}
