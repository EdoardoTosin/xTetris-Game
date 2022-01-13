#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common.h"
#include "definitions.h"

void printIntro(void){
  clearCLI();
  heightSpacing(5);
  widthSpacing(62);
  wprintf(L"          _|_|_|_|_|            _|                _|\n");
  widthSpacing(62);
  wprintf(L"_|    _|      _|      _|_|    _|_|_|_|  _|  _|_|        _|_|_|\n");
  widthSpacing(62);
  wprintf(L"  _|_|        _|    _|_|_|_|    _|      _|_|      _|  _|_|\n");
  widthSpacing(62);
  wprintf(L"_|    _|      _|    _|          _|      _|        _|      _|_|\n");
  widthSpacing(62);
  wprintf(L"_|    _|      _|      _|_|_|      _|_|  _|        _|  _|_|_|\n");
}

void printMenuItems(int start, int end, int selected){
  int i;
  wchar_t* item[7];
  item[0]=L"-->";
  item[1]=L"Start Game";
  item[2]=L"Guide";
  item[3]=L"Credits";
  item[4]=L"Exit";
  item[5]=L"Return";
  item[6]=L"<--";

  for(i=start; i<=end; i++){
    if(i==selected){
      widthSpacing(wcslen(item[0])+wcslen(item[i])+wcslen(item[6]));
      wprintf(L"%ls%ls%ls\r\n",item[0],item[i],item[6]);
    }
    else{
      widthSpacing(wcslen(item[i]));
      wprintf(L"%ls\r\n",item[i]);
    }
  }
}

void printMainMenu(int opt){
  heightSpacing(4);
  printMenuItems(1,4,opt-1);
}

void playersName(wchar_t* pl1, wchar_t* pl2){
  pl1 = L"Player 007";
  pl2 = L"Player 2";
  setlocale( LC_ALL, "" );
  do{
    heightSpacing(1);
    widthSpacing(20);
    wprintf(L"Enter Player 1 name:\r\n");
    /*wscanf(L"%ls", pl1);*/
  }
  while(wcslen(pl1)<1 || wcslen(pl1)>20);
  do{
    heightSpacing(1);
    widthSpacing(20);
    wprintf(L"Enter Player 2 name:\r\n");
    /*wscanf(L"%ls", pl2);*/
  }
  while(wcslen(pl2)<1 || wcslen(pl2)>20);
}

void printGuide(){
  heightSpacing(14);
  wprintf(L"- Goal: Put your organizational skills and endurance to the test by clearing as many lines as possible.\r\n");
  wprintf(L"- Clear lines: Maneuver the falling Tetriminos to fit them together within the Matrix. To clear a line, fill every square within a single row.\r\n");
  wprintf(L"- Score points: Earn points by clearing lines. Clear multiple lines at once to increase your scoring opportunities.\r\n");
  wprintf(L"- Ghost piece: Use the Ghost Piece to determine the best fit for the falling Tetrimino. This helpful guide appears directly below the falling Tetrimino and displays possible placements.\r\n");
  wprintf(L"- Next queue: Preview the upcoming Tetrimino in the Next Queue to plan ahead and increase your scoring opportunities.\r\n");
  wprintf(L"- Hold queue: Store a falling Tetrimino in the Hold Queue for later use.\r\n");
  wprintf(L"- Game over: Stack the Tetriminos too high and the game is over!\r\n");
  wprintf(L"\r\n");
  printMenuItems(5,5,5);
}

void printCredits(){
  heightSpacing(14);
  widthSpacing(10);
  wprintf(L"Developer:\r\n");
  widthSpacing(13);
  wprintf(L"Edoardo Tosin\r\n");
  wprintf(L"\r\n");
  wprintf(L"\r\n");
  printMenuItems(5,5,5);
}

void printCurrentMenu(int menu, int opt){
  clearCLI();
  /*sound();*/
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
      if(key==LOWER_W || key==UPPER_W || key==LOWER_S || key==UPPER_S){
        if(key==LOWER_W || key==UPPER_W){
          opt--;
          if(opt<min)
            opt=max;
        }
        else if(key==LOWER_S || key==UPPER_S){
          opt++;
          if(opt>max)
            opt=min;
        }
        printCurrentMenu(menu, opt);
      }
      else if(key==CARRIAGE_RETURN){
        return opt;
      }
      else if(key==ESCAPE)
        return 0;
    }
    usleep(100);
  }
  return 0;
}
