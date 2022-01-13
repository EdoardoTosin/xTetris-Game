#include <sys/ioctl.h>

/*!
   \brief Exit the program after cleaning everything on screen.
*/
void exitFailure();
/*!
   \brief Makes a beep sound.
*/
void sound();
/*!
   \brief Call the system function to clear the cli.
*/
void clearCLI();
/*!
   \brief Call the system sleep.
   @param[in] timeDelay Time of the sleep in seconds.
*/
void delayTimer(int timeDelay);

/*!
   \brief Global variable type struct winsize used for terminal width and height.
*/
struct winsize w;

/*!
   \brief Apply an horizontal spacing based on window width and what need to be printed.
   @param[in] filledWidth Width of what is printed that need to be centered.
*/
void widthSpacing(int filledWidth);

/*!
   \brief Apply a vertical spacing based on window heigth and what need to be printed.
   @param[in] filledHeight Height of what is printed that need to be centered.
*/
void heightSpacing(int filledHeight);

/*!
   \brief Assign unicode character (white square) to this global variable.
*/
wchar_t eSq;
/*!
   \brief Assign unicode character (black square) to this global variable.
*/
wchar_t fSq;

/*
  COMPLETE WITH NEW FUNCTIONS
*/

/*!
   \brief Loop until user press a valid key.
*/
int waitUserInput();
