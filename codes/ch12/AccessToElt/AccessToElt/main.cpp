/* ��ҿ� �����ϱ� */
#include <iostream>
using namespace std;
int main() {
	int A[10] = { -999 }; // A[0]�� '-999'�̰� �������� '0'���� �ʱ�ȭ
	cout << "sizeof(A): " << sizeof(A) << endl; // 40byte

	int* p = A; // int* p = &A[0];
	cout << "1.�迭���� ����� index ǥ��: " << endl;
	cout << "2.�迭���� ����� poiter ǥ��: " << endl;
	cout << "3.�����ͺ����� ����� pointer ǥ��: " << endl;
	cout << "p: " << p << endl;
	cout << "4.�����ͺ����� ����� index ǥ��: " << endl;

	// *(p+i)
	// p + i �� ���̰� ��� �ϳ��ϳ���  i*i*i�� ä���
	for (int i = 0; i < 10; i++) {
		cout << "p + " << i << ": " << p + i << endl;
		cout << "*(p + " << i << "): " << *(p + i) << '\n' << endl;
		*(p + i) = i*i*i;
	}
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}