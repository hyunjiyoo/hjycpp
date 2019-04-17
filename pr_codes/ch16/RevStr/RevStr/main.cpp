#include <iostream>
using namespace std;
char* RevStr(char* cp, int n); // Dynamic Arr
char* RevStr_static(char* cp, int n); // Static Arr
int main() {
	char org[] = "ABCDE";
	int len = strlen(org); // 5

	/* 1.main() �ȿ��� ���ڿ� reverse */
	/*char* rev = new char[len + 1];
	for (int i = 0; i < len; i++) {
		rev[i] = org[len - i - 1];
	}
	rev[len] = '\0';*/

	/* 2.�Լ� ���� ���ڿ� reverse */
	char* rev = RevStr(org, len);
	// char* rev = RevStr_static(org, len);
	// RevStr_static �����鼭 pop() �Ͼ�鼭 reverse�� ���ڿ� �����.
	// �׷��� rev�� �𸣴� �ּ� ��.
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
	char rev[100]; // ����� ū �޸� Ȯ��
	for (int i = 0; i < n; i++) {
		rev[i] = cp[n - 1 - i];
	}
	rev[n] = '\0';
	return rev;
}