#include <iostream>
using namespace std;
int main() {
	char pwd[100];
	while (true)
	{
		cout << "��ȣ �Է�: ";
		cin.getline(pwd, 100, '\n');
		if (strcmp(pwd, "alpha go") == 0) {
			cout << "Correct password" << endl;
			break; // loop Ż��
		}
		else if (strcmp(pwd, "\0") == 0) {
			cout << "exit" << endl;
			break; // null ���ڿ� ���������� loop Ż��
		}
		else {
			cout << "Incorrect password" << endl;
		}
	}
	return 0;
}