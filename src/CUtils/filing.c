#include "filing.h"

int WriteAllData(char* path, char* data, int dataLen)
{
	// Create file pointer
	FILE* fp;
	fp = fopen(path, "w");

	// Check file pointer
	if (fp == NULL)
	{
		// If CEP goes here, we have Fatal Error
		return false;
	}

	// Cast from char* to void*
	// Write all the bytes to the file
	int res = (int)fwrite((void*)data, 1, dataLen * sizeof(char), fp);

	// Clean up
	fclose(fp);
	fp = NULL;

	// Return
	return res;
}

int WriteAllLines(char* path, char** data, int* dataLens, int len)
{
	// Create file pointer
	FILE* fp;
	fp = fopen(path, "w");

	// Check file pointer
	if (fp == NULL)
	{
		// If CEP goes here, we have Fatal Error
		return false;
	}

	// Holds the sum of all the written bytes
	int res = 0;

	// Iterate through data[][] from 0 to len
	for (int i = 0; i < len; i++)
	{	
		// Cast from char* to void*
		// Write all the bytes to the file
		// Add the written bytes count to res variable
		res += (int)fwrite((void*)data[i], 1, dataLens[i] * sizeof(char), fp);
	}

	// Clean up
	fclose(fp);
	fp = NULL;

	// Return
	return res;
}

int AppendAllData(char* path, char* data, int dataLen)
{
	// Create file pointer
	FILE* fp;
	fp = fopen(path, "a");

	// Check file pointer
	if (fp == NULL)
	{
		// If CEP goes here, we have Fatal Error
		return false;
	}

	// Cast from char* to void*
	// Append all the bytes to the file
	int res = (int)fwrite((void*)data, 1, dataLen * sizeof(char), fp);

	// Clean up
	fclose(fp);
	fp = NULL;

	// Return
	return res;
}

int AppendAllLines(char* path, char** data, int* dataLens, int len)
{
	// Create file pointer
	FILE* fp;
	fp = fopen(path, "a");

	// Check file pointer
	if (fp == NULL)
	{
		// If CEP goes here, we have Fatal Error
		return false;
	}

	// Holds the sum of all the written bytes
	int res = 0;

	// Iterate through data[][] from 0 to len
	for (int i = 0; i < len; i++)
	{
		// Cast from char* to void*
		// Append all the bytes to the file
		res += (int)fwrite((void*)data[i], 1, dataLens[i] * sizeof(char), fp);
	}

	// Clean up
	fclose(fp);
	fp = NULL;

	// Return
	return res;
}

int ReadAllData(NO_ALLOC LEAKY OUT char** buffer, char* path, OUT int* len)
{
	char* localBuffer;
	int num_bytes;

	// Create file pointer
	FILE* fp;
	fp = fopen(path, "r");

	// Check file pointer
	if (fp == NULL)
	{
		// If CEP goes here, we have Fatal Error
		return false;
	}

	// Calculate the number of bytes in the file
	fseek(fp, 0L, SEEK_END);
	num_bytes = ftell(fp);
	
	// Go back to the beginning of file
	fseek(fp, 0L, SEEK_SET);

	// Allocate memory equal to the size of the bytes in the file
	localBuffer = (char*)calloc(num_bytes, sizeof(char));

	if (localBuffer == NULL)
	{
		// If CEP goes here, we have Fatal Error
		// Clean up
		fclose(fp);
		fp = NULL;

		// Return
		return false;
	}

	// read all the file, putting it in the local buffer
	int res = (int)fread(localBuffer, sizeof(char), num_bytes, fp);

	// Return the by-reference params
	*len = num_bytes;
	*buffer = localBuffer;

	// Clean up
	fclose(fp);
	fp = NULL;

	// Return
	return res;
}

int SafeFRead(void** OUT buffer, int size, int number, char* path)
{
	// Create file pointer
	FILE* fp;
	fp = fopen(path, "r");

	// Check file pointer
	if (fp == NULL)
	{
		// If CEP goes here, we have Fatal Error
		return false;
	}

	if (feof(fp))
	{
		// If CEP goes here, we have Fatal Error
		// Clean up
		fclose(fp);
		fp = NULL;

		// Return
		return false;
	}

	// Put all the read bytes in res for later error checking
	int res = (int)fread(*buffer, size, number, fp);
	
	if (res < number)
	{
		// Clean up
		fclose(fp);
		fp = NULL;

		// Return
		return false;
	}

	// Clean up
	fclose(fp);
	fp = NULL;

	// Return
	return res;
}

bool DoesFileExist(char* path)
{
#ifdef _WIN32
	unsigned long attrib = GetFileAttributes(path);
	return (attrib != INVALID_FILE_ATTRIBUTES && !(attrib & FILE_ATTRIBUTE_DIRECTORY));
#endif // _WIN32

#ifdef linux
	if (access(path, F_OK) != -1)
	{
		return true;
	}
	return false;
#endif // linux
}

bool CreateDir(char* path)
{
#ifdef _WIN32
	unsigned long res = CreateDirectory((const char*)path, NULL);
	if (res == (ERROR_ALREADY_EXISTS | ERROR_PATH_NOT_FOUND))
	{
		// Failed to create directory
		return false;
	}
	// Directory created successfully
	return true;
#endif // _WIN32

#ifdef linux
	struct stat st = { 0 };
	if (stat(path, &st) == -1)
	{
		// Directory created successfully
		mkdir(dir, 0700);
		return true;
	}
	// Failed to create directory
	return false;
#endif // linux
}
