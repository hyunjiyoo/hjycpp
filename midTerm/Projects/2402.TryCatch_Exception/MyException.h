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
};
MyException::MyException(void * sender, const char * desp, int info)
{
	this->sender = sender;
	strcpy_s(this->desp, strlen(desp) + 1, desp);
	this->info = info;
}
#endif // !MYEXCEPTION_H