#include <wchar.h>

/*!
   \brief Print game logo.
*/
void printIntro();

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
void printMainMenu(int opt);

/*!
   \brief Prepare the gameplay asking for player names.
   @param[in] pl1 Pointer to Player 1 name.
   @param[in] pl2 Pointer to Player 2 name.
*/
void playersName(wchar_t* pl1, wchar_t* pl2);

/*!
   \brief Print the rules menu.
*/
void printGuide();

/*!
   \brief Print the credits menu.
*/
void printCredits();

/*!
   \brief Call the print of the current menu.
   @param[in] menu Define the current menu.
   @param[in] opt Define the current option selected.
*/
void printCurrentMenu(int menu, int opt);

/*!
   \brief Create the board.
   @param[in] menu Define the current menu.
   @param[in] opt Define the current option selected.
   @param[in] min Lowest value of option in current menu.
   @param[in] max Highest value of option in current menu.
*/
int choiceCtrl(int menu, int opt, int min, int max);
