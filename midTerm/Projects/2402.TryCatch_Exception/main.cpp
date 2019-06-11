#include <iostream>
#include "MyException.h"
using namespace std;
const int DEFAULT_SIZE = 10;
class DA {
public:
	int* arr; int size;
	DA();
	DA(int arrSize);
	DA(const DA& d);
	~DA();
	DA& operator=(const DA& obj);
	void SetAt(int index, int val);
	int GetAt(int index);
	int GetSize();
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
DA& DA::operator=(const DA& obj)
{
	if (this != &obj) {
		this->size = obj.size;
		this->arr = new int[this->size];
		for (int i = 0; i < obj.size; i++) {
			this->arr[i] = obj.arr[i]; // *((this->arr) + i) = *(d.arr + i);
		}
	}
	return *this;
}
void DA::SetAt(int index, int val)
{
	if (index < 0 || index >= this->GetSize()) {
		// throw "Index out of bound";
		MyException e(this, "Index out of bound", index);
		throw e;
	}
	this->arr[index] = val;
}
int DA::GetAt(int index)
{
	if (index < 0 || index >= this->GetSize()) {
		// throw "Index out of bound";
		MyException e(this, "Index out of bound", index);
		throw e;
	}
	return this->arr[index];
}
int DA::GetSize()
{
	return this->size;
}
float Divide(int a, int b);
int main() {
	DA D1(10);
	cout << "&D1: " << &D1 << endl;

	try
	{
		D1.SetAt(0, 10);
		D1.SetAt(2, 20);
		D1.SetAt(9, 90);
		D1.SetAt(10, 100); // Error!!
	}
	catch (const char* string)
	{
		cout << "���� ����: " << string << endl;
	}
	catch (const MyException& e)
	{
		cout << "���ܸ� ���� ��ü�� �ּ�: " << e.sender << endl;
		cout << "���ܿ� ���� ����: " << e.desp << endl;
		cout << "�ΰ� ����: " << e.info << endl;
	}

	try
	{
		cout << Divide(10, 20) << endl;
		cout << Divide(10, 0) << endl; // ����!!!
		cout << Divide(10, 3) << endl; // ������ �������� ������ �ٽ� ������� ����!!
	}
	catch (const char* string)
	{
		cout << "��������: " << string << endl;
	}

	cout << "main�� ��" << endl;
	return 0;
}
float Divide(int a, int b)
{
	if (b == 0) {
		throw "0���� �������� �õ�";
	}
	return (float)a / (float)b;
}