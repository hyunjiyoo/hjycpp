#include <iostream>
using namespace std;
int main() {
	/* �����ͺ������� ���� */
	short sArr[10];
	short* ps1 = &sArr[3];
	short* ps2 = &sArr[7];

	cout << &sArr[0] << endl;
	cout << &sArr[1] << endl;
	cout << &sArr[2] << endl;
	cout << &sArr[3] << endl;
	cout << ps1 << endl;
	cout << ps2 << endl;
	cout << ps2 - ps1 << endl; // 8 / 2byte �ؾ���(short������� 2byte ������)

	cout << "----------------------------------------------------" << endl;

	/* ��ġ����� ��ġ���� */
	int i;
	int* p = &i;
	cout << p << endl;
	cout << p++ << endl; // cout��ü�� p���� �־� ��� ��, p����.
	cout << p << endl;
	cout << ++p << endl; // ���� p�� ������Ų ��, cout��ü�� �־� ���.

	cout << "----------------------------------------------------" << endl;

	int j;
	int* ip = &j;
	cout << ip << endl;
	ip = ip + 1; // ip�� 4byte��ŭ ����
	cout << ip << endl;
	ip = ip - 1; // ip�� 4byte��ŭ ����
	cout << ip << endl;

	return 0;
}