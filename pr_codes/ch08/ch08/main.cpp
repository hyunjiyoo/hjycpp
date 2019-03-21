#include <iostream>
using namespace std;

int main() {
	// sizeof()
	cout << "sizeof(char) : " << sizeof(char) << endl;
	cout << "sizeof(short) : " << sizeof(short) << endl;
	cout << "sizeof(int) : " << sizeof(int) << endl;
	cout << "sizeof(bool) : " << sizeof(bool) << endl;
	cout << "sizeof(long) : " << sizeof(long) << endl;
	cout << "sizeof(float) : " << sizeof(float) << endl;
	cout << "sizeof(double) : " << sizeof(double) << endl << endl;

	// Array - sizeof, address
	int arrA[3] = { 1,2,3 };
	int arrB[5] = { 5,6,7,8,9 };
	cout << "sizeof(arrA): " << sizeof(arrA) << endl;
	cout << "sizeof(arrB): " << sizeof(arrB) << endl;
	cout << "arrA: " << arrA << endl; // �迭�� �����ּҰ�
	cout << "&arrA[0]: " << &arrA[0] << endl; // �迭�� �����ּҰ�
	cout << "arrA[0]: " << arrA[0] << endl << endl; // ù��° �迭��

	// arrA = arrB �� �ϸ� �����Ͽ���!
	// arrA�� ���������. ����� ���� ���� �� ����. 5 = 8 (�����Ͽ���)
	// arrA = arrB; // lvalue error �Ͼ. *** �迭�̸��� ������ '���'�̴�. ***

	// cout�� char*�� ������ ���ڿ��̶�� �����ؼ� null���� ���� ������ ���!!
	char arrC[] = { 'h', 'e', 'l', 'l', 'o' }; // ������ �迭
	char arrD[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // ���ڿ� (="hello")
	cout << "(void*)arrD: " << (void*)arrD << endl; // arrD�� ���� (char*)Ÿ���ε� (void*)�� ����ȯ!! => �ּҰ� ���
	cout << "&arrD[0]: " << &arrD[0] << endl; // �ּҰ��� �ƴ� ���ڿ� ���
	cout << "(void*)&arrD[0]: " << (void*)&arrD[0] << endl;
	cout << "arrD: " << arrD << endl; 
	cout << "arrD[1]: " << arrD[1] << endl;

	return 0;
}