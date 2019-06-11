#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
class MyException {
public:
	void * sender; // ���ܸ� ���� ��ü�� �ּ�
	char desp[MAX]; // ���ܿ� ���� ����
	int info; // �ΰ� ����
	MyException(void * sender, const char * desp, int info);
};
MyException::MyException(void * sender, const char * desp, int info)
{
	this->sender = sender;
	strcpy_s(this->desp, strlen(desp) + 1, desp);
	this->info = info;
}
#endif // !MYEXCEPTION_H