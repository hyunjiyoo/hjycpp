#include <iostream>
using namespace std;

int main() {
	int A[10] = { -999 }; // 1��°���� ��� 0
	int *p = A; // �Ǵ� int* p = &A[0];


	cout << "1. �迭���� ����� indexǥ��" << endl;
	for (int i = 0; i < 10; i++)
	{
		A[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;


	cout << "2. �迭���� ����� pointerǥ��" << endl;
	for (int i = 0; i < 10; i++)
	{
		*(A + i) = i * i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;


	cout << "3. ������ ������ ����� pointerǥ��" << endl;
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i * i * i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;


	cout << "4. ������ ������ ����� indexǥ��" << endl;
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