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
	cout << "인자 없는 생성자" << endl;
	this->size = DEFAULT_SIZE;
	this->arr = new int[this->size];
}
DA::DA(int arrSize) {
	cout << "인자 있는 생성자" << endl;
	this->size = arrSize;
	this->arr = new int[this->size];
}
DA::DA(const DA& d) {
	cout << "복사 생성자" << endl;
	this->size = d.size;
	this->arr = new int[this->size];
	for (int i = 0; i < d.size; i++) {
		this->arr[i] = d.arr[i]; // *(d.arr + i)
	}
}
DA::~DA() {
	cout << "소멸자" << endl;
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
	cout << "몇 개의 정수를 입력하시겠소? ";
	int num; cin >> num;
	DA d4(num);
	for (int i = 0; i < num; i++) {
		cout << "입력: ";
		cin >> d4.arr[i]; // *(d4.arr + i)
	}

	// 매개변수로 객체 넘겨줌 => 복사생성자 호출
	int n = func(d4);
	cout << "n: " << n << endl;

	// int를 매개변수로 넘겨주고 객체를 리턴 => 복사생성자 호출
	DA d5 = func2(3);

	return 0;
}