#include <iostream>
using namespace std;
int MidValue(int* arr, int size);
int main() {
	int arr[10] = { 8,10,7,2,16,9,1,0,3,5 };
	int mid = MidValue(arr, 10);
	cout << "mid: " << mid << endl;
	return 0;
}
int MidValue(int* arr, int size) {
	int index, mid;
	int tmp;
	int* midArr = new int[size];
	for (int i = 0; i < size; i++) {
		midArr[i] = arr[i];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (midArr[i] < midArr[j]) {
				tmp = midArr[i];
				midArr[i] = midArr[j];
				midArr[j] = tmp;
			}
		}
	}
	index = int((size - 1) / 2);
	mid = midArr[index];
	delete[] midArr;
	midArr = NULL;
	return mid;
}