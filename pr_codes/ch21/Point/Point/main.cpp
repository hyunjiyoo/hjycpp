#include <iostream>
using namespace std;
class Point 
{
public:
	int x, y;

	Point();
	Point(int initX, int initY);
	Point(const Point& p);

	~Point();

	void Print();
};
Point::Point() {
	cout << "���� ���� ������" << endl;
	this->x = 0;
	this->y = 0;
}
Point::Point(int initX, int initY) {
	cout << "���� �ִ� ������" << endl;
	this->x = initX;
	this->y = initY;
}
Point::Point(const Point& p) {
	cout << "���� ������" << endl;
	this->x = p.x;
	this->y = p.y;
}
Point::~Point() {
	cout << "�Ҹ���" << endl;
}
void Point::Print() {
	cout << "(" << x << ", " << y << ")" << endl;
}
enum { MAKE = 1, UPDATE, INQUIRE, EXIT };
void PrintMenu();
void MakePoint(Point* Arr, int& indexPtr, int size);
void UpdatePoint(Point* Arr, int& indexPtr, int size);
void InquirePoint(Point* Arr, int& indexPtr);
int main() {
	/* 1.Point��ü ������. */
	Point pt1, pt2;
	pt1.x = 500; pt1.y = 5;
	pt1.Print(); pt2.Print();
	cout << "sizeof(Point): " << sizeof(Point) << endl;
	cout << "sizeof(pt1): " << sizeof(pt1) << endl;
	cout << "sizeof(pt2): " << sizeof(pt2) << endl;
	cout << "&pt1: " << &pt1 << endl;
	cout << "&pt1.x: " << &pt1.x << endl;
	cout << "&pt1.y: " << &pt1.y << endl;
	cout << "&pt2: " << &pt2 << endl;

	/* 2.�����ڿ� �Ҹ��� */
	// Point ADT�� ����ϴ� Ŭ���̾�Ʈ�� ����
	const int SIZE = 5;
	int index = 0;
	Point Arr[SIZE]; // ��ü 10�� ����(���ھ��� �����ڰ� SIZE��ŭ ȣ��)
	int choice;
	while (true)
	{
		PrintMenu();
		cout << "����: ";
		cin >> choice;
		switch (choice)
		{
		case MAKE:
			MakePoint(Arr, index, SIZE);
			break;
		case UPDATE:
			UpdatePoint(Arr, index, SIZE);
			break;
		case INQUIRE:
			InquirePoint(Arr, index);
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}
	return 0;
}
void PrintMenu() {
	cout << "----------------MENU-----------------" << endl;
	cout << "1.(Point ��ǥ ä���)" << endl;
	cout << "2.(Point ��ǥ �����ϱ�)" << endl;
	cout << "3.(��ü ��ȸ)" << endl;
	cout << "4.(���α׷� ����)" << endl;
}
void MakePoint(Point* Arr, int& indexPtr, int size) {
	cout << "MakePoint() ȣ��" << endl;
	while (true) {
		if (indexPtr >= size) {
			cout << "�迭�� SIZE�� �� á���ϴ�." << endl;
			break;
		}
		cout << "��ǥ�� �Է����ּ���: ";
		cin >> Arr[indexPtr].x >> Arr[indexPtr].y;
		Arr[indexPtr].Print();
		indexPtr++;
		return;
	}
}
void UpdatePoint(Point* Arr, int& indexPtr, int size) {
	cout << "UpdatePoint() ȣ��" << endl;
	while (true) {
		cout << "������ ��ǥ��ȣ�� �Է����ּ���: ";
		int num; cin >> num;
		if (num > indexPtr) {
			cout << "�� ���� ��ȣ�� �Է����ּ���" << endl;
			return;
		}
		cout << "������ ���� �Է����ּ���: ";
		cin >> Arr[num-1].x >> Arr[num-1].y;
		return;
	}
}
void InquirePoint(Point* Arr, int& indexPtr) {
	cout << "InquirePoint() ȣ��" << endl;
	for (int i = 0; i < indexPtr; i++)
		Arr[i].Print();
}