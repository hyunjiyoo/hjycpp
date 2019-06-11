#include "Student.h"

Student::Student()
	:Person()
{
	cout << "Student: 인자 없는 생성자" << endl;
	this->stdId = 0;
	this->major = new char[MAX];
	this->major[0] = NULL;
}
Student::Student(const char* name, int age, int stdId, const char* major)
	:Person(name, age)
{
	cout << "Student: 인자 있는 생성자" << endl;
	this->stdId = stdId;
	int len = strlen(major);
	this->major = new char[len + 1];
	strcpy_s(this->major, len + 1, major);
}
Student::Student(const Student& obj)
	:Person(obj)
{
	cout << "Student: 복사 생성자" << endl;
	this->stdId = obj.stdId;
	int len = strlen(obj.name);
	strcpy_s(this->major, len + 1, obj.major);
}
Student::~Student() {
	cout << "Student: 소멸자" << endl;
	delete[] this->major;
	this->major = NULL;
}
Student& Student::operator=(const Student& obj) {
	cout << "Student: 대입 연산자" << endl;
	if (this != &obj) {
		delete[] this->major;
		this->major = NULL;
		int len = strlen(obj.major);
		this->major = new char[len + 1];
		strcpy_s(this->major, len + 1, obj.major);
	}
	return *this;
}
void Student::setStdId(int stdId) {
	this->stdId = stdId;
}
void Student::setMajor(const char* major) {
	if (this->major != major) {
		delete[] this->major;
		this->major = NULL;
		int len = strlen(major);
		this->major = new char[len + 1];
		strcpy_s(this->major, len + 1, major);
	}
}
int Student::getStdId() {
	return this->stdId;
}
char* Student::getMajor() {
	return this->major;
}
void Student::Print() {
	cout << "이름: " << getName() << endl;
	cout << "나이: " << getAge() << endl;
	cout << "학번: " << getStdId() << endl;
	cout << "전공: " << getMajor() << endl;
}
void Student::Write(int index) {
	ofstream fout;
	fout.open("Student.txt");
	if (!fout) {
		cout << "Error: Student.txt 파일을 열 수 없습니다." << endl;
		return;
	}
	for (int i = 0; i < index; i++) {
		int len = strlen(this[i].name);
		for (int j = 0; j < len + 1; j++) {
			fout << this[i].name[j];
		}
		fout << endl;
		fout << this[i].age << endl;
		fout << this[i].stdId << endl;
		for (int k = 0; k < strlen(this[i].major) + 1; k++) {
			fout << this[i].major[k];
		}
		fout << endl;
	}
	fout.close();
}