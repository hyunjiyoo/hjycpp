#include <iostream>
#include "Student.h"
using namespace std;
void func1();
void func2();
int main() {
	Student::printScnt(); // 0
	Student s1("유현지", 1);
	Student::printScnt(); // 1
	func2();
	Student::printScnt(); // 1

	return 0;
}
void func1() {
	Student s1("김석주", 2);
	Student s2("방가영", 3);
	Student::printScnt(); // 4
}
void func2() {
	Student s1("김예린", 4);
	func1();
	Student::printScnt(); // 2
}