#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student :public Person {
protected:
	int stdId;
	char* major;
public:
	Student();
	Student(const char* name, int age, int stdId, const char* major);
	Student(const Student& obj);
	~Student();
	Student& operator=(const Student& obj);
	void setStdId(int stdId);
	void setMajor(const char* major);
	int getStdId();
	char* getMajor();
	void Print();
	void Write(int index);
};

#endif STUDENT_H