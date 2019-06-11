#ifndef STACKTMP_H
#define STACKTMP_H
#include <iostream>
class Stack
{
private:
	int topIndex;
	char* stackPtr;

public:
	Stack(int size = 10); // �����ִ� �����ڿ� ���ھ��� ������ ������ ���� ��. �Ű������� �迭�� ������
	~Stack();
	void push(const char& val);
	char pop();
	int getTopIndex();
};
Stack::Stack(int size)
{
	this->topIndex = -1;
	this->stackPtr = new char[size];
}
Stack::~Stack()
{
	delete[] this->stackPtr;
	this->stackPtr = NULL;
}
void Stack::push(const char& val)
{
	this->topIndex++;
	this->stackPtr[this->topIndex] = val;
}
char Stack::pop()
{
	return this->stackPtr[this->topIndex--];
}
int Stack::getTopIndex()
{
	return this->topIndex;
}
#endif STACKTMP_H