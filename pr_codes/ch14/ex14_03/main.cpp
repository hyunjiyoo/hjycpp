#include <iostream>
using namespace std;
/* 중간값 구하기 */
int MidValue(int* arr);
int main() {
	int arr[] = { 9,1,15,3,7 };
	int mid = MidValue(arr);
	cout << "mid: " << mid << endl;
	return 0;
}
int MidValue(int* arr) {
	int mid = 0;
	int tmp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int k = 0; k < 5; k++) {
		cout << arr[k] << endl;
	}
	mid = arr[2];
	return mid;
}