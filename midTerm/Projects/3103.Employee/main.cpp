#include <iostream>
using namespace std;
/* Employee START */
class Employee
{
protected:
	char* name;
public:
	Employee();
	Employee(char* name);
	Employee(const Employee& obj);
	virtual ~Employee();
	Employee& operator=(const Employee& obj);
	void SetName(char* name);
	char* GetName();
	virtual double GetPay();
};
Employee::Employee()
{
	cout << "Employee: ���ھ��� ������" << endl;
	this->name = NULL;
}
Employee::Employee(char* name)
{
	cout << "Employee: �����ִ� ������" << endl;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}
Employee::Employee(const Employee& obj)
{
	cout << "Employee: ���� ������" << endl;
	int len = strlen(obj.name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, obj.name);
}
Employee::~Employee()
{
	cout << "Employee: �Ҹ���" << endl;
	delete[] this->name;
	this->name = NULL;
}
Employee& Employee::operator=(const Employee& obj)
{
	cout << "Employee: ���� ���� ���� ������" << endl;
	if (this != &obj) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
	}
	return *this;
}
void Employee::SetName(char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}
char* Employee::GetName()
{
	return this->name;
}
double Employee::GetPay()
{
	return 0.0;
}
/* Employee END */

/* Permanent START */
class Permanent :public Employee
{
protected:
	int salary;
public:
	Permanent();
	Permanent(char* name, int salary);
	Permanent(const Permanent& obj);
	~Permanent();
	Permanent& operator=(const Permanent& obj);
	void SetSalary(int salary);
	double GetPay();
};
Permanent::Permanent()
	:Employee()
{
	cout << "Permanent: ���� ���� ������" << endl;
	this->salary = 0;
}
Permanent::Permanent(char* name, int salary)
	: Employee(name)
{
	cout << "Permanent: ���� �ִ� ������" << endl;
	this->salary = salary;
}
Permanent::Permanent(const Permanent& obj)
	: Employee(obj)
{
	cout << "Permanent: ���� ������" << endl;
	this->salary = obj.salary;
}
Permanent::~Permanent()
{
	cout << "Permanent: �Ҹ���" << endl;
}
Permanent& Permanent::operator=(const Permanent& obj)
{
	if (this != &obj) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->salary = obj.salary;
	}
	return *this;
}
void Permanent::SetSalary(int salary)
{
	this->salary = salary;
}
double Permanent::GetPay()
{
	return this->salary;
}
/* Permanent END */
/* Temporary START */
class Temporary :public Employee
{
protected:
	int hourlyPay;
	double hour;
public:
	Temporary();
	Temporary(char* name, int hourlyPay, double hour);
	Temporary(const Temporary& obj);
	~Temporary();
	Temporary& operator=(const Temporary& obj);
	void SetHourlyPay(int hourlyPay);
	void SetHour(double hour);
	double GetPay();
};
Temporary::Temporary()
	:Employee()
{
	cout << "Temporary: ���� ���� ������" << endl;
	this->hourlyPay = 0;
	this->hour = 0.0;
}
Temporary::Temporary(char* name, int hourlyPay, double hour)
	:Employee(name)
{
	cout << "Temporary: ���� �ִ� ������" << endl;
	this->hourlyPay = hourlyPay;
	this->hour = hour;
}
Temporary::Temporary(const Temporary& obj)
	:Employee(obj)
{
	cout << "Temporary: ���� �ִ� ������" << endl;
	this->hourlyPay = obj.hourlyPay;
	this->hour = obj.hour;
}
Temporary::~Temporary()
{
	cout << "Temporary: �Ҹ���" << endl;
}
Temporary& Temporary::operator=(const Temporary& obj)
{
	if (this != &obj) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->hourlyPay = obj.hourlyPay;
		this->hour = obj.hour;
	}
	return *this;
}
void Temporary::SetHourlyPay(int hourlyPay)
{
	this->hourlyPay = hourlyPay;
}
void Temporary::SetHour(double hour)
{
	this->hour = hour;
}
double Temporary::GetPay()
{
	return (double)this->hourlyPay * this->hour;
}
/* Temporary END */
/* Sales START */
class Sales :public Employee
{
protected:
	int salary;
	int profit;
public:
	Sales();
	Sales(char* name, int salary, int profit);
	Sales(const Sales& obj);
	~Sales();
	Sales& operator=(const Sales& obj);
	void SetSalary(int salary);
	void SetProfit(int profit);
	double GetPay();
};
Sales::Sales()
	:Employee()
{
	cout << "Sales: ���� ���� ������" << endl;
	this->salary = 0;
	this->profit = 0;
}
Sales::Sales(char* name, int salary, int profit)
	:Employee(name)
{
	cout << "Sales: ���� �ִ� ������" << endl;
	this->salary = salary;
	this->profit = profit;
}
Sales::Sales(const Sales& obj)
	:Employee(obj)
{
	cout << "Sales: ���� ������" << endl;
	this->salary = obj.salary;
	this->profit = obj.profit;
}
Sales::~Sales()
{
	cout << "Sales: �Ҹ���" << endl;
}
Sales& Sales::operator=(const Sales& obj)
{
	cout << "Sales: ���� ���� ���� ������" << endl;
	if (this != &obj) {
		delete[] this->name;
		this->name = NULL;
		int len = strlen(obj.name);
		this->name = new char[len + 1];
		strcpy_s(this->name, len + 1, obj.name);
		this->salary = obj.salary;
		this->profit = obj.profit;
	}
	return *this;
}
void Sales::SetSalary(int salary)
{
	this->salary = salary;
}
void Sales::SetProfit(int profit)
{
	this->profit = profit;
}
double Sales::GetPay()
{
	return this->salary + (0.15 * (double)this->profit);
}
/* Sales END */
const int ARR_MAX = 5;
enum { ADD_PER = 1, ADD_TEM, ADD_SALES, SALARY, EXIT };
void ShowMenu();
void AddPermanent(Employee** emp, int& top, int size);
void AddTemporary(Employee** emp, int& top, int size);
void AddSales(Employee** emp, int& top, int size);
void Salary(Employee** emp, int top);
void Exit(Employee** emp, int top);
int main() {
	Employee* emp[ARR_MAX];
	int top = 0;
	int choice;
	while (true)
	{
		ShowMenu();
		cout << "����: "; cin >> choice;
		switch (choice)
		{
		case ADD_PER:
			AddPermanent(emp, top, ARR_MAX);
			break;
		case ADD_TEM:
			AddTemporary(emp, top, ARR_MAX);
			break;
		case ADD_SALES:
			AddSales(emp, top, ARR_MAX);
			break;
		case SALARY:
			Salary(emp, top);
			break;
		case EXIT:
			Exit(emp, top);
			return 0;
		default:
			cout << "1~5 ������ ���ڸ� �Է��ϼ���." << endl;
			break;
		}
	}
	return 0;
}
void ShowMenu()
{
	cout << "1: Permanent �߰��ϱ�" << endl;
	cout << "2: Temporary �߰��ϱ�" << endl;
	cout << "3: Sales �߰��ϱ�" << endl;
	cout << "4: �޿� ������ �ֱ�" << endl;
	cout << "5: ���α׷� ����" << endl;
}
void AddPermanent(Employee** emp, int& top, int size)
{
	if (top == size) {
		cout << "�迭�� ���� á���ϴ�." << endl;
		return;
	}
	else {
		char name[10]; int salary;
		cout << "�̸�: "; cin >> name;
		cout << "����: "; cin >> salary;
		emp[top] = new Permanent(name, salary);
		top++;
	}
}
void AddTemporary(Employee** emp, int& top, int size)
{
	if (top == size) {
		cout << "�迭�� ���� á���ϴ�." << endl;
		return;
	}
	else {
		char name[10];  int hourlyPay; double hour;
		cout << "�̸�: "; cin >> name;
		cout << "�ñ�: "; cin >> hourlyPay;
		cout << "�ð�: "; cin >> hour;
		emp[top] = new Temporary(name, hourlyPay, hour);
		top++;
	}
}
void AddSales(Employee** emp, int& top, int size)
{
	if (top == size) {
		cout << "�迭�� ���� á���ϴ�." << endl;
		return;
	}
	else {
		char name[10];  int salary; int profit;
		cout << "�̸�: "; cin >> name;
		cout << "����: "; cin >> salary;
		cout << "�߰�����: "; cin >> profit;
		emp[top] = new Sales(name, salary, profit);
		top++;
	}
}
void Salary(Employee** emp, int top)
{
	for (int i = 0; i < top; i++) {
		cout << emp[i]->GetName() << ": " << emp[i]->GetPay() << "��" << endl;
	}

}
void Exit(Employee** emp, int top)
{
	cout << "Exit" << endl;
	for (int i = 0; i < top; i++) {
		if (emp[i] != NULL) {
			delete emp[i];
			emp[i] = NULL;
		}
	}
}