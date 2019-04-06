#include <iostream>
using namespace std;

int main() {
	int A[10] = { -999 }; // 1번째부터 모두 0
	int *p = A; // 또는 int* p = &A[0];


	cout << "1. 배열명을 사용한 index표현" << endl;
	for (int i = 0; i < 10; i++)
	{
		A[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;


	cout << "2. 배열명을 사용한 pointer표현" << endl;
	for (int i = 0; i < 10; i++)
	{
		*(A + i) = i * i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;


	cout << "3. 포인터 변수를 사용한 pointer표현" << endl;
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i * i * i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;


	cout << "4. 포인터 변수를 사용한 index표현" << endl;
	for (int i = 0; i < 10; i++)
	{
		p[i] = i * i * i * i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;

	return 0;
}