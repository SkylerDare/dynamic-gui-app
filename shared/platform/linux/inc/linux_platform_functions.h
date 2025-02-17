#ifndef _LINUX_PLATFORM_FUNCTIONS_H_
#define _LINUX_PLATFORM_FUNCTIONS_H_

/* System include */
#include <iostream>
#include <iomanip>

/* Platform includes */
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

bool Linux_IsUserQuit();

#endif // _LINUX_PLATFORM_FUNCTIONS_H_