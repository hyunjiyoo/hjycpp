#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "MyException.h"
class Account
{
protected:
	int id; // ∞Ë¡¬id
	char* name;
	double balance;
public:
	Account();
	Account(int id, const char* name, double balance);
	Account(const Account& obj);
	~Account();
	Account& operator=(const Account& ac);
	void SetId(int id);
	void SetName(const char* name);
	int GetId();
	char* GetName();
	
	virtual void SetBalance(double balance);
	virtual double GetBalance();
	virtual double Deposit(int val);
	virtual double Withdraw(int val);
	virtual void Show();

protected:
	static int totACT;
public:
	static void SetTotACT(int _totACT);
	static int getTotACT();
	virtual void AddCount();
	virtual void MinusCount();
};

/* ¿‘√‚±›∞Ë¡¬ */
class CheckingAccount :public Account
{
public:
	CheckingAccount();
	CheckingAccount(int id, const char* name, double balance);
	CheckingAccount(const CheckingAccount& obj);
	~CheckingAccount();
	CheckingAccount& operator=(const CheckingAccount& obj);
	void SetBalance(double balance);
	double GetBalance();
	double Deposit(int val);
	double Withdraw(int val);
	void AddCount();
	void MinusCount();
	void Show();
};
/* øπ±›∞Ë¡¬ */
class SavingsAccount :public Account
{
public:
	SavingsAccount();
	SavingsAccount(int id, const char* name, double balance);
	SavingsAccount(const SavingsAccount& obj);
	~SavingsAccount();
	SavingsAccount& operator=(const SavingsAccount& obj);
	void SetBalance(double balance);
	double GetBalance();
	double Deposit(int val);
	double Withdraw(int val);
	void AddCount();
	void MinusCount();
	void Show();
};
/* ∏∂¿Ã≥ Ω∫∞Ë¡¬ */
class MinusAccount :public Account
{
public:
	MinusAccount();
	MinusAccount(int id, const char* name, double balance);
	MinusAccount(const MinusAccount& obj);
	~MinusAccount();
	MinusAccount& operator=(const MinusAccount& obj);
	void SetBalance(double balance);
	double GetBalance();
	double Deposit(int val);
	double Withdraw(int val);
	void AddCount();
	void MinusCount();
	void Show();
};
#endif ACCOUNT_H