#include <iostream>
using namespace std;
int main() {
	char pwd[100];
	while (true) 
	{
		cout << "��ȣ �Է�: ";
		cin.getline(pwd, 100, '\n');
		// ��ȣ ������ loop Ż��
		if (strcmp(pwd, "alpha go") == 0) {
			cout << "Correct password" << endl;
			break;
		}
		// null ���ڿ� ������ �� loop Ż��
		else if (strcmp(pwd, "\0") == 0) {
			cout << "exit" << endl;
			break;
		} 
		else {
			cout << "��ȣ�� Ʋ���ϴ�." << endl;
		}
	}
	return 0;
}