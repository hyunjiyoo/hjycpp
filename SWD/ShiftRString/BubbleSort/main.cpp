#include <iostream>
using namespace std;
const int MAX = 6;

void bubbleSort(int* arr, int n)
{
	int i, j, tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
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
	bubbleSort(A, MAX);
	for (int i = 0; i < MAX; i++)
	{
		cout << A[i] << "   ";
	}
	cout << endl;

	return 0;
}