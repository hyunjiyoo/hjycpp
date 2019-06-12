#include <iostream>
using namespace std;
const int MAX = 6;
void insertionSort(int* A, int lastIndex)
{
	// int* A = A; int lastIndex = 6;
	int tmp;
	int j;
	for (int i = 1; i <= lastIndex; i++)
	{
		tmp = A[i]; // 배열 첫번째를 tmp에 넣고
		for (j = i - 1; j >= 0 && tmp < A[j]; j--)
		{
			A[j + 1] = A[j]; // swap
		}
		A[j + 1] = tmp;
	}
}
int main()
{
	int A[MAX] = { 23,52,12,10,3,5 };
	cout << "소트되지 않은 배열: " << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << A[i] << "   ";
	}
	cout << endl << endl;

	cout << "소트된 배열: " << endl;
	insertionSort(A, MAX - 1);
	for (int i = 0; i < MAX; i++)
	{
		cout << A[i] << "   ";
	}
	cout << endl;

	return 0;
}