#include <iostream>
using namespace std;
int Factorial(int n);
int main() {
	int result;
	result = Factorial(5);
	cout << "5!�� " << result << "�Դϴ�." << endl;
	return 0;
}
int Factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}