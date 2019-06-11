#ifndef STACKTEMP_H
#define STACKTEMP_H
class Stack {
private:
	int topIndex;
	int size;
	char * stack;
public:
	Stack(int size);
	~Stack();
	void push(char c);
	char pop();
};
Stack::Stack(int size) {
	this->size = size;
	this->stack = new char[size];
	this->topIndex = -1;
}
Stack::~Stack() {
	delete[] stack;
}
void Stack::push(char c) {
	topIndex++;
	stack[topIndex] = c;
}
char Stack::pop() {
	return stack[topIndex--];
}
#endif // !STACKTEMP_H
