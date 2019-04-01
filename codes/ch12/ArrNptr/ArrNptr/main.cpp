#include <iostream>
using namespace std;
int main() {
	/* 포인터변수간의 뺄셈 */
	short sArr[10];
	short* ps1 = &sArr[3];
	short* ps2 = &sArr[7];

	cout << "&Arr[0]: " << &sArr[0] << endl; 
	cout << "&Arr[1]: " << &sArr[1] << endl;
	cout << "&Arr[2]: " << &sArr[2] << endl; 
	cout << "&Arr[3]: " << &sArr[3] << endl;
	cout << "ps1: " << ps1 << endl; 
	cout << "ps2: " << ps2 << endl; 
	cout << "ps2 - ps1: " << ps2 - ps1 << endl; // 8 / 2byte 해야함(short사이즈라서 2byte 나눈다)

	cout << "----------------------------------------------------" << endl;

	/* 전치연산과 후치연산 */
	int i;
	int* p = &i;
	cout << p << endl;
	cout << p++ << endl; // cout객체에 p값을 넣어 출력 후, p증가.
	cout << p << endl;
	cout << ++p << endl; // 먼저 p를 증가시킨 후, cout객체에 넣어 출력.

	cout << "----------------------------------------------------" << endl;

	int j;
	int* ip = &j;
	cout << ip << endl;
	ip = ip + 2; // ip는 8byte만큼 증가
	cout << ip << endl;
	ip = ip - 1; // ip는 4byte만큼 감소
	cout << ip << endl;

	return 0;
}