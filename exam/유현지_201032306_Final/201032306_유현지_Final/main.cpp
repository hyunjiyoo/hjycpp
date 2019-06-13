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
	Account* ACT[MAX]; // 정적 객체 포인터 배열

	while (true)
	{
		Menu();
		cout << "선택: ";
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
			cout << "1~7 사이의 값을 입력하세요" << endl;
			break;
		}
	}
	return 0;
}

void Menu()
{
	cout << "--------MENU--------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 계좌 해지" << endl;
	cout << "3. 입금" << endl;
	cout << "4. 출금" << endl;
	cout << "5. 계좌 갯수 조회" << endl;
	cout << "6. 전체 계좌 정보 조회" << endl;
	cout << "7. 프로그램 종료" << endl << endl;
}
void AddAccount(Account** act, int& index, int size)
{
	if (index == size) {
		cout << "계좌를 더이상 생성할 수 없습니다." << endl;
	}
	else {
		cout << "계좌 종류 선택(1.입출금계좌  2.예금계좌  3.마이너스계좌): ";
		int num; cin >> num;
		cout << "계좌개설을 위한 입력(계좌ID  잔액  이름): ";
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
			cout << "1~3 사이의 숫자를 입력해주세요" << endl;
			break;
		}
		act[index]->AddCount();
		index++;
	}
}
void DeleteAccount(Account** act, int index)
{
	cout << "제거할 계좌 ID: ";
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
				cout << "계좌를 제거하였습니다!" << endl;
			}
			flag = true;
		}
	}
	if (flag == false)
		cout << "해당 ID의 계좌를 찾을 수 없습니다!" << endl;
}
void Deposit(Account** act, int index)
{
	bool flag = false;
	cout << "계좌ID: ";
	int id; cin >> id;
	for (int i = 0; i < index; i++)
	{
		if (act[i]->GetId() == id)
		{
			cout << "입금액: ";
			int input; cin >> input;
			act[i]->Deposit(input);
			cout << "현재잔고: " << act[i]->GetBalance() << endl;
			flag = true;
		}
	}
	if (flag == false)
		cout << "해당 계좌가 없습니다." << endl;
}
void Withdraw(Account** act, int index)
{
	bool flag = false;
	cout << "계좌 ID: "; 
	int id; cin >> id;
	for (int i = 0; i < index; i++)
	{
		try
		{
			if (act[i]->GetId() == id)
			{
				cout << "출금액: ";
				int input; cin >> input;
				act[i]->Withdraw(input);
				cout << "현재잔고: " << act[i]->GetBalance() << endl;
				flag = true;
			}
		}
		catch (MyException* e)
		{
			e->Report();
		}
	}
	if (flag == false)
		cout << "해당 계좌가 없습니다." << endl;
}
void CountAccount()
{
	cout << "현재 계좌의 수는 : " <<  Account::getTotACT() << endl;
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