#include <iostream>
using namespace std;
const int MAX = 100;
void swap_string(char* p1, char* p2, int size);
int main() {
	char A[MAX];
	char B[MAX];
	while(1) {
		cout << "처음 문자열: ";
		cin.getline(A, MAX, '\n');
		if (strcmp(A, "\0") == 0) {
			break;
		}
		cout << "두번째 문자열: ";
		cin.getline(B, MAX, '\n');
		if (strcmp(B, "\0") == 0) {
			break;
		}
		cout << "swap_string 콜 후" << endl;
		swap_string(A, B, MAX);
		cout << "처음 문자열은 " << A << endl << "두번째 문자열은 " << B << endl;
		cout << "------------------------------------------------" << endl;
	}
	return 0;
}
void swap_string(char* p1, char* p2, int size) {
	char swap[MAX];
	for (int i = 0; i < size; i++) {
		swap[i] = p1[i];
		p1[i] = p2[i];
		p2[i] = swap[i];
	}
}