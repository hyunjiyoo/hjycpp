#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int DEFAULT_ARR_SIZE = 3;
const int DEFAULT_NAME_LEN = 50;
/* ADT ������ ���� */
class SA {
public:
	int* arr; char* name;
	int size; int len;
	SA();
	SA(int arrSize, int arrLen);
	SA(const SA& sa);
	~SA();
	void Print();
	void Sort(int* arr, int size);
};
SA::SA() {
	this->size = DEFAULT_ARR_SIZE;
	this->len = DEFAULT_NAME_LEN;
	this->arr = new int[this->size];
	this->name = new char[this->len];
}
SA::SA(int arrSize, int arrLen) {
	this->size = arrSize;
	this->len = arrLen;
	this->arr = new int[this->size];
	this->name = new char[this->len];
}
SA::SA(const SA& sa) {
	this->size = sa.size;
	this->len = sa.len;
	this->name = new char[this->len];
	this->arr = new int[this->size];
	for (int i = 0; i < sa.size; i++) {
		this->arr[i] = sa.arr[i];
	}
}
SA::~SA() {
	delete[] this->arr;
	this->arr = NULL;
}
void SA::Print() {
	cout << "�迭 �̸�: " << this->name << " �迭 ���: ";
	for (int i = 0; i < this->size; i++) {
		cout << setw(3) << this->arr[i];
	}
	cout << endl;
}
void SA::Sort(int* arr, int size) {
	int tmp;
	int j;
	for (int i = 1; i <= size; i++) {
		tmp = arr[i];
		for (j = i - 1; j >= 0 && tmp < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}
/* ADT ������ ��*/
enum { INPUT = 1, CHANGE, MAX_MIN, INQUIRE, EXIT };
void InputSa(SA* arrSa, int& index, int n);
void ChangeSa(SA* arrSa, int index);
void MaxMinSa(SA* arrSa, int index);
void InquireSa(SA* arrSa, int index);
void ExitSa(SA* arrSa);
/* Ŭ���̾�Ʈ�� ���� */
int main() {
	cout << "SA ��ü �: ";
	int n; cin >> n;
	SA* sp = new SA[n]; 
	int index = 0;

	while (true) {
		cout << "-------------------MENU-------------------" << endl;
		cout << "1(SA ��ü �̸��� �迭��� �Է��ϱ�)" << endl;
		cout << "2(SA ��ü �����ϱ�)" << endl;
		cout << "3(��ü�����Ͽ� max-min ���ϱ�)" << endl;
		cout << "4(�Էµ� ��ü SA��ü�� �̸��� ���ĵ� �迭����)" << endl;
		cout << "5(�����ϱ�)" << endl << endl;

		cout << "����: ";
		int choice; cin >> choice;
		switch (choice) {
		case INPUT:
			InputSa(sp, index, n);
			break;
		case CHANGE:
			ChangeSa(sp, index);
			break;
		case MAX_MIN:
			MaxMinSa(sp, index);
			break;
		case INQUIRE:
			InquireSa(sp, index);
			break;
		case EXIT:
			ExitSa(sp);
			return 0;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}
	return 0;
}
void InputSa(SA* arrSa, int& index, int n)
{
	if (index >= n) {
		cout << "��ü �迭�� ũ�Ⱑ �� á���ϴ�." << endl;
		return;
	}
	//cin.clear();
	cin.ignore();
	cout << "�̸� �Է�: ";

	char inputName[50];
	cin.getline(inputName, 50);

	strcpy_s(arrSa[index].name, arrSa->len, inputName);
	if (index < n) {
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
			cout << "����Է�: ";
			cin >> arrSa[index].arr[i];
		}
		index++;
	}
}
void ChangeSa(SA* arrSa, int index)
{
	cout << "��ġ �Է�: ";
	int num;
	cin >> num;

	if (num < index && num >= 0) {
		cin.clear();
		cin.ignore();
		cout << "new �̸�: ";
		cin.getline(arrSa[num].name, strlen(arrSa[num].name) + 1);
		cout << "new ������: ";
		cin >> arrSa[num].size;
		for (int i = 0; i < arrSa[num].size; i++) {
			cout << "new ����Է�: ";
			cin >> arrSa[num].arr[i];
		}
	}
	else if (num >= index) {
		cout << index << "���� �� ���� ���� �Է����ּ���" << endl;
	}
}
void MaxMinSa(SA* arrSa, int index)
{
	cin.clear();
	cin.ignore();
	cout << "SA ��ü �̸� �Է�: ";
	char correctName[50];
	cin.getline(correctName, 50);

	for (int i = 0; i < index; i++) {
		if (strcmp(correctName, arrSa[i].name) == 0) {
			SA localSa(arrSa[i]); // SA localSa = arrSa[i];
			int size = localSa.size;
			localSa.Sort(localSa.arr, size - 1);
			cout << "��ü " << correctName << " �� max - min: " << localSa.arr[size - 1] - localSa.arr[0] << endl;
			return;
		}
	}
	if (arrSa->name != 0)
		cout << correctName << "�̸��� ��ü�� ã�� ���߽��ϴ�." << endl;	
}
void InquireSa(SA* arrSa, int index)
{
	for (int i = 0; i < index; i++) {
		arrSa[i].Print();
	}
}
void ExitSa(SA* arrSa)
{
	cin.clear();
	cin.ignore();
	delete[] arrSa; arrSa = NULL;
}