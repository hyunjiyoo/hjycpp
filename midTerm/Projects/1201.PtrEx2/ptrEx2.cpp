#include <iostream>
using namespace std;
int main() {
	int A[10] = { -999, -888, -777, -666, -555 };
	int* p = A;
	cout << p << endl;
	// A[0]이 먼저 '0'으로 바뀝.
	for (int i = 0; i < 10; i++)
	{
		// 후치연산이기때문에 대입되어 바뀌고 p증가
		*p++ = i * i * i;
		cout << A[i] << endl;

		// runtime error (전치연산이기때문에 4만큼 먼저 늘어나고 *p에 대입) 그래서 배열의 크기를 넘어섬.
		// cout << p++ << endl; 과 같은 원리
		// *++p = i * i * i; 
	}
	cout << p << endl;

	return 0;
}