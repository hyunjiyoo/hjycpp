#include <iostream>
using namespace std;
/* ADT 정의의 시작 */
class Power {
public:
	int kick; int punch;
	Power();
	Power(int k, int p);
	Power(const Power& p);
	~Power();
	void show();
	Power& operator=(const Power& obj); // 대입 연산자
	bool operator==(const Power& obj); // == 연산자
	Power operator+(const Power& obj); // + 연산자
	Power& operator+=(int i); // += 연산자 with int
	Power& operator+=(const Power& obj); // += 연산자
};
Power::Power() {
	cout << "인자 없는 생성자" << endl;
	this->kick = 0;
	this->punch = 0;
}
Power::Power(int k, int p) {
	cout << "인자 있는 생성자" << endl;
	this->kick = k;
	this->punch = p;
}
Power::Power(const Power& p) {
	cout << "복사 생성자" << endl;
	this->kick = p.kick;
	this->punch = p.punch;
}
Power::~Power() {
	cout << "소멸자" << endl;
}
void Power::show() {
	cout << "kick: " << this->kick << "  punch: " << this->punch << endl;
}
Power& Power::operator=(const Power& obj) {
	/* return type이 스스로가 된다. (그때 call by ref 타입)
	   p1 = p1; 일때는 아무일 하지 않기 위해 조건문 달아줌.
	   p1.operator=(p1); this와 매개변수인 &obj가 같을때. */

	   /* 얕은 대입 연산자 overloading */
	if (this != &obj) {
		this->kick = obj.kick;
		this->punch = obj.punch;
	}
	return *this;
}
// p1 == p2;  |  p1.operator(p2); bool값 리턴.
bool Power::operator==(const Power& obj) {
	/* this의 개념: "이 객체의" */
	if (this->kick == obj.kick && this->punch == obj.punch)
		return true;
	else
		return false;
}
// p1 = p2 + p3;  |  새로운 Power객체 리턴해야 해서 tmp만들어 Power객체 리턴.
Power Power::operator+(const Power& obj) {
	Power tmp;
	tmp.kick = this->kick + obj.kick;
	tmp.punch = this->punch + obj.punch;
	return tmp;
}
// p1 += p2;  | p1.operator(p2);
Power& Power::operator+=(const Power& obj) {
	this->kick += obj.kick;
	this->punch += obj.punch;
	return *this;
}
// p1 += 5;  | p1.operator(5);
Power& Power::operator+=(int i) {
	this->kick += i;
	this->punch += i;
	return *this;
}
/* ADT 정의의 끝 */

/* 클라이언트의 시작 */
int main() {
	Power A(3, 5), B(4, 6), C(5, 50);
	C = A + B;
	C.show();
	if (A == B) {
		cout << "같은 객체" << endl;
	}
	A = B;
	if (A == B) {
		cout << "같은 객체" << endl;
	}
	else {
		cout << "다른 객체" << endl;
	}
	A += B;
	A.show();
	A += 5;
	A.show();

	return 0;
}