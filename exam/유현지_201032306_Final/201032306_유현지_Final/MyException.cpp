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
	cout << "������ �߻���Ų Account��ü�� �ּ�: " << this->sender << endl;
	cout << "Account Negative Balance" << endl;
	cout << "��û��" << this->info << "�� ����ϸ� �ܰ� ���̳ʽ��� �Ǿ ����� �Ұ���." << endl;
}