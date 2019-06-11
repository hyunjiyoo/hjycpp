#include "Student.h"
void Menu();
void CreateStd(Student* std, int& index, int size);
void InquireStd(Student* std, int index);
void ModifyStd(Student* std, int index);
void AllInquireStd(Student* std, int index);
void Exit(Student* std, int index);
enum { EXIT = 0, CREATE, INQUIRE, MODIFY, ALLINQUIRE };
int main() {
	cout << "입력 받을 학생 수 입력: ";
	int num; cin >> num;
	Student* std = new Student[num];

	ifstream fin;
	fin.open("Student.txt");
	if (!fin) {
		cout << "Student.txt 파일이 없습니다." << endl;
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
				cout << "잘못 입력했습니다." << endl;
			}
		}
	}
	return 0;
}
void Menu() {
	cout << "==========MENU==========" << endl;
	cout << " Student 생성: 1" << endl;
	cout << " Student 조회: 2" << endl;
	cout << " Student 수정: 3" << endl;
	cout << " 모든 Student 조회: 4" << endl;
	cout << " 프로그램 종료: 0" << endl;
	cout << "========================" << endl;
	cout << "입력: ";
}
void CreateStd(Student* std, int& index, int size) {
	if (index == size) {
		cout << "배열이 가득차여 더이상 생성할 수 없습니다." << endl;
		return;
	}
	cout << "이름: ";
	cin.clear(); cin.ignore();
	char name[MAX]; cin.getline(name, MAX);
	cout << "나이: ";
	int age; cin >> age;
	cout << "학번: ";
	int stdId; cin >> stdId;
	cout << "학과: ";
	cin.clear(); cin.ignore();
	char major[MAX]; cin.getline(major, MAX);

	std[index].setName(name);
	std[index].setAge(age);
	std[index].setStdId(stdId);
	std[index].setMajor(major);
	index++;
	cout << "객체가 생성되었습니다." << endl;
}
void InquireStd(Student* std, int index) {
	cout << "조회하려는 Student 이름: ";
	cin.clear(); cin.ignore();
	char _name[MAX]; cin.getline(_name, MAX);
	bool flag = false;
	for (int i = 0; i < index; i++) {
		if (strcmp(std[i].getName(), _name) == 0) {
			cout << "학생 객체" << endl;
			std[i].Print();
			flag = true;
			return;
		}
	}
	if (flag == false) {
		cout << "입력한 이름의 Student를 찾지 못했습니다." << endl;
	}
}
void ModifyStd(Student* std, int index) {
	cout << "수정하려는 Student 학번: ";
	int _stdId; cin >> _stdId;
	bool flag = false;

	for (int i = 0; i < index; i++) {
		if (std[i].getStdId() == _stdId) {
			cout << "새로 설정할 나이: ";
			int _age; cin >> _age;
			cout << "새로 설정할 학과: ";
			cin.clear(); cin.ignore();
			char _major[MAX]; cin.getline(_major, MAX);

			std[i].setAge(_age);
			std[i].setMajor(_major);
			flag = true;
			return;
		}
	}
	if (flag == false) {
		cout << "입력한 학번의 Student를 찾지 못했습니다." << endl;
	}
}
void AllInquireStd(Student* std, int index) {
	for (int i = 0; i < index; i++) {
		cout << i << "번째 학생 객체" << endl;
		std[i].Print();
	}
}
void Exit(Student* std, int index) {
	std->Write(index);
	delete[] std;
	std = NULL;
}