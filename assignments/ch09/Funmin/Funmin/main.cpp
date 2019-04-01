#include <iostream>
using namespace std;

int funMin(int arr[], int size); // = int funMin(int* arr, int size);
int main() {
	int arr[5] = { 40, 21, 12, 55, 33 }; // sizeof(arr) = 4*5 = 20byte
	cout << "sizeof(arr): " << sizeof(arr) << endl;
	cout << "최소값의 위치는 " << funMin(arr, 5)  << " 입니다." << endl;
	return 0;
}
int funMin(int arr[], int size) {
	int min = 1000000;
	int position = -1; 
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			if (min == arr[i]) {
				position = i;
			}
		}
	}
	return position;
}