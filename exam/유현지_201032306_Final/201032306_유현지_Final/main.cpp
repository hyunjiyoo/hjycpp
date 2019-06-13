#include "Account.h"

enum { ADDACCOUNT = 1, DELACCOUNT, DEPOSIT, WITHDRAW, CNTACCOUNT, TOTACCOUNT, EXIT };
void Menu();
void AddAccount(Account** act, int& index, int size);
void DeleteAccount(Account** act, int index);
void Deposit(Account** act, int cnt);
void Withdraw(Account** act, int cnt);
void CountAccount();
void TotalAccount(Account** act, int cnt);
void Exit(Account** act, int index);

int main()
{
	int index = 0; int cnt = 0;
	Account* ACT[MAX]; // ���� ��ü ������ �迭

	while (true)
	{
		Menu();
		cout << "����: ";
		int num; cin >> num;
		switch (num)
		{
		case ADDACCOUNT:
			AddAccount(ACT, index, MAX);
			break;
		case DELACCOUNT:
			DeleteAccount(ACT, index);
			break;
		case DEPOSIT:
			Deposit(ACT, index);
			break;
		case WITHDRAW:
			Withdraw(ACT, index);
			break;
		case CNTACCOUNT:
			CountAccount();
			break;
		case TOTACCOUNT:
			TotalAccount(ACT, index);
			break;
		case EXIT:
			Exit(ACT, index);
			return 0;
		default:
			cout << "1~7 ������ ���� �Է��ϼ���" << endl;
			break;
		}
	}
	return 0;
}

void Menu()
{
	cout << "--------MENU--------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ����" << endl;
	cout << "3. �Ա�" << endl;
	cout << "4. ���" << endl;
	cout << "5. ���� ���� ��ȸ" << endl;
	cout << "6. ��ü ���� ���� ��ȸ" << endl;
	cout << "7. ���α׷� ����" << endl << endl;
}
void AddAccount(Account** act, int& index, int size)
{
	if (index == size) {
		cout << "���¸� ���̻� ������ �� �����ϴ�." << endl;
	}
	else {
		cout << "���� ���� ����(1.����ݰ���  2.���ݰ���  3.���̳ʽ�����): ";
		int num; cin >> num;
		cout << "���°����� ���� �Է�(����ID  �ܾ�  �̸�): ";
		int id; double balance; char name[NAME_LEN];
		cin >> id >> balance >> name;
		switch (num)
		{
		case 1:
			act[index] = new CheckingAccount(id, name, balance);
			break;
		case 2:
			act[index] = new SavingsAccount(id, name, balance);
			break;
		case 3:
			act[index] = new MinusAccount(id, name, balance);
			break;
		default:
			cout << "1~3 ������ ���ڸ� �Է����ּ���" << endl;
			break;
		}
		act[index]->AddCount();
		index++;
	}
}
void DeleteAccount(Account** act, int index)
{
	cout << "������ ���� ID: ";
	bool flag = false;
	int id; cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (act[i]->GetId() == id) {
			if (act[i] != NULL)
			{
				act[i]->MinusCount();
				delete act[i];
				act[i] = NULL;
				cout << "���¸� �����Ͽ����ϴ�!" << endl;
			}
			flag = true;
		}
	}
	if (flag == false)
		cout << "�ش� ID�� ���¸� ã�� �� �����ϴ�!" << endl;
}
void Deposit(Account** act, int index)
{
	bool flag = false;
	cout << "����ID: ";
	int id; cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (act[i]->GetId() == id)
		{
			cout << "�Աݾ�: ";
			int input; cin >> input;
			act[i]->Deposit(input);
			cout << "�����ܰ�: " << act[i]->GetBalance() << endl;
			flag = true;
		}
	}
	if (flag == false)
		cout << "�ش� ���°� �����ϴ�." << endl;
}
void Withdraw(Account** act, int index)
{
	bool flag = false;
	cout << "���� ID: "; 
	int id; cin >> id;
	for (int i = 0; i < index; i++)
	{
		try
		{
			if (act[i]->GetId() == id)
			{
				cout << "��ݾ�: ";
				int input; cin >> input;
				act[i]->Withdraw(input);
				cout << "�����ܰ�: " << act[i]->GetBalance() << endl;
				flag = true;
			}
		}
		catch (MyException* e)
		{
			e->Report();
		}
	}
	if (flag == false)
		cout << "�ش� ���°� �����ϴ�." << endl;
}
void CountAccount()
{
	cout << "���� ������ ���� : " <<  Account::getTotACT() << endl;
}
void TotalAccount(Account** act, int index)
{
	for (int i = 0; i < index; i++)
	{
		act[i]->Show();
	}
}
void Exit(Account** act, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (act[i] != NULL)
		{
			delete act[i];
			act[i] = NULL;
		}
	}
}