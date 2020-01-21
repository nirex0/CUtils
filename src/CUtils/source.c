#include "strutil.h"

int main() 
{

	printf("TESTING SPLIT:\n");
	// Split
	char string[53] = "Hello Everyone, How ya'all doing in this fine day?!";
	char* delim = " ";
	char** out;
	int count = SplitString(string, delim, &out);
	for (int i = 0; i < count; i++)
	{
		printf("%s%s", (const char*)out[i], (const char*)delim);
	}
	SplitFree(out, count);


	printf("\n\nTESTING CONCAT:\n");
	// Concat
	char* con0 = ConcatString((char*)"is attached", (char*)" to The Second string using the third stirng!");
	char* con1 = ConcatString((char*)"The first string, ", con0);
	printf("%s\n", con1);

	ConcatFree(con0);
	ConcatFree(con1);


	return 0;
}