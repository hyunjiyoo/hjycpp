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
	cout << "Base: ¼Ò¸êÀÚ" << endl;
}
class Derived :public Base
{
public:
	// ~Derived();
	virtual ~Derived();
};
Derived::~Derived()
{
	cout << "Derived: ¼Ò¸êÀÚ" << endl;
}
int main() {
	// virtual ¾øÀ¸¸é Base ¼Ò¸êÀÚ¸¸ ³ª¿Í¼­ ¸Þ¸ð¸® ½ÌÅ©°¡ ³ª°Ô µÊ.
	Base* bp = new Derived();
	delete bp;

	return 0;
}