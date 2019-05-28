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
	// ��ü ����� ���� Base�� stat�Լ��� Derived�� stat �Լ� ����
	Base::stat(); // stat(); �� Ŭ���� �Ҽ��̶� ��ü ���� ���� ����.
	Derived::stat();
	// d��ü�� �̿��Ͽ� Derived�� Func1(), stat() ����. 
	// Base�� Func1(), stat() ����.
	Derived d;
	d.Func1();
	d.stat();
	d.Base::Func1();
	d.Base::stat();
	

	return 0;
}
