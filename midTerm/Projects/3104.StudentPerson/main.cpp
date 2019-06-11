#include "Student.h"
void Menu();
void CreateStd(Student* std, int& index, int size);
void InquireStd(Student* std, int index);
void ModifyStd(Student* std, int index);
void AllInquireStd(Student* std, int index);
void Exit(Student* std, int index);
enum { EXIT = 0, CREATE, INQUIRE, MODIFY, ALLINQUIRE };
int main() {
	cout << "�Է� ���� �л� �� �Է�: ";
	int num; cin >> num;
	Student* std = new Student[num];

	ifstream fin;
	fin.open("Student.txt");
	if (!fin) {
		cout << "Student.txt ������ �����ϴ�." << endl;
		int index = 0;
		while (true) {
			Menu();
			int choice; cin >> choice;
			switch (choice) {
			case CREATE:
				CreateStd(std, index, num);
				break;
			case INQUIRE:
				InquireStd(std, index);
				break;
			case MODIFY:
				ModifyStd(std, index);
				break;
			case ALLINQUIRE:
				AllInquireStd(std, index);
				break;
			case EXIT:
				Exit(std, index);
				return 0;
			default:
				cout << "�߸� �Է��߽��ϴ�." << endl;
			}
		}
	}
	return 0;
}
void Menu() {
	cout << "==========MENU==========" << endl;
	cout << " Student ����: 1" << endl;
	cout << " Student ��ȸ: 2" << endl;
	cout << " Student ����: 3" << endl;
	cout << " ��� Student ��ȸ: 4" << endl;
	cout << " ���α׷� ����: 0" << endl;
	cout << "========================" << endl;
	cout << "�Է�: ";
}
void CreateStd(Student* std, int& index, int size) {
	if (index == size) {
		cout << "�迭�� �������� ���̻� ������ �� �����ϴ�." << endl;
		return;
	}
	cout << "�̸�: ";
	cin.clear(); cin.ignore();
	char name[MAX]; cin.getline(name, MAX);
	cout << "����: ";
	int age; cin >> age;
	cout << "�й�: ";
	int stdId; cin >> stdId;
	cout << "�а�: ";
	cin.clear(); cin.ignore();
	char major[MAX]; cin.getline(major, MAX);

	std[index].setName(name);
	std[index].setAge(age);
	std[index].setStdId(stdId);
	std[index].setMajor(major);
	index++;
	cout << "��ü�� �����Ǿ����ϴ�." << endl;
}
void InquireStd(Student* std, int index) {
	cout << "��ȸ�Ϸ��� Student �̸�: ";
	cin.clear(); cin.ignore();
	char _name[MAX]; cin.getline(_name, MAX);
	bool flag = false;
	for (int i = 0; i < index; i++) {
		if (strcmp(std[i].getName(), _name) == 0) {
			cout << "�л� ��ü" << endl;
			std[i].Print();
			flag = true;
			return;
		}
	}
	if (flag == false) {
		cout << "�Է��� �̸��� Student�� ã�� ���߽��ϴ�." << endl;
	}
}
void ModifyStd(Student* std, int index) {
	cout << "�����Ϸ��� Student �й�: ";
	int _stdId; cin >> _stdId;
	bool flag = false;

	for (int i = 0; i < index; i++) {
		if (std[i].getStdId() == _stdId) {
			cout << "���� ������ ����: ";
			int _age; cin >> _age;
			cout << "���� ������ �а�: ";
			cin.clear(); cin.ignore();
			char _major[MAX]; cin.getline(_major, MAX);

			std[i].setAge(_age);
			std[i].setMajor(_major);
			flag = true;
			return;
		}
	}
	if (flag == false) {
		cout << "�Է��� �й��� Student�� ã�� ���߽��ϴ�." << endl;
	}
}
void AllInquireStd(Student* std, int index) {
	for (int i = 0; i < index; i++) {
		cout << i << "��° �л� ��ü" << endl;
		std[i].Print();
	}
}
void Exit(Student* std, int index) {
	std->Write(index);
	delete[] std;
	std = NULL;
}