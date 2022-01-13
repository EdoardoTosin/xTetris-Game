#include <sys/ioctl.h>

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
