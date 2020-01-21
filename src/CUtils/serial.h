#ifndef _SERIAL_H_
#define _SERIAL_H_

#include "precompiled.h"

/* UNUSED BLOCK
#ifdef __USE_INACTIVE_
#ifdef _WIN32

// Opens and sets the port settings, returns fd
// for later processing in HANDLE* hCom parameter
// Returns 1 if function is finished successfully
// Returns 0 if function fails
bool AutoPortInit(char* portname, OUT HANDLE* hCom);

// Closes the HANDLE that has been opened by AutoPortInit Function
void CloseHandle(HANDLE hCom);

#endif // _WIN32
#endif // __USE_INACTIVE_
UNUSED BLOCK */

#ifdef linux

// Opens and sets the port settings, returns fd
// for later processing in int* outFd parameter
// Returns 1 if function is finished successfully
// Returns 0 if function fails
bool InitPort(char* portname, OUT int* outFd);

// Sets min count and timeout for fd
// Returns 1 if function is finished successfully
// Returns 0 if function fails
bool SetMincount(int fd, int mcount);

#endif // linux

#endif // !_SERIAL_H_