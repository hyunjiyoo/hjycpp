#include <iostream>
using namespace std;

int funMin(int arr[], int size); // = int funMin(int* arr, int size);
int main() {
	int arr[] = { 6, 1, 4 }; // sizeof(arr) = 4*5 = 20byte
	cout << "sizeof(arr): " << sizeof(arr) << endl;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "main_n: " << n << endl; // 5

	cout << "�ּҰ��� ��ġ�� " << funMin(arr, n) << " �Դϴ�." << endl;
	return 0;
}

int funMin(int arr[], int size) { // �Ű������� �Ѿ�� arr�� �����ͺ����� �޴´�. 
	int min = 1000000;
	int position = -1;
	// sizeof(arr)�� �����ͻ������ 1byte�̴�. �׷��� n = 1
	// �׷��� �ݵ�� �迭�� size�� �Ű������� �Բ� �Ѱ��־�� ��.
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
- �Ű������� ��������
- ����������, ���ø޸𸮿� push�Ǿ��ٰ� pop�Ǵ� ����.
*/