#include <iostream>
using namespace std;
int main() {
	char pwd[100];
	while (true) 
	{
		cout << "암호 입력: ";
		cin.getline(pwd, 100, '\n');
		// 암호 맞으면 loop 탈출
		if (strcmp(pwd, "alpha go") == 0) {
			cout << "Correct password" << endl;
			break;
		}
		// null 문자열 만났을 때 loop 탈출
		else if (strcmp(pwd, "\0") == 0) {
			cout << "exit" << endl;
			break;
		} 
		else {
			cout << "암호가 틀립니다." << endl;
		}
	}
	return 0;
}