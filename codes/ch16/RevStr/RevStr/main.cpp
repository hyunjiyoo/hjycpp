#include <iostream>
using namespace std;
/* 중요 예제 */
char* RevStr(char* cp, int n); // Dynami Arr
char* RevStr_static(char* cp, int n); // Static Arr
int main() {
	char org[] = "ABCDE";
	int len = strlen(org);

	// 1. main() 안에서 문자열 reverse
	//char* rev = new char[len + 1]; // 마지막 '\0'도 포함해야 해서 len+1
	//for (int i = 0; i < len; i++) 
	//{
	//	rev[i] = orig[len - i - 1];
	//}
	//rev[len] = '\0';

	// 2. 함수 만들어서 문자열 reverse
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
	for (int i = 0; i < n; i++) 
	{
		rev[i] = cp[n - i - 1];
	}
	rev[n] = '\0';
	return rev;
}
char* RevStr_static(char* cp, int n) {
	// 충분한 큰 공간의 메모리를 확보한다.
	char rev[100];
	for (int i = 0; i < n; i++)
	{
		rev[i] = cp[n - i - 1];
	}
	rev[n] = '\0';
	return rev;
}