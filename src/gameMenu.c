#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

#include "common.h"
#include "definitions.h"

void printMainMenu(int opt){
  clearCLI();
  wprintf(L"\a");
  if(opt==1){
    wprintf(L"-->Start Game<--\r\n");
    wprintf(L"      Rules\r\n");
    wprintf(L"     Credits\r\n");
    wprintf(L"      Exit\r\n");
  }
  else if(opt==2){
    wprintf(L"   Start Game\r\n");
    wprintf(L"   -->Rules<--\r\n");
    wprintf(L"     Credits\r\n");
    wprintf(L"      Exit\r\n");
  }
  else if(opt==3){
    wprintf(L"   Start Game\r\n");
    wprintf(L"      Rules\r\n");
    wprintf(L"  -->Credits<--\r\n");
    wprintf(L"      Exit\r\n");
  }
  else if(opt==4){
    wprintf(L"   Start Game\r\n");
    wprintf(L"      Rules\r\n");
    wprintf(L"     Credits\r\n");
    wprintf(L"   -->Exit<--\r\n");
  }
}

int crtlMainMenu(){
  int key, opt;
  printMainMenu(opt=1);
  while(1){
    if(u_kbhit()){
      key=u_getchar();
      if(key==119 || key==87){
        opt--;
        if(opt<1)
          opt=4;
        printMainMenu(opt);
      }
      else if(key==115 || key==83){
        opt++;
        if(opt>4)
          opt=1;
        printMainMenu(opt);
      }
      else if(key==13){
        return 1;
      }
      else if(key==27)
        return 0;
    }
    usleep(100);
  }

  return 0;
}
