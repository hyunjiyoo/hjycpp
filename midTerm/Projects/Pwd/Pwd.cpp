#include <iostream>
using namespace std;
int main() {
	char pwd[100];
	while (true)
	{
		cout << "¾ÏÈ£ ÀÔ·Â: ";
		cin.getline(pwd, 100, '\n');
		if (strcmp(pwd, "alpha go") == 0) {
			cout << "Correct password" << endl;
			break; // loop Å»Ãâ
		}
		else if (strcmp(pwd, "\0") == 0) {
			cout << "exit" << endl;
			break; // null ¹®ÀÚ¿­ ¸¸³µÀ»¶§µµ loop Å»Ãâ
		}
		else {
			cout << "Incorrect password" << endl;
		}
	}
	return 0;
}