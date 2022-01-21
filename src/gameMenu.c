#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "definitions.h"
#include "struct.h"

void printIntro(void){
  clearCLI();
  heightSpacing(7);
  widthSpacing(62);
  wprintf(L"          _|_|_|_|_|            _|                _|\r\n");
  widthSpacing(62);
  wprintf(L"_|    _|      _|      _|_|    _|_|_|_|  _|  _|_|        _|_|_|\r\n");
  widthSpacing(62);
  wprintf(L"  _|_|        _|    _|_|_|_|    _|      _|_|      _|  _|_|\r\n");
  widthSpacing(62);
  wprintf(L"_|    _|      _|    _|          _|      _|        _|      _|_|\r\n");
  widthSpacing(62);
  wprintf(L"_|    _|      _|      _|_|_|      _|_|  _|        _|  _|_|_|\r\n");
  wprintf(L"\r\n");
  printCentered(L"🎮 Controls: W⏫, A⏪, S⏬, D⏩, Enter✅, Esc❎");
  wprintf(L"\r\n");
  wprintf(L"\r\n");
  printCentered(L"🕹 Press ENTER to continue...");
}

void printMenuItems(int start, int end, int selected){
  int i;
  wchar_t *item[9];
  item[0]=L"-->";
  item[1]=L"🎮 Start Game";
  item[2]=L"🆘 Guide";
  item[3]=L"💳 Credits";
  item[4]=L"🍵 Exit";
  item[5]=L"🍺 Singleplayer";
  item[6]=L"🍻 Multiplayer";
  item[7]=L"🔙 Return";
  item[8]=L"<--";
  for(i=start; i<=end; i++){
    if(i==selected){
      widthSpacing(wcslen(item[0]) + wcslen(item[i]) + wcslen(item[8]));
      wprintf(L"%ls%ls%ls\r\n", item[0], item[i], item[8]);
    }
    else
      printCentered(item[i]);
  }
}

void printMainMenu(int *opt){
  heightSpacing(4);
  printMenuItems(1, 4, (*opt)-1);
}

void printPlayerMode(int* opt){
  heightSpacing(5);
  printMenuItems(1, 1, 0);
  wprintf(L"\r\n");
  printMenuItems(5, 7, (*opt)-1);
}

void secondPlayerName(PlNamePtr pl1, PlNamePtr pl2, int mode){
  pl1->name=L"Player 1";
  wprintf(L"\r\n");
  wprintf(L"%ls\r\n", pl1->name);
  wprintf(L"%ls\r\n", pl2->name);
  if (mode==1)
    pl2->name=L"Player 2";
  else
    pl2->name=L"Bot";
  wprintf(L"\r\n");
  wprintf(L"%ls\r\n", pl1->name);
  wprintf(L"%ls\r\n", pl2->name);
  delayTimer(2);
}

void printGuide(){
  heightSpacing(16);
  printMenuItems(2, 2, 0);
  wprintf(L"\r\n");
  wprintf(L"- Goal: Put your organizational skills and endurance to the test by clearing as many lines as possible.\r\n");
  wprintf(L"- Clear lines: Maneuver the falling Tetriminos to fit them together within the Matrix. To clear a line, fill every square within a single row.\r\n");
  wprintf(L"- Score points: Earn points by clearing lines. Clear multiple lines at once to increase your scoring opportunities.\r\n");
  wprintf(L"- Ghost piece: Use the Ghost Piece to determine the best fit for the falling Tetrimino. This helpful guide appears directly below the falling Tetrimino and displays possible placements.\r\n");
  wprintf(L"- Next queue: Preview the upcoming Tetrimino in the Next Queue to plan ahead and increase your scoring opportunities.\r\n");
  wprintf(L"- Hold queue: Store a falling Tetrimino in the Hold Queue for later use.\r\n");
  wprintf(L"- Game over: Stack the Tetriminos too high and the game is over!\r\n");
  wprintf(L"\r\n");
  printMenuItems(7, 7, 7);
}

void printCredits(){
  heightSpacing(6);
  printMenuItems(3, 3, 0);
  wprintf(L"\r\n");
  printCentered(L"Edoardo Tosin");
  wprintf(L"\r\n");
  wprintf(L"\r\n");
  printMenuItems(7, 7, 7);
}

void printCurrentMenu(int *menu, int *opt){
  clearCLI();
  /*sound();*/
  if(*menu==1)
    printMainMenu(opt);
  else if(*menu==2)
    printPlayerMode(opt);
  else if(*menu==3)
    printGuide();
  else if(*menu==4)
    printCredits();
}

int choiceCtrl(int menu, int opt, int min, int max){
  int key=0;
  printCurrentMenu(&menu, &opt);
  while(1){
    if(u_kbhit()){
      key=u_getchar();
      if(key==LOWER_W || key==UPPER_W || key==LOWER_S || key==UPPER_S){
        if(key==LOWER_W || key==UPPER_W){
          (opt)--;
          if(opt<min)
            opt=max;
        }
        else if(key==LOWER_S || key==UPPER_S){
          (opt)++;
          if(opt>max)
            opt=min;
        }
        printCurrentMenu(&menu, &opt);
      }
      else if(key==CARRIAGE_RETURN){
        return opt;
      }
      else if(key==ESCAPE){
        if(opt>=6 && opt<=8)
          return 8;
        else
          return 1;
      }
      else if(key==CTRL_C)
        exitFailure();
    }
    nanosleep(100);
  }
  exitFailure();
}
