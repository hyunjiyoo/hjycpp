#include <iostream>
using namespace std;
void Sub(int i, int* p, int& r);
int main() {
	int a = 0, b = 0, c = 0;
	Sub(a, &b, c);
	cout << a << " " << b << " " << c << endl;
	return 0;
}
void Sub(int i, int* p, int& r) {
	i = 10;
	*p = 20;
	r = 30;
}