#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
class MyException {
public:
	void * sender; // 예외를 던진 객체의 주소
	char desp[MAX]; // 예외에 대한 설명
	int info; // 부가 정보
	MyException(void * sender, const char * desp, int info);
	virtual void Report() = 0; // 순수 가상 함수
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
	cout << "예외가 발생된 객체의 주소: " << this->sender << endl;
	cout << "Index out of bound 예외 상황이 발생" << endl;
	cout << "예외가 발생된 곳은 배열 " << this->info << "의 위치" << endl;
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
	cout << "예외가 발생된 객체의 주소: " << this->sender << endl;
	cout << "요청한 메모리 " << this->info << "를 할당할 수 없음" << endl;
}
#endif // !MYEXCEPTION_H#ifndef MYEXCEPTION_H