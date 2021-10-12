all: xTetris clean

xTetris: src/xTetris.o src/common.o -o xTetris

common.o: src/common.c common.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm src/common.c

xTetris.o: src/xTetris.c
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm src/xTetris.c

.PHONY: clean
clean:
	rm -rf src/*.o
