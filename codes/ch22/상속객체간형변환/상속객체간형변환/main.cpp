#include <iostream>
using namespace std;
class Base {
private:
	int b_var;
public:
	Base();
	Base(int var);
	Base(const Base& obj);
	void Print();
};
Base::Base() {
	cout << "Base: 인자 없는 생성자" << endl;
	this->b_var = 0;
}
Base::Base(int var) {
	cout << "Base: 인자 있는 생성자" << endl;
	this->b_var = var;
}
Base::Base(const Base& obj) {
	cout << "Base: 복사 생성자" << endl;
	this->b_var = obj.b_var;
}
void Base::Print() {
	cout << "Base: Print()" << endl;
	cout << "b_var: " << b_var << endl;
}
class Derived :public Base {
private:
	int d_var;
public:
	Derived();
	Derived(int b_var, int d_var);
	Derived(const Derived& obj);
	void Print();
};
Derived::Derived() 
	:Base()
{
	cout << "Derived: 인자 없는 생성자" << endl;
	this->d_var = 0;
}
Derived::Derived(int b_var, int d_var)
	: Base(b_var)
{
	cout << "Derived: 인자 있는 생성자" << endl;
	this->d_var = d_var;
}
// obj의 dataType은 Derived. Base의 복사생성자는 dataType이 Base. 
// (b.obj = d.obj) 암묵적 형변환(implicit casting).
// 명시적 형변환은 explicit casting.
Derived::Derived(const Derived& obj) // 보내는 애는 d.obj 
	:Base(obj) // 받는 애는 b.obj
{
	cout << "Derived: 복사 생성자" << endl;
	this->d_var = obj.d_var;
}
void Derived::Print() {
	cout << "Derived: Print() " << endl;
	cout << "d_var: " << d_var << endl;
}

int main() {
	Base b(-10);
	b.Print();
	Derived d(-7, 100);
	d.Print();
	cout << "객체 간 암묵적 형변환" << endl;
	// b = d;
	//// d = b; // Derived obj = Base obj => 객체간 Dawn casting 허용 안됨!!
	//b.Print(); // Derived Print() 가 아니라 Base Print()가 실행!! (항상 original 이 실행!!)

	Base* bp = &b;
	bp->Print();
	Derived* dp = &d;
	dp->Print();

	//cout << "암묵적 Up casting" << endl;
	//bp = dp;
	//bp->Print(); // 항상 Base의 Print() 실행!
	
	cout << "명시적 Down casting" << endl;
	// dp = bp; // 포인터간 암묵적 Down casting 허용 안됨.
	dp = (Derived*)bp;
	dp->Print(); // Derived Print() 실행!!
	

	return 0;
}