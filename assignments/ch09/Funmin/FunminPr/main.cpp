#include <iostream>
using namespace std;

int funMin(int arr[], int size); // = int funMin(int* arr, int size);
int main() {
	int arr[] = { 6, 1, 4 }; // sizeof(arr) = 4*5 = 20byte
	cout << "sizeof(arr): " << sizeof(arr) << endl;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "main_n: " << n << endl; // 5

	cout << "최소값의 위치는 " << funMin(arr, n) << " 입니다." << endl;
	return 0;
}

int funMin(int arr[], int size) { // 매개변수로 넘어온 arr은 포인터변수로 받는다. 
	int min = 1000000;
	int position = -1;
	// sizeof(arr)은 포인터사이즈라서 1byte이다. 그래서 n = 1
	// 그래서 반드시 배열의 size도 매개변수로 함께 넘겨주어야 함.
	int n = sizeof(arr) / sizeof(int); 
	cout << "n: " << n << endl; // 1

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

/*
- 매개변수도 지역변수
- 지역변수란, 스택메모리에 push되었다가 pop되는 변수.
*/