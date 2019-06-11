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
	virtual void Report() = 0; // ���� ���� �Լ�
};
MyException::MyException(void * sender, const char * desp, int info)
{
	this->sender = sender;
	strcpy_s(this->desp, strlen(desp) + 1, desp);
	this->info = info;
}
class OutOfRangeException : public MyException {
public:
	OutOfRangeException(void * sender, const char * desp, int info);
	void Report();
};
OutOfRangeException::OutOfRangeException(void * sender, const char * desp, int info)
	:MyException(sender, desp, info)
{
}
void OutOfRangeException::Report() {
	cout << "���ܰ� �߻��� ��ü�� �ּ�: " << this->sender << endl;
	cout << "Index out of bound ���� ��Ȳ�� �߻�" << endl;
	cout << "���ܰ� �߻��� ���� �迭 " << this->info << "�� ��ġ" << endl;
}
class MemoryException : public MyException {
public:
	MemoryException(void * sender, const char * desp, int info);
	void Report();
};
MemoryException::MemoryException(void * sender, const char * desp, int info)
	:MyException(sender, desp, info)
{
}
void MemoryException::Report() {
	cout << "���ܰ� �߻��� ��ü�� �ּ�: " << this->sender << endl;
	cout << "��û�� �޸� " << this->info << "�� �Ҵ��� �� ����" << endl;
}
class EmptyStackException : public MyException {
public:
	EmptyStackException(void * sender, const char * desp, int info);
	void Report();
};
EmptyStackException::EmptyStackException(void * sender, const char * desp, int info)
	:MyException(sender, desp, info)
{
}
void EmptyStackException::Report() {
	cout << "������ ����ֽ��ϴ�" << endl;
	cout << "���ܰ� �߻��� ��ü�� �ּ�: " << this->sender << endl;
	cout << "������ top index " << this->info << "���� ������ �߻��߽��ϴ�" << endl;
	cout << "����: " << this->desp << endl;
}
class FullStackException : public MyException {
public:
	FullStackException(void * sender, const char * desp, int info);
	void Report();
};
FullStackException::FullStackException(void * sender, const char * desp, int info)
	:MyException(sender, desp, info)
{
}
void FullStackException::Report() {
	cout << "������ �������ֽ��ϴ�" << endl;
	cout << "���ܰ� �߻��� ��ü�� �ּ�: " << this->sender << endl;
	cout << "������ top index " << this->info << "���� ������ �߻��߽��ϴ�" << endl;
	cout << "����: " << this->desp << endl;
}
#endif // !MYEXCEPTION_H#ifndef MYEXCEPTION_H