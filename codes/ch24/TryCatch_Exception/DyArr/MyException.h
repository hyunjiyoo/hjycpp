#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>
const int MAX = 100;
class MyException {
public:
	void* sender; // 예외를 던진 객체의 주소 (어떤 객체를 던질 지 몰라서 void* 이라고 한 것)
	char des[MAX]; // 예외에 대한 설명
	int info; // 부가 정보
	MyException(void* sender, const char* des, int info);
};
MyException::MyException(void* sender, const char* des, int info)
{
	this->sender = sender;
	strcpy_s(this->des, strlen(des) + 1, des);
	this->info = info;
}
#endif MYEXCEPTION_H