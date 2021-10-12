all: xTetris clean

xTetris: src/xTetris.o -o xTetris

xTetris.o: xTetris.c
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm xTetris.c

.PHONY: clean
clean:
	rm -rf src/*.o
