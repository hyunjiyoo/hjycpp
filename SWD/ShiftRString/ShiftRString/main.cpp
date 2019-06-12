#include <iostream>
using namespace std;
char* ShiftRstring(char* source);
int main()
{
	char* input = new char[20];
	cin.getline(input, 20);

	int len = strlen(input);
	char* preStr = input;
	char* curStr = NULL;

	for (int i = 0; i < len; i++)
	{
		curStr = ShiftRstring(preStr);
		cout << curStr << endl;
		delete preStr; preStr = NULL;
		preStr = curStr;
	}
	delete preStr; preStr = NULL; curStr = NULL;

	return 0;
}
char* ShiftRstring(char* source)
{
	// char* source = preStr; // char* source = input;
	int len = strlen(source);
	char* revStr = new char[len + 1];
	revStr[0] = source[len - 1];
	for (int i = 1; i < len; i++)
	{
		revStr[i] = source[i - 1];
	}
	revStr[len] = '\0';

	return revStr;
}