#include <iostream>
using namespace std;
int* ShiftLint(int* source, int num);
int main()
{
	cout << "�����ǿ� ǥ���� ����: "; int num; cin >> num;
	int* input = new int[num];
	cout << num << "���� ���ڸ� �Է��Ͻÿ�: ";
	for (int i = 0; i < num; i++)
		cin >> input[i];

	int* preInt = input;
	int* curInt = NULL;

	cout << "move: "; int mv; cin >> mv;
	
	for (int j = 0; j < mv; j++) 
	{
		curInt = ShiftLint(preInt, num);
		preInt = curInt;
	}
		
	for (int i = 0; i < num; i++)
	{
		cout << preInt[i] << "  ";
	}

	delete preInt; preInt = NULL;
	preInt = curInt;
	curInt = NULL;

	return 0;
}
int* ShiftLint(int* source, int num)
{
	int* mvInt = new int[num];
	mvInt[num - 1] = source[0];
	for (int i = 1; i < num; i++)
		mvInt[i - 1] = source[i];
	
	return mvInt;
}