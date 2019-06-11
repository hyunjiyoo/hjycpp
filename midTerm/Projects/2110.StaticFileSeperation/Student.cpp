#include <iostream>
#include "Student.h"
using namespace std;

int Student::s_cnt = 0; // static ������� �ʱ�ȭ

Student::Student(const char* name, int stdNum) {
	strcpy_s(this->name, strlen(name) + 1, name);
	this->sNo = stdNum;
	// �ν��Ͻ� �ϳ� �������
	s_cnt++; // �̰��� class �Ҽ��̹Ƿ�, this->�� �� �� ����. this-> �� '�� ��ü��' ��� ��.
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
	cout << "���� �л��� ���� " << s_cnt << endl;
}