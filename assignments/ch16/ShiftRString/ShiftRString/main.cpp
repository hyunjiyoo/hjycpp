#include <iostream>
using namespace std;
char* ShiftRstring(char* str, int len, int loop);
int main() {
	char str[] = "Stay hungry! Stay foolish!!!";
	int len = strlen(str);
	
	for (int i = 0; i < len + 1; i++) {
		char* Rstr = ShiftRstring(str, len, i);
		cout << Rstr << endl;
		delete[] Rstr;
		Rstr = NULL;
	}
	return 0;
}
char* ShiftRstring(char* str, int len, int loop) {
	char* ShiftStr = new char[len + 1];
	char tmp;
	strcpy_s(ShiftStr, len + 1, str);

	for (int i = 0; i < loop; i++) {
		tmp = ShiftStr[0]; 
		for (int j = 1; j < len; j++) {
			ShiftStr[j-1] = ShiftStr[j];
		}
		ShiftStr[len-1] = tmp;
	}
	
	ShiftStr[len] = NULL;
	return ShiftStr;
}