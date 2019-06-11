#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
class MyException {
public:
	void* sender; // ���ܸ� ���� ��ü�� �ּ� (� ��ü�� ���� �� ���� void* �̶�� �� ��)
	char des[MAX]; // ���ܿ� ���� ����
	int info; // �ΰ� ����
	MyException(void* sender, const char* des, int info);
	virtual void Report() = 0; // ���� ���� �Լ�
};
MyException::MyException(void* sender, const char* des, int info)
{
	this->sender = sender;
	strcpy_s(this->des, strlen(des) + 1, des);
	this->info = info;
}

/* OutOfRange Exception */
class OutOfRangeException :public MyException
{
public:
	OutOfRangeException(void* sender, const char* des, int info);
	void Report();
};
OutOfRangeException::OutOfRangeException(void* sender, const char* des, int info)
	:MyException(sender, des, info)
{

}
void OutOfRangeException::Report()
{
	cout << "OutOfRange Exception" << endl;
}

/* Memory Exception */
class MemoryException :public MyException
{
public:
	MemoryException(void* sender, const char* des, int info);
	void Report();
};
MemoryException::MemoryException(void* sender, const char* des, int info)
	:MyException(sender, des, info)
{

}
void MemoryException::Report()
{
	cout << "Memory Exception" << endl;
}

/* StackFull Exception */
class StackFullException :public MyException
{
public:
	StackFullException(void* sender, const char* des, int info);
	void Report();
};
StackFullException::StackFullException(void* sender, const char* des, int info)
	:MyException(sender, des, info)
{

}
void StackFullException::Report()
{
	cout << "StackFull Exception" << endl;
}

/* StackEmpty Exception */
class StackEmptyException :public MyException
{
public:
	StackEmptyException(void* sender, const char* des, int info);
	void Report();
};
StackEmptyException::StackEmptyException(void* sender, const char* des, int info)
	:MyException(sender, des, info)
{

}
void StackEmptyException::Report()
{
	cout << "StackEmpty Exception" << endl;
}
#endif MYEXCEPTION_H