#include <iostream>
using namespace std;
double area(int r); // �Լ��� ����(declaration)(����)
int main() {
	// 1.��� ����
	int n = 3; char c = '#';
	cout << c << 5.5 << '-' << endl;
	// boolalpha : 'true'�� 1�� ��Ÿ�����ʰ� 'true' �״�� ���.
	cout << boolalpha << true << "hello world" << endl;
	cout << "n + 5 = " << n + 5 << endl;
	// area(n) : �Լ��� call
	cout << "������ " << area(n) << endl;
	cout << "stdio ex" << endl;

	// 2.�Է� ����
	cout << "�ʺ� : ";
	int width;
	cin >> width;
	cout << "���� : ";
	int height;
	cin >> height;
	cout << "���� : " << width * height << endl;

	// 3.���ڿ� �Է� ����
	// �̸�: '���� ��'��� �Է��ϸ� '����'�� ����. (delimit������ '����'���� �߸�)
	cout << "�̸��Է� : ";
	char gname[100];
	cin >> gname;
	cout << "����� �̸��� " << gname << " �Դϴ�." << endl;

	// 4.cin.getline() �Լ� ����
	cout << "�̸��Է� : ";
	char name[10]; // 0123456789012 �Է½�, 012345678 ���� ��� (size 10 ������ index 9 �� ���� ����)
	cin.getline(name, 10, '\n');
	cout << "����� �̸��� " << name << " �Դϴ�." << endl;

	return 0;
}
// �Լ��� ����(definition)
double area(int r) {
	return 3.14*r*r;
}