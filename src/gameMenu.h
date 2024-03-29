#ifndef GAMEMENU_H
#define GAMEMENU_H


#include <wchar.h>

#include "struct.h"

/*!
   \brief Print the intro screen.
*/
void welcome(void);

/*!
   \brief Print the end screen.
*/
void goodbye(void);

/*!
   \brief Print main menu.
   @param[in] start Define the first menu item that need to be printed.
   @param[in] end Define the last menu item that need to be printed.
   @param[in] selected Define wich item is currently selected.
*/
void printMenuItems(int start, int end, int selected);

/*!
   \brief Print main menu.
   @param[in] opt Define the selected option in the menu at that moment.
*/
void printMainMenu(int *opt);

/*!
   \brief Print player mode menu.
   @param[in] opt Define the selected option in the menu at that moment.
*/
void printPlayerMode(int *opt);

/*!
   \brief Print the rules menu.
*/
void printGuide(void);

/*!
   \brief Print the credits menu.
*/
void printCredits(void);

/*!
   \brief Call the print of the current menu.
   @param[in] menu Define the current menu.
   @param[in] opt Define the current option selected.
*/
void printCurrentMenu(int *menu, int *opt);

/*!
   \brief Create the board.
   @param[in] menu Define the current menu.
   @param[in] opt Define the current option selected.
   @param[in] min Lowest value of option in current menu.
   @param[in] max Highest value of option in current menu.
*/
int choiceCtrl(int menu, int opt, int min, int max);


#endif
