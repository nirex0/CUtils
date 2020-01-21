#ifndef _FILING_H_
#define _FILING_H_

#include "precompiled.h"

// Writes all the data in the "data" parameter to the file in "path" parameter
// Returns the number of written bytes
// Returns 0 if there are errors
int WriteAllData(char* path, char* data, int dataLen);

// Writes all the lines in the "data" parameter
// "dataLens" is an array determining the length of each line
// "len" is a number determining the length of the dataLens parameter
// Returns the number of written bytes
// Returns 0 if there are errors
int WriteAllLines(char* path, char** data, int* dataLens, int len);

// Appends all the data in the "data" parameter to the file in "path" parameter
// Returns the number of appended bytes
// Returns 0 if there are errors
int AppendAllData(char* path, char* data, int dataLen);

// Appends all the lines in the "data" parameter
// "dataLens" is an array determining the length of each line
// "len" is a number determining the length of the dataLens parameter
// Returns the number of appended bytes
// Returns 0 if there are errors
int AppendAllLines(char* path, char** data, int* dataLens, int len);

// Reads all the data within a specific file
// Buffer is allocated using calloc and is filled with the data being read from
//	the file, not free()ing it will cause memory leakage.
// Returns the number of read bytes (Should be equal to len)
// Returns 0 if there are errors
int ReadAllData(NO_ALLOC LEAKY OUT char** buffer, char* path, OUT int* len);

// Safely reads from the file, filling out the buffer
// Note: Buffer needs to be allocated before being passed into this function
// Returns the number of read bytes (Should be equal to number)
// Returns 0 if there are errors
int SafeFRead(void** OUT buffer, int size, int number, char* path);

// Checks to see if the file exists
// Returns 1 if exists and 0 if not
bool DoesFileExist(char* path);

#endif // !_FILING_H_