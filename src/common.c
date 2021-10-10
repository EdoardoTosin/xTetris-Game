#include <stdio.h>

void delayTimer(int timeDelay) {
  #ifdef _WIN32
  Sleep(timeDelay);
  #else
  sleep(timeDelay);
  #endif
}
