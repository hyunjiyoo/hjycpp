#include <iostream>
using namespace std;
void SameSig(int i);
void SameSig(int* ip);
// void SameSig(int& ir);
int main() {
	int k = 100;
	SameSig(k);
	SameSig(&k);

	return 0;
}
void SameSig(int i) {
	cout << "I'm in SamSig(int i)" << endl;
}
void SameSig(int* ip) {
	cout << "I'm in SamSig(int* ip)" << endl;
}
//void SameSig(int& ip) {
//	cout << "I'm in SameSig(int& ir)" << endl;
//}