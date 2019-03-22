/* 요소에 접근하기 */
#include <iostream>
using namespace std;
int main() {
	int A[10] = { -999 }; // A[0]만 '-999'이고 나머지는 '0'으로 초기화
	cout << "sizeof(A): " << sizeof(A) << endl; // 40byte

	int* p = A; // int* p = &A[0];
	cout << "1.배열명을 사용한 index 표현: " << endl;
	cout << "2.배열명을 사용한 poiter 표현: " << endl;
	cout << "3.포인터변수를 사용한 pointer 표현: " << endl;
	cout << "p: " << p << endl;
	cout << "4.포인터변수를 사용한 index 표현: " << endl;

	// *(p+i)
	// p + i 를 보이고 요소 하나하나를  i*i*i로 채우기
	for (int i = 0; i < 10; i++) {
		cout << "p + " << i << ": " << p + i << endl;
		cout << "*(p + " << i << "): " << *(p + i) << '\n' << endl;
		*(p + i) = i*i*i;
	}
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}