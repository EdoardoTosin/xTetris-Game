#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <wchar.h>

#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

#include "definitions.h"

void sound(){
  wprintf(L"\a");
}

void clearCLI(){
  int res;
  res = system("clear");
  if (res == 1){
    clearCLI();
    exit(EXIT_FAILURE);
  }
}

void exitFailure(){
  clearCLI();
  exit(EXIT_FAILURE);
}

void delayTimer(int time){
  sleep(time);
}

struct winsize w;

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

const wchar_t eSq = 0x2B1C; /* emptySquare ⬜ */
const wchar_t fSq = 0x2B1B; /* fullSquare ⬛ */

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

int waitUserInput(){
  int key=0;
  while(1){
    if(u_kbhit()){
      key=u_getchar();
      if (key == CTRL_C)
        exitFailure();
      return key;
    }
    nanosleep(100);
  }
  exitFailure();
}
