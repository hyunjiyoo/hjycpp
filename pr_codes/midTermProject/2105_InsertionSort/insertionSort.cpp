#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_ARRAY = 6;
void insertionSort(int* A, int size) {
	int tmp = A[1]; // A배열의 첫번째 값 tmp에 넣기
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] > tmp) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
		tmp = A[i + 1];
	}
}
int main() {
	int A[MAX_ARRAY] = { 28,25,62,13,2,48 };
	cout << "소트되지 않은 배열: " << endl;
	for (int i = 0; i < MAX_ARRAY; i++) {
		cout << setw(3) << A[i];
	}
	cout << endl << endl;
	cout << "소트된 배열: " << endl;
	insertionSort(A, MAX_ARRAY);
	for (int i = 0; i < MAX_ARRAY; i++) {
		cout << setw(3) << A[i];
	}
	return 0;
}