#include <iostream>
using namespace std;
int main() {
	/*
	[ C++ ���ڿ� ]
	- char name1[6] =  { 'G', 'r', 'a', 'c', 'e', '\0' }; : ���ڿ� "Grace"
	- char name2[5] =  { 'G', 'r', 'a', 'c', 'e' }; : �ܼ� ���� �迭
	- strcmp() : ���ڿ� ��
	- strlen() : ���ڿ� ����
	- strcpy() : ���ڿ� ����
	*/

	char test[6]; // 5���� ���ڸ� ������ �� �ִ� char �迭
	cin >> test; // Ű���忡�� ���ڿ� �о� name �迭�� ����

	// cin�� �̿��� ���ڿ� �Է�
	cout << "�̸��� �Է��ϼ���: ";
	char name[11]; // �ѱ��� 5�� ����, ������ 10������ ����!!
	cin >> name; // Ű����κ��� ���ڿ� �д´�.
	cout << "�̸��� " << name << "�Դϴ�." << endl;

	// cin.getline() �Լ�
	cout << "cin.getline()���� �̸� �Է�: ";
	char getName[11];
	cin.getline(getName, 11, '\n');
	cout << "����� �̸��� " << getName << "�Դϴ�." << endl;
	
	return 0;
}