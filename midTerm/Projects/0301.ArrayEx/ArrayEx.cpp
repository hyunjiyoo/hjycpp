#include <iostream>
using namespace std;
int main() {

	// ���ڿ������ �ʱ�ȭ
	char ch = 65; // 'A' ���!! (charŸ�Ե� �ᱹ ������ ����Ǿ� ����)
	int i = 65;
	cout << "i: " << i << " ch: " << ch << endl;
	char str[] = "Alpha Go"; // '���ڿ����'�� �̿��� char�迭 �ʱ�ȭ
	cout << "strlen(str): " << strlen(str) << endl; // 8
	cout << "sizeof(str): " << sizeof(str) << endl; // 9 (Null���� ����)
	cout << "--------------------------------------------" << endl;

	// Array - sizeof, address
	int arrA[3] = { 1,2,3 };
	int arrB[5] = { 5,6,7,8,9 };
	cout << "sizeof(arrA): " << sizeof(arrA) << endl;
	cout << "sizeof(arrB): " << sizeof(arrB) << endl;
	cout << "arrA: " << arrA << endl; // �迭�� �����ּҰ�
	cout << "&arrA[0]: " << &arrA[0] << endl; // �迭�� �����ּҰ�
	cout << "arrA[0]: " << arrA[0] << endl; // ù��° �迭��
	cout << "--------------------------------------------" << endl;

	// arrA = arrB �� �ϸ� �����Ͽ���! 
	// arrA�� ���������. ����� ���� ���� �� ����. 5 = 8 (�����Ͽ���)
	// arrA = arrB; // lvalue error �Ͼ. *** �迭�̸��� ������ '���'�̴�. ***

	// cout�� char*�� ������ ���ڿ��̶�� �����ؼ� null���� ���� ������ ���!!
	char arrC[] = { 'h', 'e', 'l', 'l', 'o' }; // ������ �迭
	char arrD[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; // ���ڿ�
	cout << "(void *)arrC: " << (void *)arrC << endl; // arrC�� ���� (char*)Ÿ���ε� (void*)�� ����ȯ!! => �ּҰ� ���
	cout << "&arrC[0]: " << &arrC[0] << endl; // helloakfjasdlkfj* (arrC[0]�� charŸ�� || &arrC[0]�� (char *)Ÿ��)
	cout << "(void *)&arrC[0]: " << (void *)&arrC[0] << endl; 
	cout << "arrC: " << arrC << endl; // null���� ��� garbage�� ����.
	cout << "(void *)arrD: " << (void *)arrD << endl;
	cout << "arrD: " << arrD << endl; // null���� �����ϱ� 'hello'�ϰ� ����.
	cout << "--------------------------------------------" << endl;

	cout << "sizeof(char) : " << sizeof(char) << endl; // 1
	cout << "sizeof(short) : " << sizeof(short) << endl; // 2
	cout << "sizeof(int) : " << sizeof(int) << endl; // 4
	cout << "sizeof(bool) : " << sizeof(bool) << endl; // 1
	cout << "sizeof(long) : " << sizeof(long) << endl; // 4
	cout << "sizeof(float) : " << sizeof(float) << endl; // 4
	cout << "sizeof(double) : " << sizeof(double) << endl; // 8

	return 0;
}