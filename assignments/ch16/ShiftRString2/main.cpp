#include <iostream>
#include <cstring>
using namespace std;

char* ShiftRstring(char* source);
int main() {
	char* inputStr = new char[20];
	cin.getline(inputStr, 20);

	int len = strlen(inputStr);
	char* preStr = inputStr;
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
char* ShiftRstring(char* source) {
	int len = strlen(source);
	char *destination = new char[len + 1];

	destination[0] = source[len - 1];
	for (int i = 1; i < len; i++)
		destination[i] = source[i - 1];
	destination[len] = '\0';

	return destination;
}