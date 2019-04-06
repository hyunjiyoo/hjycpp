#include <iostream>
using namespace std;

// 1. �Ű����� ���޹�� 3����
void sub(int i, int* p, int& r);

// 2. a�� b�� ���ϰ� ���ؼ� �� �����´�
void add_mul(int a, int b, int* p1, int* p2);
void add_mul_by_ref(int a, int b, int& r1, int& r2);

// 3. swap (�� ��ȯ)
void swap_call_by_val(int x, int y);
void swap_call_by_ptr(int* xp, int* yp);
void swap_call_by_ref(int& xr, int& yr);

// 4. �迭 �ѱ涩 call by ptr
// �迭 �ѱ� �� size�� ���� �ѱ�� �� ����. (int�迭�� ���) -> �����͸� ���� ����� ������ �𸣱⶧��
void usingArr(char* p);

int main() {
	cout << "------------------------------" << endl << "1. �Ű����� ���޹�� 3����" << endl << endl;
	// 1. �Ű����� ���޹�� 3����
	int a = 10, b = 20, c = 30;
	sub(a, &b, c); // 'c'�� �״�� �ѱ�� �� ������ int& r = c �� reference������ ������ �ѱ�
	cout << " a : " << a 
		 << " b : " << b 
		 << " c : " << c << endl << endl;

	cout << "------------------------------" << endl << "2. call by pointer" << endl << endl;
	// 2. call by pointer
	int add_value = 0;
	int mul_value = 0;
	int x = 10, y = 2;
	add_mul(x, y, &add_value, &mul_value);
	cout << "add_value: " << add_value << endl;
	cout << "mul_value: " << mul_value << endl;

	cout << "------------------------------" << endl << "3. call by ref" << endl << endl;
	// 3. call by ref
	add_mul_by_ref(x, y, add_value, mul_value);
	cout << "add_value: " << add_value << endl;
	cout << "mul_value: " << mul_value << endl;

	cout << "------------------------------" << endl << "4. swap" << endl << endl;
	// 4. swap
	int u, v;
	cout << "ù��° ��: ";
	cin >> u;
	cout << "�ι�° ��: ";
	cin >> v;

	swap_call_by_val(u, v);
	cout << "call_by_val => " << "u: " << u << " v: " << v << endl; // �ȹٲ�
	swap_call_by_ptr(&u, &v);
	cout << "call_by_ptr => " << "u: " << u << " v: " << v << endl; // �ٲ�
	swap_call_by_ref(u, v);
	cout << "call_by_ref => " << "u: " << u << " v: " << v << endl; // �ٲ�
	
	cout << "------------------------------" << endl << "5. �迭 �ѱ涩 call by ptr" << endl << endl;
	// 5. �迭 �ѱ涩 call by ptr
	char A[20] = "Hello, World!";
	cout << A << endl;
	usingArr(A);
	cout << A << endl;

	return 0;
}
void sub(int i, int* p, int& r)
{
	i = 100;
	*p = 200;
	r = 300;
}

void add_mul(int a, int b, int* p1, int* p2)
{
	*p1 = a + b;
	*p2 = a * b;
}
void add_mul_by_ref(int a, int b, int& r1, int& r2)
{
	r1 = a + b;
	r2 = a * b;
}

void swap_call_by_val(int x, int y)
{
	int tmp;
	tmp = y;
	y = x;
	x = tmp;
}
void swap_call_by_ptr(int* xp, int* yp)
{
	int tmp;
	tmp = *yp;
	*yp = *xp;
	*xp = tmp;
}
void swap_call_by_ref(int& xr, int& yr)
{
	int tmp;
	tmp = yr;
	yr = xr;
	xr = tmp;
}

void usingArr(char* p)
{
	*(p + 12) = '?';
}