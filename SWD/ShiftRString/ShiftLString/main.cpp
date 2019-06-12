#include <iostream>
using namespace std;
char* ShiftLstring(char* source);
int main()
{
	char* input = new char[20];
	cin.getline(input, 20);
	int len = strlen(input);
	char* preStr = input;
	char* curStr = NULL;

	for (int i = 0; i < len; i++)
	{
		curStr = ShiftLstring(preStr);
		cout << curStr << endl;
		delete preStr; preStr = NULL;
		preStr = curStr;
	}
	delete preStr; preStr = NULL; curStr = NULL;
	return 0;
}
char* ShiftLstring(char* source)
{
	int len = strlen(source);
	char* mvStr = new char[len + 1];
	
	mvStr[len - 1] = source[0];
	for (int i = 1; i < len; i++)
	{
		mvStr[i - 1] = source[i];
	}
	mvStr[len] = '\0';
	return mvStr;
}