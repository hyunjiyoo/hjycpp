#include <iostream>
using namespace std;
int main() {
	int A[10] = { -999, -888, -777, -666, -555 };
	int* p = A;
	cout << p << endl;
	// A[0]�� ���� '0'���� �ٲ�.
	for (int i = 0; i < 10; i++)
	{
		// ��ġ�����̱⶧���� ���ԵǾ� �ٲ�� p����
		*p++ = i * i * i;
		cout << A[i] << endl;

		// runtime error (��ġ�����̱⶧���� 4��ŭ ���� �þ�� *p�� ����) �׷��� �迭�� ũ�⸦ �Ѿ.
		// cout << p++ << endl; �� ���� ����
		// *++p = i * i * i; 
	}
	cout << p << endl;

	return 0;
}