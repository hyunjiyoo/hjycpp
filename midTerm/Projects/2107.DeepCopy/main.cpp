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
	/* 깊은 대입 연산자 오버로딩 */
	DA& operator=(const DA& r);
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

/**** 아주 중요 ****/
DA& DA::operator=(const DA& r) {
	if (this != &r) {
		delete[] this->arr;
		this->size = r.size;
		this->arr = new int[this->size];
		// 요소간 대입
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