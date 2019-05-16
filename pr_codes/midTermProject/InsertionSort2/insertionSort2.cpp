#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_ARRAY = 6;
void insertionSort(int* A, int lastIndex) {
	int tmp;
	int j;
	for (int i = 1; i <= lastIndex; i++) {
		tmp = A[i];
		for (j = i - 1; j >= 0 && tmp < A[j]; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = tmp;
	}
}
int main() {
	int A[MAX_ARRAY] = { 23,78,45,8,32,56 };
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
	return 0;
}