#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 20;
class Person {
protected:
	char* name;
	int age;
public:
	Person();
	Person(const char* name, int age);
	Person(const Person& obj);
	~Person();
	Person& operator=(const Person& obj);
	void setName(const char* name);
	void setAge(int age);
	char* getName();
	int getAge();
};
#endif PERSON_H