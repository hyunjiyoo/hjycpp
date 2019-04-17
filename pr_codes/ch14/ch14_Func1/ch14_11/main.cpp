#include <iostream>
using namespace std;
void GCD_LCM(int a, int b, int* pgcd, int* plcm);
int main() {
	int gcd = 0;
	int lcm = 0;
	GCD_LCM(28, 35, &gcd, &lcm);

	cout << "GCD: " << gcd << endl;
	cout << "LCM: " << lcm << endl;
	return 0;
}
void GCD_LCM(int a, int b, int* pgcd, int* plcm) {
	int z;
	int x = a;
	int y = b;
	while (true) {
		z = x % y;
		if (z == 0)
			break;
		x = y;
		y = z;
	}
	*pgcd = y;
	*plcm = a * b / *pgcd;
}