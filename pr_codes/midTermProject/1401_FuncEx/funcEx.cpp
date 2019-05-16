#include <iostream>
#include <iomanip>
using namespace std;
// 1. 매개변수 전달방식 3가지
void sub(int i, int* p, int& r);
// 2. a와 b를 합하고 곱해서 값 가져온다.
void add_mul(int a, int b, int* p1, int* p2);
void add_mul_by_ref(int a, int b, int& r1, int& r2);

// 3. swap (값 교환)
void swap_call_by_val(int x, int y);
void swap_call_by_ptr(int* xp, int* yp);
void swap_call_by_ref(int& xr, int& yr);

// 4. 배열 넘길땐 call by ptr
void usingArr(char* p);
int main() {
	cout << "--------------------------------" << endl;
	// 1. 매개변수 전달방식 3가지
	int a = 10, b = 20, c = 30;
	sub(a, &b, c);
	cout << "a: " << a << " b:" << b << " c: " << c << endl;

	cout << "--------------------------------" << endl;
	// 2. call by pointer
	int add_value = 0;
	int mul_value = 0;
	int x = 10, y = 2;
	add_mul(x, y, &add_value, &mul_value);
	cout << "add_value: " << add_value << endl;
	cout << "mul_value: " << mul_value << endl;

	cout << "--------------------------------" << endl;
	// 3. call by reference
	add_mul_by_ref(x, y, add_value, mul_value);
	cout << "add_value: " << add_value << endl;
	cout << "mul_value: " << mul_value << endl;

	cout << "--------------------------------" << endl;
	// 4. swap
	int u, v;
	cout << "첫번째 수: ";
	cin >> u;
	cout << "두번째 수: ";
	cin >> v;

	swap_call_by_val(u, v);
	cout << "call_by_Val => " << "u: " << u << " v: " << v << endl;
	swap_call_by_ptr(&u, &v);
	cout << "call_by_Val => " << "u: " << u << " v: " << v << endl;
	swap_call_by_ref(u, v);
	cout << "call_by_Val => " << "u: " << u << " v: " << v << endl;

	cout << "--------------------------------" << endl;
	// 5. 배열 넘길 땐 call by ptr
	char A[20] = "Hello, World!";
	cout << A << endl;
	usingArr(A);
	cout << A << endl;

	return 0;
}
void sub(int i, int* p, int& r) {
	i = 100;
	*p = 200;
	r = 300;
}
void add_mul(int a, int b, int* p1, int* p2) {
	*p1 = a + b;
	*p2 = a * b;
}
void add_mul_by_ref(int a, int b, int& r1, int& r2) {
	r1 = a + b;
	r2 = a * b;
}
void swap_call_by_val(int x, int y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
void swap_call_by_ptr(int* xp, int* yp) {
	int tmp;
	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}
void swap_call_by_ref(int& xr, int& yr) {
	int tmp;
	tmp = xr;
	xr = yr;
	yr = tmp;
}
void usingArr(char* p) {
	p[12] = '?'; // *(p + 12) = '?'
}