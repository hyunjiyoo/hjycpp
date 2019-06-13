#include "MyException.h"
MyException::MyException(void* sender, const char* desp, int info)
{
	this->sender = sender;
	strcpy_s(this->desp, strlen(desp) + 1, desp);
	this->info = info;
}
MinusBalance::MinusBalance(void* sender, const char* desp, int info)
	:MyException(sender, desp, info)
{
}
void MinusBalance::Report() {
	cout << "에러를 발생시킨 Account객체의 주소: " << this->sender << endl;
	cout << "Account Negative Balance" << endl;
	cout << "요청한" << this->info << "를 출금하면 잔고가 마이너스가 되어서 출금이 불가함." << endl;
}