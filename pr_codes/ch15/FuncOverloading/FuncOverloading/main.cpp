#include <iostream>
using namespace std;
void SameSig(int i);
void SameSig(int *ip);
// void SameSig(int& ir); // call by reference�� �Լ��� �ñ״�ó�� �� �� ����.
int main() {
	int k = 100;
	// Compile Error
	// �����ε�� �Լ� "SameSig"�� �ν��Ͻ� �� �� �� �̻��� �μ� ��ϰ� ��ġ�մϴ�.
	SameSig(k);
	SameSig(&k);

	return 0;
}
void SameSig(int i) {
	cout << "I'm in SameSig(int i)" << endl;
}
void SameSig(int *ip) {
	cout << "I'm in SameSig(int *ip)" << endl;
}
//void SameSig(int &ip) {
//	cout << "I'm in SameSig(int &ir)" << endl;
//}
