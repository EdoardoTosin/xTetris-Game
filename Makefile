all: xTetris clean

xTetris: src/xTetris.o src/printGame.o src/initBoard.o src/common.o -o xTetris

src/common.o: src/common.c src/common.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm src/common.c

src/initBoard.o: src/initBoard.c src/initBoard.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm src/initBoard.c

src/printGame.o: src/printGame.c src/printGame.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm src/printGame.c

src/xTetris.o: src/xTetris.c
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm src/xTetris.c

.PHONY: clean
clean:
	rm -rf src/*.o
