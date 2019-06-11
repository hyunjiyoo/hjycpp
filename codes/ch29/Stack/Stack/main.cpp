#include <iostream>
#include "StackTemp.h"
using namespace std;
int main() {
	Stack S(7);
	S.push('a');
	S.push('b');
	S.push('c');
	for (int i = 0; i < 3; i++) {
		cout << S.pop() << endl;
	}

	return 0;
}