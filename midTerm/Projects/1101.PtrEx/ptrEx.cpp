#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int a = 200;
	int b = 30;
	double c = 56789000;
	int* ip = &a;
	int* ip2 = &b;
	double* dp = &c;
	char d = 'A';
	void* vp = ip;
	*ip2 = 33;

	cout << setw(15) << "dp: " << dp << endl;
	cout << setw(15) << "*ip2:" << *ip2 << endl;
	cout << setw(15) << "&b: " << &b << endl;
	cout << setw(15) << "sizeof(dp): " << sizeof(dp) << endl;
	cout << setw(15) << "&d: " << &d << endl;
	cout << "-------------------------------------" << endl;

	// 1. 10������ 16���� 
	//    �ѹ� hex�� �ٲٸ� ��� hex�� ���ͼ� dec�� �ٽ� �ٲ���� ��.
	cout << "242: " << 242 << " " << hex << showbase << 242 << endl;
	cout << "27: " << dec << 27 << " " << hex << showbase << 27 << endl;
	cout << "33: " << dec << 33 << " " << hex << showbase << 33 << endl;
	cout << "237: " << dec << 237 << " " << hex << showbase << 237 << dec << endl;
	cout << "-------------------------------------" << endl;


	char carray1[] = "ABCDE";
	char carray2[] = { 'A', 'B', 'C', 'D', 'E', '\0' };
	cout << "sizeof(carray1): " << sizeof(carray1) << endl;
	cout << "sizeof(carray2): " << sizeof(carray2) << endl;

	return 0;
}