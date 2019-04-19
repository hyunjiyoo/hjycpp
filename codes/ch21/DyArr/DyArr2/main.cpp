/* 2019.04.19 ���� */
#include <iostream>
using namespace std;
const int DEFAULT_SIZE = 10;
class DA {
public:
	int* arr; int size;
	DA();
	DA(int arrSize);
	DA(const DA& d);
	~DA();
};
DA::DA()
{
	cout << "���� ���� ������" << endl;
	this->size = DEFAULT_SIZE;
	this->arr = new int[this->size];
}
DA::DA(int arrSize)
{
	cout << "���� �ִ� ������" << endl;
	this->size = arrSize;
	this->arr = new int[this->size];
}
DA::DA(const DA& d)
{
	cout << "���� ������" << endl;
	this->size = d.size;
	this->arr = new int[this->size];
	for (int i = 0; i < d.size; i++) {
		this->arr[i] = d.arr[i]; // *((this->arr) + i) = *(d.arr + i);
	}
}
DA::~DA()
{
	cout << "�Ҹ���" << endl;
	delete[] this->arr;
	this->arr = NULL;
}

// ADT, DA�� Ȱ���� Ŭ���̾�Ʈ�� ����
// **** ��ü�� call by value�� ���� �� ��������� ȣ���!!! ****
// int func(DA &d) { �� �����غ��ÿ�.
int func(DA d) { // call by value �϶��� ��������� �����ϰ� call by ref �϶��� ���� ������ ���� ����..(�߿�!!)
	cout << "in func()" << endl;
	return d.size;
}

DA func2(int i) {
	cout << "in func2()" << endl;
	DA r(i); // ���� �ִ� ������ ȣ��
	return r;
}
int main() {
	cout << "�� ���� ������ �Է��Ͻðڼ�? ";
	int num;
	cin >> num;
	DA d4(num); // ���� �ִ� ������ ȣ��
	for (int i = 0; i < num; i++) {
		cout << "�Է�: ";
		cin >> d4.arr[i]; // *(d4.arr + i)
	}

	// �Ű������� ��ü�� �Ѱ���
	int n = func(d4); // ���� ������ ȣ��
	// d�� �Ҹ��� ȣ��
	cout << "n: " << n << endl;

	// int�� �Ű������� �Ѱ��ְ� ��ü�� ����!!
	DA d5 = func2(3); // ��ü�� ������ ���� ��������� ȣ��
	// �Ҹ���
	// �Ҹ���
	// �Ҹ���

	/* 1.
	DA d1;
	DA d2(5);
	DA d3(d2);
	*/
	return 0;
}