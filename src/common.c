#include <stdio.h>
#include "definitions.h"

void delayTimer(int timeDelay) {
  #ifdef _WIN32
  Sleep(timeDelay);
  #else
  sleep(timeDelay);
  #endif
}
