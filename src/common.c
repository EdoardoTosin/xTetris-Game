#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include "definitions.h"

void clearCLI(){
  int result;
  result = system(CLEAR);
  if (result == 1)
    exit(EXIT_FAILURE);
}

void delayTimer(int timeDelay) {
  #ifdef _WIN32
  Sleep(timeDelay);
  #else
  sleep(timeDelay);
  #endif
}

wchar_t eSq = 0x2B1C; /* emptySquare */
wchar_t fSq = 0x2B1B; /* fullSquare */
