#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[] = "hello";
	char a;
	int i, j;

	for (i = 0; i < strlen(str) + 1; i++) {
		cout << str << endl;
		a = str[0];
		for (j = 1; j < strlen(str); j++)
			str[j - 1] = str[j];

		str[strlen(str) - 1] = a;
	}
	return 0;
}