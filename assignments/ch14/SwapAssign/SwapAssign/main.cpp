#include <iostream>
using namespace std;
const int MAX = 100;
void swap_string(char* p1, char* p2, int size);
int main() {
	char A[MAX];
	char B[MAX];
	while(1) {
		cout << "ó�� ���ڿ�: ";
		cin.getline(A, MAX, '\n');
		if (strcmp(A, "\0") == 0) {
			break;
		}
		cout << "�ι�° ���ڿ�: ";
		cin.getline(B, MAX, '\n');
		if (strcmp(B, "\0") == 0) {
			break;
		}
		cout << "swap_string �� ��" << endl;
		swap_string(A, B, MAX);
		cout << "ó�� ���ڿ��� " << A << endl << "�ι�° ���ڿ��� " << B << endl;
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