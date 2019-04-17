#include <iostream>
using namespace std;
// 인자가 있는 함수
int max(int a, int b);
int main() {
	int arg1 = 3;
	int arg2 = 5;
	// 인자가 변수여도 달라지는 것은 없다.
	int ret = max(arg1, arg2);
	cout << ret << endl;
	return 0;
}
int max(int a, int b) {
	return a > b ? a : b;
}