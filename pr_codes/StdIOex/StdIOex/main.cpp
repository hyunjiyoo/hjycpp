#include <iostream>

double area(int r); // �Լ��� ���� ���� (declaration)
int main() {
	/*
	[ cout ��ü ]
	- ��ũ�� �����ġ�� ����� ǥ�� C++ ��� ��Ʈ�� ��ü
	- <iostream> ������Ͽ� ����
	- std �̸� ������ ����: std::cout���� ���
	
	[ << ������ ]
	- ��Ʈ�� ���� ������ (stream insertion operator)
	- C++ �⺻ ��� ����Ʈ ������(<<)�� '��Ʈ�� ���� ������'�� �����ǵ�
	- ostream Ŭ������ ������
	- ������ �ǿ����ڸ� ���� ��Ʈ�� ��ü(std::cout)�� ����
	- cout ��ü�� ����� ȭ�鿡 ���
	- �������� << �����ڷ� ������ ���
	*/

	// ���ڿ� �� �⺻ Ÿ���� ������ ���
	int n = 3; char c = '#';
	std::cout << "�⺻Ÿ�� ������ ���: " << c << 5.5 << '-' << n << "hello" << std::endl;
	
	// std::boolalpha ���
	std::cout << "boolalpha ���X: " << true << std::endl; // 1
	std::cout << "boolalpha ���O: " << std::boolalpha << true << std::endl; // true

	// �����ٷ� �Ѿ�� '\n'�� std::endl ���
	std::cout << '\n' << std::endl;

	// ����Ļ� �ƴ϶� �Լ� ȣ�⵵ ����
	std::cout << "����� ���: " << "n + 5 = " << n + 5;
	std::cout << "�Լ��� ���ϰ� ���: " << area(n); // �Լ� area(3)�� ���ϰ� ���
	
	return 0;
}

// �Լ��� ���� (definition)
double area(int r) {
	return 3.14*r*r;
}