#include <iostream>
using namespace std;
int main() {
	int target = 20;
	int& ref = target; // ���� �� �ʱ�ȭ
	int* ip = &target;
	int b = 500;
	ref = b; // ����

	cout << "    ref: " << ref << endl; // 500
	cout << " target: " << target << endl; // 500
	cout << "    *ip: " << *ip << endl << endl; // 500
	
	cout << "   &ref: " << &ref << endl;
	cout << "&target: " << &target << endl;
	cout << "     ip: " << ip << endl;

	cout << "----------------" << endl;
	int A[5] = { 0, };
	int* p = A;

	cout << "sizeof(A): " << sizeof(A) << endl; // 20 byte
	cout << "sizeof(p): " << sizeof(p) << endl; // 4 byte
	cout << "A: " << A << endl; // =p
	cout << "p: " << p << endl; // =A

	return 0;
}