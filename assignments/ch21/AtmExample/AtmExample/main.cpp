#include <iostream>
#include "Account.h"
using namespace std;
const int ACC_MAX = 10;
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
void PrintMenu();
void MakeAccount(Account* act, int& index, int size);
void Deposit(Account* act, int index);
void Withdraw(Account* act, int index);
void Inquire(Account* act, int index);
void Exit(Account* act, int index);
int main() {
	int index = 0;
	Account ACT[ACC_MAX];
	while (true) {
		PrintMenu();
		cout << "선택: ";
		int num; cin >> num;
		switch (num) {
		case MAKE:
			MakeAccount(ACT, index, ACC_MAX);
			break;
		case DEPOSIT:
			Deposit(ACT, index);
			break;
		case WITHDRAW:
			Withdraw(ACT, index);
			break;
		case INQUIRE:
			Inquire(ACT, index);
			break;
		case EXIT:
			Exit(ACT, index);
			return 0;
		default:
			cout << "잘못된 선택을 하셨습니다." << endl;
			break;
		}
	}
	return 0;
}
void PrintMenu() {
	cout << "----------MENU----------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체조회" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void MakeAccount(Account* act, int& index, int size) {
	if (index < size) {
		cout << "계좌개설을 위한 입력(계좌ID 잔액 이름) : ";
		int inputId; int inputBal;
		cin >> inputId >> inputBal;
		char* inputName = new char[NAME_LEN];
		cin.getline(inputName, NAME_LEN);

		act[index].SetId(inputId);
		act[index].SetBalance(inputBal);
		act[index].SetName(inputName);
		delete[] inputName; inputName = NULL;
		index++;
	}
	else {
		cout << "더이상 계좌 생성을 할 수 없습니다." << endl;
		return;
	}
}
void Deposit(Account* act, int index) {
	cout << "계좌 ID: ";
	int id; cin >> id;
	for (int i = 0; i < index; i++) {
		if (id == act[i].GetId()) {
			cout << "입금액: ";
			int money; cin >> money;
			cout << "입금 전 잔고: " << act[i].GetBalance() << endl;
			act[i].InMoney(money);
			cout << "입금 후 잔고: " << act[i].GetBalance() << endl;
		}
		else {
			cout << "존재하지 않는 ID입니다." << endl;
		}
	}
}
void Withdraw(Account* act, int index) {
	cout << "계좌 ID: ";
	int id; cin >> id;
	for (int i = 0; i < index; i++) {
		if (id == act[i].GetId()) {
			cout << "출금액: ";
			int money; cin >> money;
			cout << "출금 전 잔고: " << act[i].GetBalance() << endl;
			if (money <= act[i].GetBalance()) {
				act[i].OutMoney(money);
				cout << "출금 후 잔고: " << act[i].GetBalance() << endl;
			}
			else {
				cout << "잔고 부족!" << endl;
			}
		}
		else {
			cout << "존재하지 않는 ID입니다." << endl;
		}
	}
}
void Inquire(Account* act, int index) {
	for (int i = 0; i < index; i++) {
		act[i].ShowAllData();
	}
}
// 잘 모르겠음..
void Exit(Account* act, int index) {
	for (int i = 0; i < index; i++) {
		if (act[i].GetName() != NULL) {
			delete[] act[i].GetName();
			act[i].SetName(NULL);
		}
	}
}