#include <iostream>
using namespace std;
// ���ڰ� �ִ� �Լ�
int max(int a, int b);
int main() {
	int arg1 = 3;
	int arg2 = 5;
	// ���ڰ� �������� �޶����� ���� ����.
	int ret = max(arg1, arg2);
	cout << ret << endl;
	return 0;
}
int max(int a, int b) {
	return a > b ? a : b;
}