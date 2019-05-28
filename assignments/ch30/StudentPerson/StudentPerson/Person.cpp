#include "Person.h"
Person::Person() {
	cout << "Person: ���� ���� ������" << endl;
	this->name = new char[MAX];
	this->name[0]= NULL;
	setName("������");
	this->age = 0;
}
Person::Person(const char* name, int age) {
	cout << "Person: ���� �ִ� ������" << endl;
	int len = strlen(name);
	this->name = new char[len + 1];
	setName(name);
	this->age = age;
}
Person::Person(const Person& obj) {
	cout << "Person: ���� ������" << endl;
	int len = strlen(obj.name);
	strcpy_s(this->name, len + 1, obj.name);
	this->age = obj.age;
}
Person::~Person() {
	cout << "Person: �Ҹ���" << endl;
	delete[] this->name;
	this->name = NULL;
}
Person& Person::operator=(const Person& obj) {
	cout << "Person: ���Կ�����" << endl;
	if (this != &obj) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->age = obj.age;
	}
	return *this;	
}
void Person::setName(const char* name) {
	if (this->name != name) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, name);
	}
}
void Person::setAge(int age) {
	this->age = age;
}
char* Person::getName() {
	return this->name;
}
int Person::getAge() {
	return this->age;
}