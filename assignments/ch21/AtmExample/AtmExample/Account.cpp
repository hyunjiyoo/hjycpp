#include <iostream>
#include "Account.h"
using namespace std; 
const int NAME_LEN = 20;

Account::Account() {
	cout << "���� ���� ������" << endl;
	this->name = new char[NAME_LEN];
	this->name[0] = NULL;
	this->id = 0;
	this->balance = 0;
}
Account::Account(int _id, int _balance, char* _name) {
	cout << "���� �ִ� ������" << endl;
	int len = strlen(_name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, _name);
	this->id = _id;
	this->balance = _balance;
}
Account::Account(const Account& ac) {
	cout << "���� ���� ������" << endl;
	int len = strlen(ac.name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, ac.name);
	this->id = ac.id;
	this->balance = ac.balance;
}
Account::~Account() {
	cout << "�Ҹ���" << endl;
	delete[] this->name;
	this->name = NULL;
}
Account Account::operator=(const Account& ac) {
	cout << "���� ���� ������" << endl;
	if (this != &ac) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(ac.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, ac.name);
		this->id = ac.id;
		this->balance = ac.balance;
	}
	return *this;
}
void Account::ShowAllData() {
	cout << "����ID: " << this->id << " �ܾ�: " 
		 << this->balance << " �̸�: " << this->name << endl;
}
int Account::InMoney(int val) {
	this->balance += val;
	return this->balance;
}
bool Account::OutMoney(int val) {
	this->balance -= val;
	if (val > balance)
		return false;
	else
		return true;
}
void Account::SetId(int _id) {
	this->id = _id;
}
void Account::SetBalance(int _balance) {
	this->balance = _balance;
}
void Account::SetName(char* _name) {
	delete[] this->name;
	this->name = NULL;
	int len = strlen(_name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, _name);
}
int Account::GetId() {
	return this->id;
}
int Account::GetBalance() {
	return this->balance;
}
char* Account::GetName() {
	return this->name;
}