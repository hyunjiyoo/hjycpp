#include <iostream>
using namespace std;
const int MAX_NAME = 20;
class Person {
public: 
	char* name;
	int age;

	Person();
	Person(const char* _name, int _age);
	Person(const Person& obj);
	~Person();
	Person& operator=(const Person& obj);
	void Showdata();

};
Person::Person() {
	cout << "인자 없는 생성자" << endl;
	this->name = new char[MAX_NAME];
	this->name[0] = NULL; // name을 출력할 때 garbage값 나오니까 NULL 을 해준 것.
	this->age = 0;
}
Person::Person(const char* _name, int _age) {
	cout << "인자 있는 생성자" << endl;
	int len = strlen(_name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, _name);
	this->age = _age;
}
Person::Person(const Person& obj) {
	cout << "깊은 복사 생성자" << endl;
	int len = strlen(obj.name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, obj.name);
	this->age = obj.age;
}
Person::~Person() {
	cout << "소멸자" << endl;
	delete[] this->name; this->name = NULL;
}
Person& Person::operator=(const Person& obj) {
	cout << "깊은 복사 대입 연산자" << endl;
	if (this != &obj) {
		delete[] this->name; this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->age = obj.age;
	}
	return *this;
}
void Person::Showdata() {
	cout << "name: " << name << " age: " << age << endl;
}
int main() {
	Person P1("강민", 21);
	P1.Showdata();
	Person P2("나동민", 24);
	P2.Showdata();
	P1 = P2;
	P1.Showdata();

	return 0;
}