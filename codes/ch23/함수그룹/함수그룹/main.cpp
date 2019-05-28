#include <iostream>
using namespace std;
class Base {
public:
	void Func1();
	static void stat();
};
void Base::Func1()
{
	cout << "In Base" << endl;
}
void Base::stat()
{
	cout << "In Base Static" << endl;
}
class Derived :public Base {
public:
	void Func1();
	static void stat();
};
void Derived::Func1()
{
	cout << "In Derived" << endl;
}
void Derived::stat()
{
	cout << "In Derived Static" << endl;
}
int main() {
	// 객체 만들기 전에 Base의 stat함수와 Derived의 stat 함수 실행
	Base::stat(); // stat(); 은 클래스 소속이라 객체 없이 실행 가능.
	Derived::stat();
	// d객체를 이용하여 Derived의 Func1(), stat() 실행. 
	// Base의 Func1(), stat() 실행.
	Derived d;
	d.Func1();
	d.stat();
	d.Base::Func1();
	d.Base::stat();
	

	return 0;
}
