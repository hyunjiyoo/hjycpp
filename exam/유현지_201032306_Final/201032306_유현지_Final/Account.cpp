#include "Account.h"
int Account::totACT = 0;

Account::Account()
{
	cout << "Account::���� ���� ������" << endl;
	this->id = 0;
	this->name = new char[NAME_LEN];
	this->name[0] = NULL;
	this->balance = 0;
}
Account::Account(int id, const char* name, double balance) 
{
	cout << "Account::���� �ִ� ������" << endl;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
	this->id = id;
	this->balance = balance;
}
Account::Account(const Account& obj) 
{
	cout << "Account::���� ������" << endl;
	int len = strlen(obj.name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, obj.name);
	this->id = obj.id;
	this->balance = obj.balance;
}
Account::~Account() 
{
	cout << "Account::�Ҹ���" << endl;
	delete[] this->name;
	this->name = NULL;
}
Account& Account::operator=(const Account& obj) 
{
	cout << "Account::���� ���� ���� ������" << endl;
	if (this != &obj)
	{
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->id = obj.id;
		this->balance = obj.balance;
	}
	return *this;
}
void Account::SetId(int id) 
{
	this->id = id;
}
void Account::SetName(const char* name) 
{
	int len = strlen(name);
	strcpy_s(this->name, len + 1, name);
}
int Account::GetId() 
{
	return this->id;
}
char* Account::GetName() 
{
	return this->name;
}
void Account::SetBalance(double balance)
{
	this->balance = balance;
}
double Account::GetBalance() 
{
	return this->balance;
}

double Account::Deposit(int val)
{
	this->balance += val;
	return this->balance;
}
double Account::Withdraw(int val)
{
	this->balance -= val;
	return this->balance;
}
void Account::SetTotACT(int _totACT)
{
	totACT = _totACT;
}
int Account::getTotACT()
{
	return totACT;
}
void Account::AddCount()
{
	totACT++;
}
void Account::MinusCount()
{
	totACT--;
}
void Account::Show()
{
	cout << "Account ����" << endl;
}
/* Checking Account */
CheckingAccount::CheckingAccount()
	:Account()
{
	cout << "CheckingAccount::���� ���� ������" << endl;

}
CheckingAccount::CheckingAccount(int id, const char* name, double balance)
	:Account(id, name, balance)
{
	cout << "CheckingAccount::���� �ִ� ������" << endl;
}
CheckingAccount::CheckingAccount(const CheckingAccount& obj)
	: Account(obj)
{
	cout << "CheckingAccount::���� ������" << endl;
}
CheckingAccount::~CheckingAccount()
{
	cout << "CheckingAccount::�Ҹ���" << endl;
}
CheckingAccount& CheckingAccount::operator=(const CheckingAccount& obj)
{
	cout << "CheckingAccount::���� ���� ���� ������" << endl;
	if (this != &obj)
	{
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->id = obj.id;
		this->balance = obj.balance;
	}
	return *this;
}
void CheckingAccount::SetBalance(double balance)
{
	this->balance = balance;
}
double CheckingAccount::GetBalance()
{
	return this->balance;
}
double CheckingAccount::Deposit(int val)
{
	cout << "CheckingAccount::����" << endl;
	this->balance += val;
	return this->balance;
}
double CheckingAccount::Withdraw(int val)
{
	if (this->balance < val)
	{
		MinusBalance e(this, "Account Negative Balance", val);
		throw e;
	}
	cout << "CheckingAccount::���" << endl;
	this->balance = this->balance - 1000 - val;
	return this->balance;
}
void CheckingAccount::AddCount()
{
	totACT++;
}
void CheckingAccount::MinusCount()
{
	totACT--;
}
void CheckingAccount::Show()
{
	cout << "����Ÿ��: ����� ����, ID: " << GetId() << ", �̸�: " << GetName() << ", �ܾ�: " << GetBalance() << endl;
}
/* Saving Account */
SavingsAccount::SavingsAccount()
	:Account()
{
	cout << "SavingsAccount::���� ���� ������" << endl;
}
SavingsAccount::SavingsAccount(int id, const char* name, double balance)
	:Account(id, name, balance)
{
	cout << "SavingsAccount::���� �ִ� ������" << endl;
}
SavingsAccount::SavingsAccount(const SavingsAccount& obj)
	:Account(obj)
{
	cout << "SavingsAccount::���� ������" << endl;
}
SavingsAccount::~SavingsAccount()
{
	cout << "SavingsAccount::�Ҹ���" << endl;
}
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& obj)
{
	cout << "SavingsAccount::���� ���� ���� ������" << endl;
	if (this != &obj)
	{
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->id = obj.id;
		this->balance = obj.balance;
	}
	return *this;
}
void SavingsAccount::SetBalance(double balance)
{
	this->balance = balance;
}
double SavingsAccount::GetBalance()
{
	return this->balance;
}
double SavingsAccount::Deposit(int val)
{
	cout << "SavingsAccount::����" << endl;
	this->balance += val;
	return this->balance;
}
double SavingsAccount::Withdraw(int val)
{
	if (this->balance < val)
	{
		MinusBalance e(this, "Account Negative Balance", val);
		throw e;
	}
	cout << "SavingsAccount::���" << endl;
	this->balance = this->balance - val - (this->balance*0.1);
	return this->balance;
}
void SavingsAccount::AddCount()
{
	totACT++;
}
void SavingsAccount::MinusCount()
{
	totACT--;
}
void SavingsAccount::Show()
{
	cout << "����Ÿ��: ���ݰ���, ID: " << GetId() << ", �̸�: " << GetName() << ", �ܾ�: " << GetBalance() << endl;
}
/* MinusAccount */
MinusAccount::MinusAccount()
	:Account()
{
	cout << "MinusAccount::���� ���� ������" << endl;
}
MinusAccount::MinusAccount(int id, const char* name, double balance)
	:Account(id, name, balance)
{
	cout << "MinusAccount::���� �ִ� ������" << endl;
}
MinusAccount::MinusAccount(const MinusAccount& obj)
	:Account(obj)
{
	cout << "MinusAccount::���� ������" << endl;
}
MinusAccount::~MinusAccount()
{
	cout << "MinusAccount::�Ҹ���" << endl;
}
MinusAccount& MinusAccount::operator=(const MinusAccount& obj)
{
	cout << "MinusAccount::���� ���� ���� ������" << endl;
	if (this != &obj)
	{
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->id = obj.id;
		this->balance = obj.balance;
	}
	return *this;

}
void MinusAccount::SetBalance(double balance)
{
	this->balance = balance;
}
double MinusAccount::GetBalance()
{
	return this->balance;
}
double MinusAccount::Deposit(int val)
{
	cout << "MinusAccount::����" << endl;
	this->balance += val;
	return this->balance;
}
double MinusAccount::Withdraw(int val)
{
	cout << "MinusAccount::���" << endl;
	this->balance = this->balance - (val*1.1);
	return this->balance;
}
void MinusAccount::AddCount()
{
	totACT++;
}
void MinusAccount::MinusCount()
{
	totACT--;
}
void MinusAccount::Show()
{
	cout << "����Ÿ��: ���̳ʽ�����, ID: " << GetId() << ", �̸�: " << GetName() << ", �ܾ�: " << GetBalance() << endl;
}