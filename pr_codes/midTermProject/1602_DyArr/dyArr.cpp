#include <iostream>
using namespace std;
int* func(int n);
int main() {
	// 1. ���� �޸� �Ҵ�
	int size;
	int tot = 0;
	cout << "�� ���� ����: ";
	cin >> size;
	int* ip = func(size);

	cout << "������ �Է��Ͻÿ�: ";
	for (int i = 0; i < size; i++) {
		cin >> *(ip + i);
		tot += *(ip + i);
	}
	float avg = (float)tot / (float)size;
	cout << "��: " << tot << endl;
	cout << "���: " << avg << endl;
	cout << "delete���� ip: " << ip << endl;
	cout << "delete���� *ip: " << *ip << endl;

	delete[] ip; ip = NULL;
	cout << "delete���� ip = " << ip << endl;
	delete[] ip;
	cout << "-----------------------------" << endl;

	// 2. char[] �迭 ���� �޸� �Ҵ�
	char *cp = new char[20];
	strcpy_s(cp, 20, "hello world");
	
	cout << "sizeof(cp): " << sizeof(cp) << endl; // �������� ������
	cout << "strlen(cp): " << strlen(cp) << endl; // �����Ͱ� ����Ű�� ���ڿ� ������
	cout << "cp: " << cp << endl; // �����Ͱ� ����Ű�� ���ڿ� ���
	cout << "----------------------------- " << endl;

	return 0;
}
int* func(int n) {
	int* arr = new int[n];
	return arr;
}