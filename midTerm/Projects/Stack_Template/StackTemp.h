#ifndef STACKTEMP_H
#define STACKTEMP_H
#include "MyException.h"
template <typename T>
class Stack {
private:
	int topIndex;
	int size;
	T * stack;
public:
	Stack(int size);
	~Stack();
	void push(T c);
	T pop();
};
template <typename T>
Stack<T>::Stack(int size) {
	this->size = size;
	this->stack = new T[size];
	this->topIndex = -1;
}
template <typename T>
Stack<T>::~Stack() {
	delete[] stack;
}
template <typename T>
void Stack<T>::push(T c) {
	if (topIndex + 1 >= size) {
		FullStackException e(this, "push�� �� �����ϴ�", topIndex);
		throw &e;
	}
	topIndex++;
	stack[topIndex] = c;
}
template <typename T>
T Stack<T>::pop() {
	if (topIndex < 0) {
		EmptyStackException e(this, "pop�� �� �����ϴ�", topIndex);
		throw &e;
	}
	return stack[topIndex--];
}
#endif // !STACKTEMP_H
