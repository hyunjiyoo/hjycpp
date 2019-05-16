#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int DEFAULT_ARR_SIZE = 3;
const int DEFAULT_NAME_LEN = 50;
/* ADT 정의의 시작 */
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
	cout << "배열 이름: " << this->name << " 배열 요소: ";
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
/* ADT 정의의 끝*/
enum { INPUT = 1, CHANGE, MAX_MIN, INQUIRE, EXIT };
void InputSa(SA* arrSa, int& index, int n);
void ChangeSa(SA* arrSa, int index);
void MaxMinSa(SA* arrSa, int index);
void InquireSa(SA* arrSa, int index);
void ExitSa(SA* arrSa);
/* 클라이언트의 시작 */
int main() {
	cout << "SA 객체 몇개: ";
	int n; cin >> n;
	SA* sp = new SA[n]; 
	int index = 0;

	while (true) {
		cout << "-------------------MENU-------------------" << endl;
		cout << "1(SA 객체 이름과 배열요소 입력하기)" << endl;
		cout << "2(SA 객체 변경하기)" << endl;
		cout << "3(객체복사하여 max-min 구하기)" << endl;
		cout << "4(입력된 전체 SA객체의 이름과 정렬된 배열보기)" << endl;
		cout << "5(종료하기)" << endl << endl;

		cout << "선택: ";
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
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}
	return 0;
}
void InputSa(SA* arrSa, int& index, int n)
{
	if (index >= n) {
		cout << "객체 배열의 크기가 꽉 찼습니다." << endl;
		return;
	}
	//cin.clear();
	cin.ignore();
	cout << "이름 입력: ";

	char inputName[50];
	cin.getline(inputName, 50);

	strcpy_s(arrSa[index].name, arrSa->len, inputName);
	if (index < n) {
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++) {
			cout << "요소입력: ";
			cin >> arrSa[index].arr[i];
		}
		index++;
	}
}
void ChangeSa(SA* arrSa, int index)
{
	cout << "위치 입력: ";
	int num;
	cin >> num;

	if (num < index && num >= 0) {
		cin.clear();
		cin.ignore();
		cout << "new 이름: ";
		cin.getline(arrSa[num].name, strlen(arrSa[num].name) + 1);
		cout << "new 사이즈: ";
		cin >> arrSa[num].size;
		for (int i = 0; i < arrSa[num].size; i++) {
			cout << "new 요소입력: ";
			cin >> arrSa[num].arr[i];
		}
	}
	else if (num >= index) {
		cout << index << "보다 더 작은 수를 입력해주세요" << endl;
	}
}
void MaxMinSa(SA* arrSa, int index)
{
	cin.clear();
	cin.ignore();
	cout << "SA 객체 이름 입력: ";
	char correctName[50];
	cin.getline(correctName, 50);

	for (int i = 0; i < index; i++) {
		if (strcmp(correctName, arrSa[i].name) == 0) {
			SA localSa(arrSa[i]); // SA localSa = arrSa[i];
			int size = localSa.size;
			localSa.Sort(localSa.arr, size - 1);
			cout << "객체 " << correctName << " 의 max - min: " << localSa.arr[size - 1] - localSa.arr[0] << endl;
			return;
		}
	}
	if (arrSa->name != 0)
		cout << correctName << "이름의 객체는 찾지 못했습니다." << endl;	
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