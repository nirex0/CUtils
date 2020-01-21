#ifndef _PERCOMPILED_H_
#define _PERCOMPILED_H_

/***************************\
	   #DEFINE SEGMENT
\***************************/

/* UNUSED
// Serial Port related enum types
// TODO: Implement into the serial function!
// Parity enum
typedef enum { PINVALID, PNone, PEven, POdd } Parity;

// Wordsize enum
typedef enum { WSINVALID, WSEight, WSSeven, WSSix } WordSize;

// StopBits enum
typedef enum { SBINVALID, SB1, SB15, SB2 } StopBits;

// Flow enum
typedef enum { FINVALID, FNone, FRTS_CTS, FXON_XOFF } Flow;

// Baudrate enum (Most common Baudrates)
typedef enum { BINVALID, B9600, B19200, B38400, B57600, 
			   B115200, B150, B300, B600, B1200, B2400, 
			   B4800, B230400, B460800, B921600, B256, B512,
			   B1024, B2048, B4096, B8192, B16384, B32768,
			   B65536, B1000, B2000, B3000, B4000, B5000,
			   B6000, B7000, B8000, B9000, B10000, B20000,
			   B30000, B40000, B50000, B60000, B70000, B80000,
			   B90000, B100000 } Baudrate;

// Message enum
typedef enum { MINVALID, MNone, MCR, MLF, MCR_AND_LF } Message;

UNUSED */

#ifdef _WIN32

// MS BS!
#define _CRT_SECURE_NO_WARNINGS

#endif // _WIN32

// empty string utility
// Usae: Makes sure the "" you placed is not a placeholder
#define STRING_EMPTY ""

// These will be used for decimal, float and double to string casting
// For ease of reading the code, please use these instead of their
// repective values
#define ENOUGH 100
#define FLOAT_STR "%f"
#define DECIMAL_STR "%d"

// Bool, (Not the C99 way!)
typedef char bool;
#define true 1
#define false 0

// This means the parameter is first a reference param and second a
// Secondary output of the function.
// (Reference Output)
#define	OUT

// This means the allocation will happen within the body of the function
// and usually comes with LEAKY macro.
#define	NO_ALLOC

// This usually comes after OUT, meaning whatever is getting passed
// Outside of the function has had dynamic heapy memory allocation
// Within the body of the function, but the usage is outside the 
// Function, thus it cannot be freed within the function
// Not cleaning it up afterwards can cause memory leakage.
#define	LEAKY

#ifdef _WIN32
// <Windows.h> Defines

#ifndef _FULL_WINSUPPORT

#define WIN32_LEAN_AND_MEAN

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
#define NOUSER
#define NONLS
#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#endif // !_FULL_WINSUPPORT

// We do not want min and max either way since they tend to
// mess things up for us if we want to use normal min and max
// in <stdlib.h>: Line 1300 & 1301

#ifndef NOMINMAX
#define NOMINMAX
#endif // !NOMINMAX

#ifndef STRICT
#define STRICT
#endif // !STRICT

#endif // _WIN32

/***************************\
	  #INCLUDE SEGMENT
\***************************/

// General headers
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <fcntl.h>
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#ifdef linux
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <termios.h>
#endif // linux

/***************************\
	 STRUCTURES SEGMENT
\***************************/

#endif // !_PERCOMPILED_H_
