#include <iostream>
#include <cstring>
using namespace std;

char* ShiftRstring(char* source);
int main() {
	char* inputStr = new char[20]; // 20만큼 동적할당 받아서
	cin.getline(inputStr, 20); // 입력을 받는다.

	int len = strlen(inputStr); // 입력받은 배열의 사이즈
	char* preStr = inputStr; // 배열의 주소값을 preStr에 대입
	char* curStr = NULL; // curStr 선언 및 NULL로 초기화
	for (int i = 0; i < len; i++)
	{
		curStr = ShiftRstring(preStr);
		cout << curStr << endl;
		delete preStr; preStr = NULL;
		preStr = curStr; // curStr이 가지고 있는 동적배열 주소값 대입
	}
	delete[] preStr; preStr = NULL; curStr = NULL;
}
char* ShiftRstring(char* source)
{
	int len = strlen(source);
	char* destination = new char[len + 1]; // 배열의 크기는 len + 1
	
	destination[0] = source[len - 1];
	for (int i = 1; i < len; i++) {
		destination[i] = source[i - 1];
	}
	destination[len] = '\0'; // 배열의 마지막 인덱스는 len

	return destination;
}