#include <iostream>
using namespace std;
class Base
{
public:
	// ~Base();
	virtual ~Base();
};
Base::~Base()
{
	cout << "Base: �Ҹ���" << endl;
}
class Derived :public Base
{
public:
	// ~Derived();
	virtual ~Derived();
};
Derived::~Derived()
{
	cout << "Derived: �Ҹ���" << endl;
}
int main() {
	// virtual ������ Base �Ҹ��ڸ� ���ͼ� �޸� ��ũ�� ���� ��.
	Base* bp = new Derived();
	delete bp;

	return 0;
}