#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "definitions.h"

void printIntro(void){
  clearCLI();
  wprintf(L"\n");
  wprintf(L"\n");
  wprintf(L"           _|_|_|_|_|            _|                _|\n");
  wprintf(L" _|    _|      _|      _|_|    _|_|_|_|  _|  _|_|        _|_|_|\n");
  wprintf(L"   _|_|        _|    _|_|_|_|    _|      _|_|      _|  _|_|\n");
  wprintf(L" _|    _|      _|    _|          _|      _|        _|      _|_|\n");
  wprintf(L" _|    _|      _|      _|_|_|      _|_|  _|        _|  _|_|_|\n");
  wprintf(L"\n");

  delayTimer(1);
}

void printMainMenu(int opt){
  if(opt==2){
    wprintf(L"-->Start Game<--\r\n");
    wprintf(L"      Guide\r\n");
    wprintf(L"     Credits\r\n");
    wprintf(L"      Exit\r\n");
  }
  else if(opt==3){
    wprintf(L"   Start Game\r\n");
    wprintf(L"   -->Guide<--\r\n");
    wprintf(L"     Credits\r\n");
    wprintf(L"      Exit\r\n");
  }
  else if(opt==4){
    wprintf(L"   Start Game\r\n");
    wprintf(L"      Guide\r\n");
    wprintf(L"  -->Credits<--\r\n");
    wprintf(L"      Exit\r\n");
  }
  else if(opt==5){
    wprintf(L"   Start Game\r\n");
    wprintf(L"      Guide\r\n");
    wprintf(L"     Credits\r\n");
    wprintf(L"   -->Exit<--\r\n");
  }
}

void playersName(wchar_t* pl1, wchar_t* pl2){
  pl1 = L"Player 007";
  pl2 = L"Player 2";
  setlocale( LC_ALL, "" );
  do{
    wprintf(L"Enter Player 1 name:\r\n");
    /*wscanf(L"%ls", pl1);*/
  }
  while(wcslen(pl1)<1 || wcslen(pl1)>20);
  do{
    wprintf(L"Enter Player 2 name:\r\n");
    /*wscanf(L"%ls", pl2);*/
  }
  while(wcslen(pl2)<1 || wcslen(pl2)>20);

}

void printGuide(){
  wprintf(L"- Goal: Put your organizational skills and endurance to the test by clearing as many lines as possible.\r\n");
  wprintf(L"- Clear lines: Maneuver the falling Tetriminos to fit them together within the Matrix. To clear a line, fill every square within a single row.\r\n");
  wprintf(L"- Score points: Earn points by clearing lines. Clear multiple lines at once to increase your scoring opportunities.\r\n");
  wprintf(L"- Ghost piece: Use the Ghost Piece to determine the best fit for the falling Tetrimino. This helpful guide appears directly below the falling Tetrimino and displays possible placements.\r\n");
  wprintf(L"- Next queue: Preview the upcoming Tetrimino in the Next Queue to plan ahead and increase your scoring opportunities.\r\n");
  wprintf(L"- Hold queue: Store a falling Tetrimino in the Hold Queue for later use.\r\n");
  wprintf(L"- Game over: Stack the Tetriminos too high and the game is over!\r\n");
  wprintf(L"\r\n");
  wprintf(L"\r\n");
  wprintf(L"   -->Return<--\r\n");
}

void printCredits(){
  wprintf(L"Developer:\r\n");
  wprintf(L" Edoardo Tosin\r\n");
  wprintf(L"\r\n");
  wprintf(L"\r\n");
  wprintf(L"   -->Return<--\r\n");
}

void printCurrentMenu(int menu, int opt){
  clearCLI();
  wprintf(L"\a");
  if(menu==1)
    printMainMenu(opt);
  else if(menu==3)
    printGuide();
  else if(menu==4)
    printCredits();
}

int choiceCtrl(int menu, int opt, int min, int max){
  int key;
  printCurrentMenu(menu, opt);
  while(1){
    if(u_kbhit()){
      key=u_getchar();
      if(key==119 || key==87 || key==115 || key==83){
        if(key==119 || key==87){
          opt--;
          if(opt<min)
            opt=max;
        }
        else if(key==115 || key==83){
          opt++;
          if(opt>max)
            opt=min;
        }
        printCurrentMenu(menu, opt);
      }
      else if(key==13){
        return opt;
      }
      else if(key==27)
        return 0;
    }
    /*usleep(100);*/
  }
  return 0;
}
