#include <iostream>
#include <iomanip>
using namespace std;
class Point {
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
void MakePoint(Point* p, int& index, int size);
void UpdatePoint(Point* p, int index);
void InquirePoint(Point* p, int index);
int main() {
	// 1.Point ��ü ������
	Point pt1, pt2;
	pt1.x = 500; pt1.y = 5;
	pt1.Print(); pt2.Print();
	cout << "sizeof(Point): " << sizeof(Point) << endl; // 8
	cout << "sizeof(pt1): " << sizeof(pt1) << endl; // 8
	cout << "sizeof(pt2): " << sizeof(pt2) << endl; // 8
	cout << "&pt1: " << &pt1 << endl; 
	cout << "&pt1.x: " << &pt1.x << endl;
	cout << "&pt1.y: " << &pt1.y << endl;
	cout << "&pt2: " << &pt2 << endl;

	// 2. �����ڿ� �Ҹ���
	Point ppt1; ppt1.Print();
	Point ppt2(3, 5); ppt2.Print();
	Point ppt3(ppt2); ppt3.Print();
	
	// 3. Menu driven
	// Point ADT�� ����ϴ� Ŭ���̾�Ʈ�� ����
	const int SIZE = 3;
	int index = 0;
	Point A[SIZE];
	int choice;
	while (true)
	{
		PrintMenu();
		cout << "����: ";
		cin >> choice;
		switch (choice)
		{
		case MAKE:
			MakePoint(A, index, SIZE);
			break;
		case UPDATE:
			UpdatePoint(A, index);
			break;
		case INQUIRE:
			InquirePoint(A, index);
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
	cout << "---------MENU----------" << endl;
	cout << "1.(Point ��ǥ ä���)" << endl;
	cout << "2.(Point ��ǥ �����ϱ�)" << endl;
	cout << "3.(��ü ��ȸ)" << endl;
	cout << "4.(���α׷� ����)" << endl;
}
void MakePoint(Point* p, int& index, int size) {
	// Point* p = A;
	if (index >= size) {
		cout << "���̻� ��ǥ�� �Է��� �� �����ϴ�." << endl;
		return;
	}
	cout << "MakePoint()" << endl;
	cout << "x��ǥ �Է�: ";
	cin >> p[index].x;
	cout << "y��ǥ �Է�: ";
	cin >> p[index].y;
	index++;
}
void UpdatePoint(Point* p, int index) {
	cout << "UpdatePoint()" << endl;
	while (true) {
		cout << "��ġ�� �����ϼ���: ";
		int num; cin >> num;
		if (index <= num || num < 0) {
			cout << "0���� " << index - 1 << "������ ���� �Է����ּ���" << endl;
			continue;
		}
		cout << "������ x�� �Է�: ";
		cin >> p[num].x;
		cout << "������ y�� �Է�: ";
		cin >> p[num].y;
		break;
	}
}
void InquirePoint(Point* p, int index) {
	// Point* p = A;
	cout << "InquirePoint()" << endl;
	for (int i = 0; i < index; i++) {
		p[i].Print();
	}
}