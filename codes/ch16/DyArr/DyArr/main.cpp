#include <iostream>
using namespace std;

// size ũ���� �޸𸮸� �Ҵ��Ͽ� �� ���� �ּҸ� return �ϴ� �Լ� ����.
int* func(int n); // �����ּҸ� return�ؾ��ؼ� ����Ÿ���� int*
int main() {
	// 1. ���� �޸� �Ҵ�
	//int size;
	//int tot = 0;
	//cout << "�� ���� ����: ";
	//cin >> size;
	//// int* ip = new int[size];
	//// sizeũ���� �޸𸮸� �Ҵ��Ͽ� �� ���� �ּҸ� return�ϴ� �Լ� call.
	//// new int[]�� func()���� �ϰ�, delete[]�� main()���� �ص� �������!! (���� �Լ� �ȿ��� �� �ʿ� ����!!)
	//int *ip = func(size);

	//cout << "������ �Է��Ͻÿ�: ";
	//for (int i = 0; i < size; i++) {
	//	cin >> *(ip + i);
	//	tot += *(ip + i);
	//}
	//float avg = (float)tot / (float)size; // 'tot/size'�� ������ ���ͼ� casting �ʿ�. 
	//cout << "��: " << tot << endl;
	//cout << "���: " << avg << endl;
	//cout << "delete ����  ip: " << ip << endl;
	//cout << "delete ���� *ip: " << *ip << endl;
	//delete[] ip; // ip�� ����Ű�� �迭�� ������� ip�� ���� �ٲ�.
	//ip = NULL;
	//cout << "delete ����  ip: " << ip << endl; 
	//// cout << "delete ���� *ip: " << *ip << endl; // �ٲ� �ּҰ��� �����Ϸ��� �ϸ� err. (ip = NULL ��������)
	//delete[] ip; // ip = NULL; ���ְ� �ѹ� �� delete[] ip; ���ָ� runtime error �ȳ�.

	// 2. char[] �迭 ���� �޸� �Ҵ� [�߿�]
	//char *cp = new char[20];
	//cout << "sizeof(cp): " << sizeof(cp) << endl; // cp�� �����ͺ����� 4byte
	//cout << "strlen(cp): " << strlen(cp) << endl; // '\0' ���ö����� size ����
	//cout << "cp: " << cp << endl; // ���ڿ� ���

	// 3. new, delete
	int* p = new int;
	*p = -888;
	cout << "p: " << p << " *p: " << *p << endl;
	delete p; p = NULL;
	cout << "p: " << p << endl;

	return 0;
}
int* func(int n) {
	int* tp = new int[n];
	return tp;
}