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
	cout << "인자 없는 생성자" << endl;
	this->size = DEFAULT_SIZE;
	this->arr = new int[this->size];
}
DA::DA(int arrSize)
{
	cout << "인자 있는 생성자" << endl;
	this->size = arrSize;
	this->arr = new int[this->size];
}
DA::DA(const DA& d)
{
	cout << "복사 생성자" << endl;
	this->size = d.size;
	this->arr = new int[this->size];
	for (int i = 0; i < d.size; i++) {
		this->arr[i] = d.arr[i]; // *((this->arr) + i) = *(d.arr + i);
	}
}
DA::~DA()
{
	cout << "소멸자" << endl;
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
		cout << "예외 종료: " << string << endl;
	}
	catch (const MyException& e)
	{
		cout << "예외를 던진 객체의 주소: " << e.sender << endl;
		cout << "예외에 대한 설명: " << e.desp << endl;
		cout << "부가 정보: " << e.info << endl;
	}

	try
	{
		cout << Divide(10, 20) << endl;
		cout << Divide(10, 0) << endl; // 에러!!!
		cout << Divide(10, 3) << endl; // 위에서 에러났기 때문에 다시 실행되지 않음!!
	}
	catch (const char* string)
	{
		cout << "예외종료: " << string << endl;
	}

	cout << "main의 끝" << endl;
	return 0;
}
float Divide(int a, int b)
{
	if (b == 0) {
		throw "0으로 나누려는 시도";
	}
	return (float)a / (float)b;
}