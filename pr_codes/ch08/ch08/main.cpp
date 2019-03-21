#include <iostream>
using namespace std;

int main() {
	// sizeof()
	cout << "sizeof(char) : " << sizeof(char) << endl;
	cout << "sizeof(short) : " << sizeof(short) << endl;
	cout << "sizeof(int) : " << sizeof(int) << endl;
	cout << "sizeof(bool) : " << sizeof(bool) << endl;
	cout << "sizeof(long) : " << sizeof(long) << endl;
	cout << "sizeof(float) : " << sizeof(float) << endl;
	cout << "sizeof(double) : " << sizeof(double) << endl << endl;

	// Array - sizeof, address
	int arrA[3] = { 1,2,3 };
	int arrB[5] = { 5,6,7,8,9 };
	cout << "sizeof(arrA): " << sizeof(arrA) << endl;
	cout << "sizeof(arrB): " << sizeof(arrB) << endl;
	cout << "arrA: " << arrA << endl; // 배열의 시작주소값
	cout << "&arrA[0]: " << &arrA[0] << endl; // 배열의 시작주소값
	cout << "arrA[0]: " << arrA[0] << endl << endl; // 첫번째 배열값

	// arrA = arrB 를 하면 컴파일에러!
	// arrA는 상수포인터. 상수는 값을 받을 수 없다. 5 = 8 (컴파일에러)
	// arrA = arrB; // lvalue error 일어남. *** 배열이름은 포인터 '상수'이다. ***

	// cout은 char*를 만나면 문자열이라고 가정해서 null문자 만날 때까지 출력!!
	char arrC[] = { 'h', 'e', 'l', 'l', 'o' }; // 문자의 배열
	char arrD[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // 문자열 (="hello")
	cout << "(void*)arrD: " << (void*)arrD << endl; // arrD는 원래 (char*)타입인데 (void*)로 형변환!! => 주소값 출력
	cout << "&arrD[0]: " << &arrD[0] << endl; // 주소값이 아닌 문자열 출력
	cout << "(void*)&arrD[0]: " << (void*)&arrD[0] << endl;
	cout << "arrD: " << arrD << endl; 
	cout << "arrD[1]: " << arrD[1] << endl;

	return 0;
}