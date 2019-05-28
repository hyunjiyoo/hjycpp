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
	cout << "Base: ���� ���� ������" << endl;
	this->b_var = 0;
}
Base::Base(int var) {
	cout << "Base: ���� �ִ� ������" << endl;
	this->b_var = var;
}
Base::Base(const Base& obj) {
	cout << "Base: ���� ������" << endl;
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
	cout << "Derived: ���� ���� ������" << endl;
	this->d_var = 0;
}
Derived::Derived(int b_var, int d_var)
	: Base(b_var)
{
	cout << "Derived: ���� �ִ� ������" << endl;
	this->d_var = d_var;
}
// obj�� dataType�� Derived. Base�� ��������ڴ� dataType�� Base. 
// (b.obj = d.obj) �Ϲ��� ����ȯ(implicit casting).
// ����� ����ȯ�� explicit casting.
Derived::Derived(const Derived& obj) // ������ �ִ� d.obj 
	:Base(obj) // �޴� �ִ� b.obj
{
	cout << "Derived: ���� ������" << endl;
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
	cout << "��ü �� �Ϲ��� ����ȯ" << endl;
	// b = d;
	//// d = b; // Derived obj = Base obj => ��ü�� Dawn casting ��� �ȵ�!!
	//b.Print(); // Derived Print() �� �ƴ϶� Base Print()�� ����!! (�׻� original �� ����!!)

	Base* bp = &b;
	bp->Print();
	Derived* dp = &d;
	dp->Print();

	//cout << "�Ϲ��� Up casting" << endl;
	//bp = dp;
	//bp->Print(); // �׻� Base�� Print() ����!
	
	cout << "����� Down casting" << endl;
	// dp = bp; // �����Ͱ� �Ϲ��� Down casting ��� �ȵ�.
	dp = (Derived*)bp;
	dp->Print(); // Derived Print() ����!!
	

	return 0;
}