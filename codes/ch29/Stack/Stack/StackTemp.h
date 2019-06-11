#ifndef STACKTMP_H
#define STACKTMP_H
#include <iostream>
class Stack
{
private:
	int topIndex;
	char* stackPtr;

public:
	Stack(int size = 10); // 인자있는 생성자와 인자없는 생성자 역할을 같이 함. 매개변수는 배열의 사이즈
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