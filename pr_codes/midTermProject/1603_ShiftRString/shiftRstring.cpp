#include <iostream>
#include <cstring>
using namespace std;

char* ShiftRstring(char* source);
int main() {
	char* inputStr = new char[20]; // 20��ŭ �����Ҵ� �޾Ƽ�
	cin.getline(inputStr, 20); // �Է��� �޴´�.

	int len = strlen(inputStr); // �Է¹��� �迭�� ������
	char* preStr = inputStr; // �迭�� �ּҰ��� preStr�� ����
	char* curStr = NULL; // curStr ���� �� NULL�� �ʱ�ȭ
	for (int i = 0; i < len; i++)
	{
		curStr = ShiftRstring(preStr);
		cout << curStr << endl;
		delete preStr; preStr = NULL;
		preStr = curStr; // curStr�� ������ �ִ� �����迭 �ּҰ� ����
	}
	delete[] preStr; preStr = NULL; curStr = NULL;
}
char* ShiftRstring(char* source)
{
	int len = strlen(source);
	char* destination = new char[len + 1]; // �迭�� ũ��� len + 1
	
	destination[0] = source[len - 1];
	for (int i = 1; i < len; i++) {
		destination[i] = source[i - 1];
	}
	destination[len] = '\0'; // �迭�� ������ �ε����� len

	return destination;
}