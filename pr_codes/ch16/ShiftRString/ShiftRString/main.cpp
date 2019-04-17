#include <iostream>
using namespace std;
char* ShiftRstring(char* str, int n);
const int SIZE = 20;

int main() {
	cout << "문자열을 입력하시오: ";
	char str[SIZE];
	cin.getline(str, SIZE);
	int len = strlen(str);
	char* Rstr = ShiftRstring(str, len);
	delete[] Rstr; Rstr = NULL;

	return 0;
}

char* ShiftRstring(char* str, int n) {
	char* ShiftStr = new char[n+1];
	char tmp = NULL;
	strcpy_s(ShiftStr, n+1, str);

	for (int i = 0; i < n + 1; i++) {
		cout << ShiftStr << endl;
		tmp = ShiftStr[0];
		for (int j = 1; j < n; j++) {
			ShiftStr[j - 1] = ShiftStr[j];
		}
		ShiftStr[n - 1] = tmp;
		ShiftStr[n] = '\0';
	}
	return ShiftStr;
}