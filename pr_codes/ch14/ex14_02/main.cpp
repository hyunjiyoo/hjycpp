#include <iostream>
using namespace std;
char* returnName(char* str);
int main() {
	char name[] = "hyunjiyoo";
	for (int i = 0; i < 10; i++) {
		cout << returnName(name) << endl;
	}
	return 0;
}
char* returnName(char* str) {
	return str;
}