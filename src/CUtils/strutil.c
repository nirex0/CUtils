#include "strutil.h"

int SplitString(char* string, char* delimiter, OUT LEAKY char*** outArrayReference)
{
	int count = 0;
	char** result;
	
	char* tmpstr = (char*)malloc(strlen(string) + 1);
	strcpy(tmpstr, string);

	char* token = strtok(tmpstr, delimiter);

	// loop through the string to get token count for array allocation
	while (token != NULL)
	{
		token = strtok(NULL, delimiter);
		++count;
	}

	// Clean Up
	strcpy(tmpstr, string);
	free(tmpstr);
	tmpstr = NULL;

	result = (char*)malloc(count * sizeof(char*));

	token = NULL;
	token = strtok(string, delimiter);

	// loop through the string to extract all other tokens
	int counter = 0;
	while (token != NULL)
	{
		result[counter] = (char*)malloc(strlen(token) + 1);
		strcpy(result[counter], token);

		token = strtok(NULL, delimiter);
		++counter;
	}	

	*outArrayReference = result;
	return counter;
}

void SplitFree(char** strArray, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(strArray[i]);
		strArray[i] = NULL;
	}

	free(strArray);
	strArray = NULL;
}

LEAKY char* ConcatString(char* stringA, char* stringB)
{
	if (stringA == NULL || stringB == NULL)
	{
		return NULL;
	}

	int alen = (int)strlen(stringA);
	int blen = (int)strlen(stringB);

	char* result = (char*)calloc(alen + blen + 1, sizeof(char));
	strcpy(result, stringA);
	strcat(result, stringB);
	
	return result;
}

void ConcatFree(char* string)
{
	free(string);
	string = NULL;
}

int StringToInt(char* string)
{
	int result = 0;
	int puiss = 1;

	while (('-' == (*string)) || ((*string) == '+'))
	{
		if (*string == '-')
			puiss = puiss * -1;
		string++;
	}
	while ((*string >= '0') && (*string <= '9'))
	{
		result = (result * 10) + ((*string) - '0');
		string++;
	}
	return (result * puiss);
}

LEAKY char* IntToString(int input, OUT int* len)
{
	*len = (int)((ceil(log10(input)) + 1) * sizeof(char));
	
	char* str = (char*)malloc((*len) * sizeof(char));
	sprintf(str, DECIMAL_STR, input);

	return str;
}

LEAKY char* DoubleToString(double input, OUT int* len)
{
	char str[ENOUGH];
	sprintf(str, FLOAT_STR, input);
	*len = (int)strlen(str);

	char* sout = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(sout, str);
	return sout;
}

LEAKY char* FloatToString(float input, OUT int* len)
{
	char str[ENOUGH];
	sprintf(str, FLOAT_STR, input);
	*len = (int)strlen(str);

	char* sout = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(sout, str);
	return sout;
}

bool AreEqual(char* stringA, char* stringB)
{
	int aLen = (int)strlen(stringA);
	int bLen = (int)strlen(stringB);

	if (aLen != bLen) 
	{
		return false;
	}
	
	for (int i = 0; i < aLen; i++)
	{
		if (stringA[i] != stringB[i])
		{
			return false;
		}
	}

	return true;
}
