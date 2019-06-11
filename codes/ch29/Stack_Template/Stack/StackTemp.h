#ifndef STACKTMP_H
#define STACKTMP_H
#include <iostream>
template <typename T>
class Stack
{
private:
	int topIndex;
	T* stackPtr;
	int stackSize;
public:
	Stack(int size = 10); // 인자있는 생성자와 인자없는 생성자 역할을 같이 함. 매개변수는 배열의 사이즈
	~Stack();
	void push(const T& val);
	T pop();
	int getTopIndex();
};
template <typename T>
Stack<T>::Stack(int size)
{
	this->topIndex = -1;
	this->stackPtr = new T[size];
	this->stackSize = size;
}
template <typename T>
Stack<T>::~Stack()
{
	delete[] this->stackPtr;
	this->stackPtr = NULL;
}
template <typename T>
void Stack<T>::push(const T& val)
{
	if (topIndex >= stackSize - 1)
	{
		StackFullException e(this, "Stack Full", topIndex);
		throw &e;
	}
	this->topIndex++;
	this->stackPtr[this->topIndex] = val;
}
template <typename T>
T Stack<T>::pop()
{
	if (topIndex < 0)
	{
		StackEmptyException e(this, "Stack Empty", topIndex);
		throw &e;
	}
	return this->stackPtr[this->topIndex--];
}
template <typename T>
int Stack<T>::getTopIndex()
{
	return this->topIndex;
}
#endif STACKTMP_H