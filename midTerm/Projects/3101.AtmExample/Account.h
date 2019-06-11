#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;
const int ACC_MAX = 10;
const int NAME_LEN = 20;
class Account {
private:
	int id;
	int balance;
	char* name;
public:
	Account();
	Account(int _id, int _balance, char* _name);
	Account(const Account& ac);
	~Account();
	Account& operator=(const Account& ac);

	void ShowAllData();
	int InMoney(int val);
	bool OutMoney(int val);

	void SetId(int _id);
	void SetBalance(int _balance);
	void SetName(char* _name);
	int GetId();
	int GetBalance();
	char* GetName();
};
#endif