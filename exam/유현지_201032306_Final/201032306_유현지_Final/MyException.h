#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
const int MAX = 10;
const int NAME_LEN = 20;
class MyException {
public:
	void * sender;
	char desp[MAX];
	int info;
	MyException(void* sender, const char* desp, int info);
	virtual void Report() = 0; 
};

class MinusBalance :public MyException {
public:
	MinusBalance(void * sender, const char * desp, int info);
	void Report();
};
#endif MYEXCEPTION_H