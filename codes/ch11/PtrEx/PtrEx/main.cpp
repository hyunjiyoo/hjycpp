#include <iostream>
using namespace std;
int main() {
	// 1. 10진수와 16진수 
	//    한번 hex로 바꾸면 계속 hex로 나와서 dec로 다시 바꿔줘야 함.
	cout << "242: " << 242 << " " << hex << showbase << 242 << endl;
	cout << "27: " << dec << 27 << " " << hex << showbase << 27 << endl;
	cout << "33: " << dec << 33 << " " << hex << showbase << 33 << endl;
	cout << "237: " << dec << 237 << " " << hex << showbase << 237 << dec << endl;
	
	char carray1[] = "ABCDE";
	char carray2[] = { 'A', 'B', 'C', 'D', 'E', '\0' };

	cout << "sizeof(carray1): " << sizeof(carray1) << endl;
	cout << "sizeof(carray2): " << sizeof(carray2) << endl;


	return 0;
}