#include <iostream>
using namespace std;
int main() {
	int a = 200;
	int b = 30;
	double c = 56789000;
	int* ip = &a;
	int* ip2 = &b;
	double* dp = &c;
	char d = 'A';
	void* vp = ip;
	*ip2 = 33;

	cout << dp << endl;
	cout << *ip2 << endl;
	cout << &b << endl;
	cout << sizeof(dp) << endl;
	cout << &d << endl;

	return 0;
}