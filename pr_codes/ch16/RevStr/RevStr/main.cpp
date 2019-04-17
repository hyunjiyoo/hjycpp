#include <iostream>
using namespace std;
char* RevStr(char* cp, int n); // Dynamic Arr
char* RevStr_static(char* cp, int n); // Static Arr
int main() {
	char org[] = "ABCDE";
	int len = strlen(org); // 5

	/* 1.main() 안에서 문자열 reverse */
	/*char* rev = new char[len + 1];
	for (int i = 0; i < len; i++) {
		rev[i] = org[len - i - 1];
	}
	rev[len] = '\0';*/

	/* 2.함수 만들어서 문자열 reverse */
	char* rev = RevStr(org, len);
	// char* rev = RevStr_static(org, len);
	// RevStr_static 끝나면서 pop() 일어나면서 reverse된 문자열 사라짐.
	// 그래서 rev에 모르는 주소 들어감.
	cout << "org: " << org << endl;
	cout << "rev: " << rev << endl;
	delete[] rev; rev = NULL;

	return 0;
}
char* RevStr(char* cp, int n) {
	char* rev = new char[n + 1];
	for (int i = 0; i < n; i++) {
		rev[i] = cp[n - 1 - i];
	}
	rev[n] = '\0';
	return rev;
}
char* RevStr_static(char* cp, int n) {
	char rev[100]; // 충분히 큰 메모리 확보
	for (int i = 0; i < n; i++) {
		rev[i] = cp[n - 1 - i];
	}
	rev[n] = '\0';
	return rev;
}