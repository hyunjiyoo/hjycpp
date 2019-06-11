#include <iostream>
using namespace std;
class WhoAmI {
public:
	int id;
	WhoAmI(int id);
	void ShowYourself();
};
WhoAmI::WhoAmI(int id) {
	this->id = id;
}
void WhoAmI::ShowYourself() {
	cout << "ID: " << this->id; // (*this).id
	cout << " this: " << this << endl; // this-> (= (*this). )°ú °°´Ù
}
int main() {
	WhoAmI i(1);
	WhoAmI j(2);
	cout << &i << endl;
	i.ShowYourself();
	cout << &j << endl;
	j.ShowYourself();
	return 0;
}