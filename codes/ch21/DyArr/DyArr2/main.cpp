/* 2019.04.19 수업 */
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

// ADT, DA를 활용한 클라이언트의 시작
// **** 객체를 call by value로 보낼 때 복사생성자 호출됨!!! ****
// int func(DA &d) { 로 수행해보시오.
int func(DA d) { // call by value 일때는 복사생성자 생성하고 call by ref 일때는 복사 생성자 생성 안함..(중요!!)
	cout << "in func()" << endl;
	return d.size;
}

DA func2(int i) {
	cout << "in func2()" << endl;
	DA r(i); // 인자 있는 생성자 호출
	return r;
}
int main() {
	cout << "몇 개의 정수를 입력하시겠소? ";
	int num;
	cin >> num;
	DA d4(num); // 인자 있는 생성자 호출
	for (int i = 0; i < num; i++) {
		cout << "입력: ";
		cin >> d4.arr[i]; // *(d4.arr + i)
	}

	// 매개변수로 객체를 넘겨줌
	int n = func(d4); // 복사 생성자 호출
	// d의 소멸자 호출
	cout << "n: " << n << endl;

	// int를 매개변수로 넘겨주고 객체를 리턴!!
	DA d5 = func2(3); // 객체를 리턴할 때도 복사생성자 호출
	// 소멸자
	// 소멸자
	// 소멸자

	/* 1.
	DA d1;
	DA d2(5);
	DA d3(d2);
	*/
	return 0;
}