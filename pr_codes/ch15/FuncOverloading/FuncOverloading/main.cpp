#include <iostream>
using namespace std;
void SameSig(int i);
void SameSig(int *ip);
// void SameSig(int& ir); // call by reference는 함수의 시그니처가 될 수 없다.
int main() {
	int k = 100;
	// Compile Error
	// 오버로드된 함수 "SameSig"의 인스턴스 중 두 개 이상이 인수 목록과 일치합니다.
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
