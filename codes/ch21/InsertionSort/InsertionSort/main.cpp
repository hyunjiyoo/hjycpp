#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_ARRAY = 6;
void insertionSort(int* A, int lastIndex) {
	int curr;
	int hold;
	int walker;
	for (curr = 1; curr <= lastIndex; curr++) 
	{
		hold = A[curr];
		for (walker = curr - 1; walker >= 0 && hold < A[walker]; walker--) 
		{
			A[walker + 1] = A[walker];
		}
		A[walker + 1] = hold;
	}
}
int main() {
	int A[MAX_ARRAY] = { 23, 78, 45, 8, 32, 56 };
	cout << "소트되지 않은 배열: " << endl;
	for (int i = 0; i < MAX_ARRAY; i++) {
		cout << setw(3) << A[i];
	}
	cout << endl << endl;

	cout << "소트된 배열: " << endl;
	insertionSort(A, MAX_ARRAY - 1);
	for (int i = 0; i < MAX_ARRAY; i++) {
		cout << setw(3) << A[i];
	}
	cout << endl;

	return 0;
}