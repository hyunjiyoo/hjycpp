#include <iostream>
using namespace std;
int* func(int n);
int main() {
	/* 1.동적 메모리 할당 */
	int size;
	int tot = 0;
	cout << "몇 개의 정수: ";
	cin >> size;
	// int* ip = new int[size];
	// size크기의 메모리를 할당하여 그 시작 주소를 return하는 함수 call.
	// new int[]는 func()에서 하고, delete[]는 main()에서 해도 상관없다!!
	int* ip = func(size);

	cout << "정수를 입력하시오: ";
	for (int i = 0; i < size; i++) {
		cin >> *(ip + i);
		tot += *(ip + i);
	}
	float avg = (float)tot / (float)size;
	cout << "합: " << tot << endl;
	cout << "평균: " << avg << endl;
	cout << "delete 이전 ip: " << ip << endl;
	cout << "delete 이전 *ip: " << *ip << endl;
	delete[] ip; // ip가 가리키는 배열은 사라지고 ip의 값이 바뀜
	ip = NULL;
	cout << "delete 이후 ip " << ip << endl;
	delete[] ip;

	/* 2.char[] 배열 동적 메모리 할당!! (중요) */
	char str[] = "hello";
	char *cp = new char[20];
	cp = str;
	cout << "sizeof(cp): " << sizeof(cp) << endl; // cp는 포인터변수라서 4byte
	cout << "strlen(cp): " << strlen(cp) << endl; // '\0' 나올때까지 size 측정(5)
	cout << "cp: " << cp << endl; // 문자열 출력("hello")

	/* 3.new, delete */
	int* p = new int;
	*p = -888;
	cout << "p: " << p << " *p: " << *p << endl;
	delete p; p = NULL;
	cout << "p: " << p << endl;
	
	return 0;
}
int* func(int n) {
	int* tp = new int[n];
	return tp;
}