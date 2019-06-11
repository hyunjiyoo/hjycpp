#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>
const int MAX = 100;
class MyException {
public:
	void* sender; // ���ܸ� ���� ��ü�� �ּ� (� ��ü�� ���� �� ���� void* �̶�� �� ��)
	char des[MAX]; // ���ܿ� ���� ����
	int info; // �ΰ� ����
	MyException(void* sender, const char* des, int info);
};
MyException::MyException(void* sender, const char* des, int info)
{
	this->sender = sender;
	strcpy_s(this->des, strlen(des) + 1, des);
	this->info = info;
}
#endif MYEXCEPTION_H