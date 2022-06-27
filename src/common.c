#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <wchar.h>

#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

#include "definitions.h"

const wchar_t chSq = 0x2705; /* checkSquare ✅ */
const wchar_t crSq = 0x274E; /* crossSquare ❎ */
const wchar_t eSq = 0x2B1C; /* emptySquare ⬜ */
const wchar_t fSq = 0x2B1B; /* fullSquare ⬛ */

const int timeLimit = 1000;

enum {NSEC_TO_SLEEP = 125, SECS_TO_SLEEP = 0};

struct timespec request, remaining = {NSEC_TO_SLEEP, SECS_TO_SLEEP};

void sound(){
  wprintf(L"\a");
}

void clearCLI(void){

  int res;
  
  res = system("clear");
  if (res == 1){
    clearCLI();
    exit(EXIT_FAILURE);
  }
}

void exitFailure(void){
  clearCLI();
  exit(EXIT_FAILURE);
}

void delayTimer(int time){
  sleep(time);
}

struct winsize w;

int intLen(int value){
  
  int length = 0;
  
  if (value != 0){
    while(value!=0){  
       value = value/10;  
       length++;  
    }
  }
  
  return (length==0)?1:length;
  
}

void widthSpacing(int filledWidth){

  int i;
  
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  for(i=0; i<(w.ws_col-filledWidth)/2; i++)
    wprintf(L" ");
}

void printCentered(wchar_t *text){
  widthSpacing(wcslen(text));
  wprintf(L"%ls\r\n", text);
}

void heightSpacing(int filledHeight){

  int i;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  for(i=0; i<(w.ws_row-filledHeight)/2; i++)
    wprintf(L"\r\n");
}

static struct termios orig_term;

void u_cleanup(void){
  tcsetattr(0, TCSANOW, &orig_term);
}

int u_kbhit(void){

  struct termios t;
  fd_set rfd;
  struct timeval to;
  static int first_hit=0;

  if(first_hit==0){
    if(tcgetattr(0, &t)!=0)
      exit(0);
    orig_term=t;
    cfmakeraw(&t);
    if(tcsetattr(0, TCSANOW, &t)!=0)
      exit(0);
    atexit(u_cleanup);
    first_hit=1;
  }

  FD_ZERO(&rfd);
  FD_SET(0, &rfd);
  to.tv_sec=0;
  to.tv_usec=0;
  if(select(1, &rfd, NULL, NULL, &to)==1)
    return 1;
  return 0;
}

int u_getchar(void){

  int ret;
  unsigned char buf;

  if(read(0, &buf, 1)!=1)
    ret=0;
  else
    ret=buf;
  return ret;
}

int waitUserInput(void){

  int key=0;

  while(1){
    if(u_kbhit()){
      key=u_getchar();
      if (key == CTRL_C)
        exitFailure();
      return key;
    }
    nanosleep(&request, &remaining);
  }
  exitFailure();
}

void waitUser(void){
  int key=2;
  while(key!=CARRIAGE_RETURN){
    key = waitUserInput();
  }
}
