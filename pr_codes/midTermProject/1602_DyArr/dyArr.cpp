#include <iostream>
using namespace std;
int* func(int n);
int main() {
	// 1. 동적 메모리 할당
	int size;
	int tot = 0;
	cout << "몇 개의 정수: ";
	cin >> size;
	int* ip = func(size);

	cout << "정수를 입력하시오: ";
	for (int i = 0; i < size; i++) {
		cin >> *(ip + i);
		tot += *(ip + i);
	}
	float avg = (float)tot / (float)size;
	cout << "합: " << tot << endl;
	cout << "평균: " << avg << endl;
	cout << "delete이전 ip: " << ip << endl;
	cout << "delete이전 *ip: " << *ip << endl;

	delete[] ip; ip = NULL;
	cout << "delete이후 ip = " << ip << endl;
	delete[] ip;
	cout << "-----------------------------" << endl;

	// 2. char[] 배열 동적 메모리 할당
	char *cp = new char[20];
	strcpy_s(cp, 20, "hello world");
	
	cout << "sizeof(cp): " << sizeof(cp) << endl; // 포인터의 사이즈
	cout << "strlen(cp): " << strlen(cp) << endl; // 포인터가 가리키는 문자열 사이즈
	cout << "cp: " << cp << endl; // 포인터가 가리키는 문자열 출력
	cout << "----------------------------- " << endl;

	return 0;
}
int* func(int n) {
	int* arr = new int[n];
	return arr;
}