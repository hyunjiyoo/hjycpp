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
DA::DA() {
	cout << "���� ���� ������" << endl;
	this->size = DEFAULT_SIZE;
	this->arr = new int[this->size];
}
DA::DA(int arrSize) {
	cout << "���� �ִ� ������" << endl;
	this->size = arrSize;
	this->arr = new int[this->size];
}
DA::DA(const DA& d) {
	cout << "���� ������" << endl;
	this->size = d.size;
	this->arr = new int[this->size];
	for (int i = 0; i < d.size; i++) {
		this->arr[i] = d.arr[i]; // *(d.arr + i)
	}
}
DA::~DA() {
	cout << "�Ҹ���" << endl;
}
int func(DA d) {
	cout << "I'm in func()" << endl;
	return d.size;
}
DA func2(int n) {
	cout << "I'm in func2()" << endl;
	DA d(n);
	return d;
}
int main() {
	cout << "�� ���� ������ �Է��Ͻðڼ�? ";
	int num; cin >> num;
	DA d4(num);
	for (int i = 0; i < num; i++) {
		cout << "�Է�: ";
		cin >> d4.arr[i]; // *(d4.arr + i)
	}

	// �Ű������� ��ü �Ѱ��� => ��������� ȣ��
	int n = func(d4);
	cout << "n: " << n << endl;

	// int�� �Ű������� �Ѱ��ְ� ��ü�� ���� => ��������� ȣ��
	DA d5 = func2(3);

	return 0;
}