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
	/* ���� ���� ������ �����ε� */
	DA& operator=(const DA& r);
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

/**** ���� �߿� ****/
DA& DA::operator=(const DA& r) {
	if (this != &r) {
		delete[] this->arr;
		this->size = r.size;
		this->arr = new int[this->size];
		// ��Ұ� ����
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = r.arr[i];
		}
	}
	return *this;
}

int main() {
	DA A(2);
	DA B(5);
	A = B;

	for (int i = 0; i < A.size; i++) {
		cout << A.arr[i] << " ";
	}

	return 0;
}