#include <iostream>
using namespace std;
int main() {

	// 문자열상수로 초기화
	char ch = 65; // 'A' 출력!! (char타입도 결국 정수로 저장되어 있음)
	int i = 65;
	cout << "i: " << i << " ch: " << ch << endl;
	char str[] = "Alpha Go"; // '문자열상수'를 이용해 char배열 초기화
	cout << "strlen(str): " << strlen(str) << endl; // 8
	cout << "sizeof(str): " << sizeof(str) << endl; // 9 (Null문자 포함)
	cout << "--------------------------------------------" << endl;

	// Array - sizeof, address
	int arrA[3] = { 1,2,3 };
	int arrB[5] = { 5,6,7,8,9 };
	cout << "sizeof(arrA): " << sizeof(arrA) << endl;
	cout << "sizeof(arrB): " << sizeof(arrB) << endl;
	cout << "arrA: " << arrA << endl; // 배열의 시작주소값
	cout << "&arrA[0]: " << &arrA[0] << endl; // 배열의 시작주소값
	cout << "arrA[0]: " << arrA[0] << endl; // 첫번째 배열값
	cout << "--------------------------------------------" << endl;

	// arrA = arrB 를 하면 컴파일에러! 
	// arrA는 상수포인터. 상수는 값을 받을 수 없다. 5 = 8 (컴파일에러)
	// arrA = arrB; // lvalue error 일어남. *** 배열이름은 포인터 '상수'이다. ***

	// cout은 char*를 만나면 문자열이라고 가정해서 null문자 만날 때까지 출력!!
	char arrC[] = { 'h', 'e', 'l', 'l', 'o' }; // 문자의 배열
	char arrD[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // 문자열
	cout << "(void *)arrC: " << (void *)arrC << endl; // arrC는 원래 (char*)타입인데 (void*)로 형변환!! => 주소값 출력
	cout << "&arrC[0]: " << &arrC[0] << endl; // helloakfjasdlkfj* (arrC[0]는 char타입 || &arrC[0]는 (char *)타입)
	cout << "(void *)&arrC[0]: " << (void *)&arrC[0] << endl; 
	cout << "arrC: " << arrC << endl; // null문자 없어서 garbage값 나옴.
	cout << "(void *)arrD: " << (void *)arrD << endl;
	cout << "arrD: " << arrD << endl; // null문자 있으니까 'hello'하고 끝남.
	cout << "--------------------------------------------" << endl;

	cout << "sizeof(char) : " << sizeof(char) << endl; // 1
	cout << "sizeof(short) : " << sizeof(short) << endl; // 2
	cout << "sizeof(int) : " << sizeof(int) << endl; // 4
	cout << "sizeof(bool) : " << sizeof(bool) << endl; // 1
	cout << "sizeof(long) : " << sizeof(long) << endl; // 4
	cout << "sizeof(float) : " << sizeof(float) << endl; // 4
	cout << "sizeof(double) : " << sizeof(double) << endl; // 8

	return 0;
}