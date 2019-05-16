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
		cout << "����: ";
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
			cout << "�߸��� ������ �ϼ̽��ϴ�." << endl;
			break;
		}
	}
	return 0;
}
void PrintMenu() {
	cout << "----------MENU----------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. ��ü��ȸ" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void MakeAccount(Account* act, int& index, int size) {
	if (index < size) {
		cout << "���°����� ���� �Է�(����ID �ܾ� �̸�) : ";
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
		cout << "���̻� ���� ������ �� �� �����ϴ�." << endl;
		return;
	}
}
void Deposit(Account* act, int index) {
	cout << "���� ID: ";
	int id; cin >> id;
	for (int i = 0; i < index; i++) {
		if (id == act[i].GetId()) {
			cout << "�Աݾ�: ";
			int money; cin >> money;
			cout << "�Ա� �� �ܰ�: " << act[i].GetBalance() << endl;
			act[i].InMoney(money);
			cout << "�Ա� �� �ܰ�: " << act[i].GetBalance() << endl;
		}
		else {
			cout << "�������� �ʴ� ID�Դϴ�." << endl;
		}
	}
}
void Withdraw(Account* act, int index) {
	cout << "���� ID: ";
	int id; cin >> id;
	for (int i = 0; i < index; i++) {
		if (id == act[i].GetId()) {
			cout << "��ݾ�: ";
			int money; cin >> money;
			cout << "��� �� �ܰ�: " << act[i].GetBalance() << endl;
			if (money <= act[i].GetBalance()) {
				act[i].OutMoney(money);
				cout << "��� �� �ܰ�: " << act[i].GetBalance() << endl;
			}
			else {
				cout << "�ܰ� ����!" << endl;
			}
		}
		else {
			cout << "�������� �ʴ� ID�Դϴ�." << endl;
		}
	}
}
void Inquire(Account* act, int index) {
	for (int i = 0; i < index; i++) {
		act[i].ShowAllData();
	}
}
// �� �𸣰���..
void Exit(Account* act, int index) {
	for (int i = 0; i < index; i++) {
		if (act[i].GetName() != NULL) {
			delete[] act[i].GetName();
			act[i].SetName(NULL);
		}
	}
}