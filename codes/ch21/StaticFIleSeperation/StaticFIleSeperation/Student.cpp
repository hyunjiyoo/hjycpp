#include <iostream>
#include "Student.h"
using namespace std;

int Student::s_cnt = 0; // static 멤버변수 초기화

Student::Student(const char* name, int stdNum) {
	strcpy_s(this->name, strlen(name) + 1, name);
	this->sNo = stdNum;
	// 인스턴스 하나 만들어짐
	s_cnt++; // 이것은 class 소속이므로, this->를 할 수 없다. this-> 는 '이 객체의' 라는 뜻.
}
Student::~Student() {
	s_cnt--;
}

const char* Student::getName() {
	return this->name;
}
int Student::getSNo() {
	return this->sNo;
}
void Student::SetName(const char* name) {
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Student::SetSNo(int stdNum) {
	this->sNo = stdNum;
}
/* static */
int Student::getScnt() {
	return s_cnt;
}
void Student::setScnt(int val) {
	s_cnt = val;
}
void Student::printScnt() {
	cout << "현재 학생의 수는 " << s_cnt << endl;
}