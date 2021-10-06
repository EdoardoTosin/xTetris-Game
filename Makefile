all: xTetris clean

xTetris: src/xTetris.o src/gameControl.o src/objectCreation.o src/printGame.o src/startGame.o src/printRules.o src/printCredits.o src/startMenu.o
	cc src/xTetris.o src/gameControl.o src/objectCreation.o src/printGame.o src/startGame.o src/printRules.o src/printCredits.o src/startMenu.o -o xTetris

objectCreation.o: objectCreation.c objectCreation.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm objectCreation.c

printGame.o: printGame.c printGame.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm printGame.c

gameControl.o: gameControl.c gameControl.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm gameControl.c

startGame.o: startGame.c startGame.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm startGame.c

printRules.o: printRules.c printRules.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm printRules.c

printCredits.o: printCredits.c printCredits.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm printCredits.c

startMenu.o: startMenu.c startMenu.h
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm startMenu.c

xTetris.o: xTetris.c
	cc -c -ansi -pedantic -O2 -Wall -Wextra -lm xTetris.c

.PHONY: clean
clean:
	rm -rf src/*.o
