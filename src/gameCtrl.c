#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

void makeMove(BoardPtr board, MovePtr storeMove){
	return;
}

int validRotation(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove, int rotation){

	int i, j, k, l;
	int piece, row, col;
	
	piece = storeMove->piece;

	for(i=storeMove->row, k=0; k<TETRO_DIM; i++, k++){
		for(j=storeMove->col, l=0; l<TETRO_DIM; j++, l++){
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

int fallingTetromino(BoardPtr board, MovePtr storeMove){

	int i, j;
	int fall;

	for(i=0, fall=VALID; i<HEIGHT; i++){
		for(j=0; j<WIDTH && fall==VALID; j++){
			if(board[i][j].status==TETRO_BOX && i+1>=HEIGHT){
				/*wprintf(L"[%d][%d] clash with bottom\r\n", i, j);*/
				fall = INVALID;
			}
			else if(board[i][j].status==TETRO_BOX && board[i+1][j].status>TETRO_BOX){
				/*wprintf(L"[%d][%d] clash with another box below\r\n", i, j);*/
				fall = INVALID;
			}
		}
	}

	if(fall==VALID){
		wprintf(L"Falling\r\n");
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
		/*wprintf(L"Landed\r\n");*/
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
	int shape, rotation, clash, row, col;
	col = WIDTH/2-TETRO_DIM/2;
	shape = storeMove->piece;
	rotation = storeMove->rotation;
	wprintf(L"First Row check\r\n");
	for(i=0, row=-1; i<TETRO_DIM; i++){
		for(j=0; j<TETRO_DIM; j++){
			if(row==-1 && tetro[shape][rotation][i][j].status==TETRO_BOX)
				row = i;
		}
	}
	wprintf(L"Check Clash\r\n");
	for(i=0, y = row; y<TETRO_DIM; y++, i++){
		for(j=col, l=0; l<TETRO_DIM; j++, l++){
			if(tetro[shape][rotation][y][l].status==TETRO_BOX && board[i][j].status==BOARD_BOX)
				return 1;
		}
	}
	wprintf(L"Valid add -> proceed to add the tetro to the board\r\n");
	for(i=0, y = row; y<TETRO_DIM; y++, i++){
		for(j=col, l=0; l<TETRO_DIM; j++, l++){
			if(tetro[shape][rotation][y][l].status==TETRO_BOX)
				board[i][j].status = TETRO_BOX;
		}
	}
	wprintf(L"Store new coordinates of tetromino in storeMove\r\n");
	storeMove->row = row;
	storeMove->col = col;
	return 0;
}

int playerTurn(BoardPtr board, TetrominoPtr tetro, MovePtr storeMove, int points){
	return 0;
}

void startGame(int mode){

	int i, j;
	int count = 0;

	int move;
	int skip;
	int prevPoints;
	int key=RESET;
	int fall = 0;
	int complete = 0;
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
	while(complete==0){
		if(fall==0){
			storeMove->piece = randGen(0, N_PIECES-1);
			storeMove->rotation = randGen(0, TETRO_ROT-1);
			complete = addTetromino(board_1, tetro, storeMove);
			move = 1;
		}
		if (complete==0){
			start = clock();
			fall = 1;
			skip = 0;
			do{
				if(move==1){
					printBoard(board_1, board_2, mode);
					move = 0;
				}
				if(u_kbhit()){
					key=u_getchar();
					if(key==LOWER_W || key==UPPER_W){
						move = validRotation(board_1, tetro, storeMove, -1);
						if (move==1){
							if(storeMove->rotation==0){
								storeMove->rotation = 3;
							}
							else{
								(storeMove->rotation)--;
							}
							makeMove(board_1, storeMove);
						}
					}
					else if(key==LOWER_S || key==UPPER_S){
						move = validRotation(board_1, tetro, storeMove, 1);
						if (move==1){
							if(storeMove->rotation==3){
								storeMove->rotation = 0;
							}
							else{
								(storeMove->rotation)++;
							}
							makeMove(board_1, storeMove);
						}
					}
					else if(key==LOWER_A || key==UPPER_A){
						move = validMove(board_1, -1);
						if (move==1){
							(storeMove->col)--;
							makeMove(board_1, storeMove);
						}
					}
					else if(key==LOWER_D || key==UPPER_D){
						move = validMove(board_1, 1);
						if (move==1){
							(storeMove->col)++;
							makeMove(board_1, storeMove);
						}
					}
					else if(key==CARRIAGE_RETURN){
						move = 1;
						skip = 1;
					}
					else if(key==CTRL_C)
						exitFailure();
					nanosleep(&request, &remaining);
				}
				timeDiff = (clock()-start)*1000/CLOCKS_PER_SEC;
			}
			while(timeDiff<700 && skip==0);
			fall = fallingTetromino(board_1, storeMove);
			printBoard(board_1, board_2, mode);
			if(fall==0){
				points_1 = prevPoints;
				points_1 += clearFullRows(board_1);
				if (points_1 != prevPoints){
					printBoard(board_1, board_2, mode);
					move = 1;
				}
				count++;
			}
			if (count>=3){
				complete = 1;
			}
		}
	}

	wprintf(L"\r\n");
	if (points_1>points_2 && mode==SINGLEPLAYER){
		wprintf(L"YOU WON!!!");
	}
	else if (points_2>points_1 && mode==SINGLEPLAYER){
		wprintf(L"LOSER!!!");
	}
	else if (points_1>points_2 && mode==MULTIPLAYER){
		wprintf(L"Winner: Player 1!!");
	}
	else if (points_1>points_2 && mode==MULTIPLAYER){
		wprintf(L"Winner: Player 2!!");
	}
	else if(points_1 == points_2){
		wprintf(L"TIE!!!");
	}
	delayTimer(2);
	key=RESET;
	wprintf(L"\r\nPress ENTER to exit\r\n");
	waitUser();

	/*
	printBoard(board_1, board_2, mode);
	waitUser();

	printTetrominoes(tetro);
	waitUser();

	addTetromino(board_1, tetro, 0, 3);

	printBoard(board_1, board_2, mode);
	waitUser();

	addTetromino(board_2, tetro, 3, 2);

	printBoard(board_1, board_2, mode);
	waitUser();

	for(i=HEIGHT-1; i>=HEIGHT-7; i--){
		if(i==HEIGHT-1 || i<HEIGHT-3)
			for(j=0; j<WIDTH; j++)
				board_2[i][j].status = BOARD_BOX;
	}

	printBoard(board_1, board_2, mode);
	waitUser();

	points_2 += clearFullRows(board_2);

	wprintf(L"%d\r\n", points_2);
	waitUser();

	printBoard(board_1, board_2, mode);
	waitUser();
	*/

	destroyBoard(board_1);
	destroyBoard(board_2);
	destroyMove(storeMove);
	destroyTetromino(tetro);

}
