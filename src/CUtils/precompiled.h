#ifndef _PERCOMPILED_H_
#define _PERCOMPILED_H_

/***************************\
	   #DEFINE SEGMENT
\***************************/

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
typedef enum { false, true } bool;

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

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#ifdef linux
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif // linux

/***************************\
	 STRUCTURES SEGMENT
\***************************/

#endif // !_PERCOMPILED_H_