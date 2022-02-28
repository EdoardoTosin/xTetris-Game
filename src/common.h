#ifndef COMMON_H
#define COMMON_H

#include <time.h>
#include <sys/ioctl.h>

/*!
   \brief Global variables type `struct timespec` used for nanosleep paramenters.
*/
struct timespec request, remaining;

/*!
   \brief Makes a beep sound.
*/
void sound();
/*!
   \brief Call the system function to clear the cli.
*/
void clearCLI();
/*!
   \brief Exit the program after cleaning everything on screen.
*/
void exitFailure();
/*!
   \brief Call the system sleep.
   @param[in] timeDelay Time of the sleep in seconds.
*/
void delayTimer(int timeDelay);

/*!
   \brief Global variable type `struct winsize` used for terminal width and height.
*/
struct winsize w;

/*!
   \brief Apply an horizontal spacing based on window width and what need to be printed.
   @param[in] filledWidth Width of what is printed that need to be centered.
*/
void widthSpacing(int filledWidth);

/*!
   \brief Print text centered horizontally based on string length.
   @param[in] text Text that need to be printed on screen (doesn't include special characters).
*/
void printCentered(wchar_t *text);

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

void u_cleanup(void);

int u_kbhit(void);

int u_getchar(void);

/*!
   \brief Loop until user press a valid key.
   @param[in] time Time in microseconds which the usleep is called.
*/
int waitUserInput();

#endif
