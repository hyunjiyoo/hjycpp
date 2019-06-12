#include<iostream>
using namespace std;
//void swapping(int &a, int &b) {        
//	int tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}
void selectionSort(int *arr, int size) {
	int i, j, imin, tmp;
	for (i = 0; i < size - 1; i++) {
		imin = i;   //get index of minimum data
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[imin])
				imin = j;
		tmp = arr[i];
		arr[i] = arr[imin];
		arr[imin] = tmp;
	}
}
int main() {
	int arr[5] = { 95,52,16,23,46 };    
	cout << "Array before Sorting: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";

	cout << endl << endl;

	selectionSort(arr, 5);
	cout << "Array after Sorting: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
}