#define HEIGHT (15)
#define WIDTH (10)
#define SPACING (8)

#ifdef _WIN32
#include <Windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif
