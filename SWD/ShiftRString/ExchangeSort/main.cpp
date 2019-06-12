#include <iostream>
using namespace std;
const int MAX = 6;
void ExchangeSort(int* num, int len)
{
	int i, j;
	int tmp; 
	for (i = 0; i < len - 1; i++)  
	{
		for (j = i + 1; j < len; j++)  
		{
			if (num[i] > num[j])        
			{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
}
int main()
{
	int A[MAX] = { 23,52,12,10,31,5 };
	cout << "소트되지 않은 배열: " << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << A[i] << "   ";
	}
	cout << endl << endl;

	cout << "소트된 배열: " << endl;
	ExchangeSort(A, MAX);
	for (int i = 0; i < MAX; i++)
	{
		cout << A[i] << "   ";
	}
	cout << endl;

	return 0;
}