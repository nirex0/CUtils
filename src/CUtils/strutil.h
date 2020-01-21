#ifndef _STRUTIL_H_
#define _STRUTIL_H_

#include "precompiled.h"

// Splits a string using the the delimiter param
// outArray is set to an array of all tokens
// Returns the count of the final tokens
// NOTE: This function will remove empty results ( "" )
//   E.G: "Hello     World!" will result in "Hello" and 
//   "World!" and the empty spaces between the two will
//   not be included in the outArrayReference parameter
int SplitString(char* string, char* delimiter, OUT LEAKY char*** outArrayReference);

// Frees the string array taken from the SplitString function
void SplitFree(char** strArray, int count);

// Concats two strings together without causing segfault
// Returns the new string, allowing the cascading function call
LEAKY char* ConcatString(char* stringA, char* stringB);

// Frees the string taken from the ConcatString function
void ConcatFree(char* string);

// Parses an int from a string
// Returns the resulting int as the result
// Error will be 1 if there are any errors, 0 otherwise
int StringToInt(char* string);

// Converts an int to a string
// Len will be set to the length of the string
// Returns the resulting string
LEAKY char* IntToString(int input, OUT int* len);

// Converts a double to a string
// Len will be set to the length of the string
// Returns the resulting string
LEAKY char* DoubleToString(double input, OUT int* len);

// Converts a float to a string
// Len will be set to the length of the string
// Returns the resulting string
LEAKY char* FloatToString(float input, OUT int* len);

// Checks to see whether or not two strings are equal
// Returns 1 if equal, 0 if not equal
bool AreEqual(char* stringA, char* stringB);

#endif // !_STRUTIL_H_
	