#include <iostream>
using namespace std;
class Point 
{
public:
	int x, y;
	// char c;
	// double d;

	/* ������ */
	Point();
	Point(int initX, int initY);
	Point(const Point& p);

	/* �Ҹ��� */
	~Point();

	void Print();
};

/* �����ڿ� �Ҹ��� 
   "this-> "�� "�� ��ü��"��� �ǹ�
*/
/* ���� ���� ������ */
Point::Point() {
	cout << "���� ���� ������" << endl;
	this->x = 0;
	this->y = 0;
}
/* ���� �ִ� ������ */
Point::Point(int initX, int initY) {
	cout << "���� �ִ� ������" << endl;
	this->x = initX;
	this->y = initY;
}
/* ���� ������ */
// pt2�� ���� �ٲ�� �ȵǱ⶧���� const Ű���� �ٿ���.
Point::Point(const Point& p) {
	cout << "���� ������" << endl;
	this->x = p.x;
	this->y = p.y;
}
/* �Ҹ��� */
Point::~Point() {
	cout << "�Ҹ���" << endl;
}

void Point::Print() 
{
	cout << "(" << x << " , " << y << ")" << endl;
}

// Point ADT�� ����ϴ� Ŭ���̾�Ʈ�� ���� 
// MAKE�� '1'�� �ָ� �ڵ����� 2,3,4 ��
enum { MAKE = 1, UPDATE, INQUIRE, EXIT };
void PrintMenu();
void MakePoint(Point* A, int* indexPtr, int size);
void UpdatePoint();
void InquirePoint();
int main() {

	// 1. Point ��ü ������.
	Point pt1, pt2;
	pt1.x = 500; pt1.y = 5;
	pt1.Print(); pt2.Print();
	cout << "sizeof(Point): " << sizeof(Point) << endl; // char c; double d; �߰��ϸ� �� 17byte���� �ϴµ� �޸� ����?�� ���ܼ� 24byte ����.
	cout << "sizeof(pt1): " << sizeof(pt1) << endl;
	cout << "sizeof(pt2): " << sizeof(pt2) << endl;
	cout << "&pt1: " << &pt1 << endl;
	cout << "&pt1.x: " << &pt1.x << endl;
	cout << "&pt1.y: " << &pt1.y << endl;
	cout << "&pt2: " << &pt2 << endl;

	// 2. �����ڿ� �Ҹ���
	Point pt1; pt1.Print(); // pt1.Point(); ������ ����
	Point pt2(3, 5); pt2.Print(); // pt2.Point(3, 5); ������ ����
	Point pt3(pt2); pt3.Print(); // pt3.Point(pt2); ������ ����

	// 3. Menu driven
	// Point ADT�� ����ϴ� Ŭ���̾�Ʈ�� ���� 
	const int SIZE = 10;
	int index = 0;
	Point A[SIZE]; // ��ü�� 10�� ���� (���� ���� �����ڰ� SIZE��ŭ ȣ��)
	int choice;
	while (true) 
	{
		PrintMenu();
		cout << "����: ";
		cin >> choice;
		switch (choice)
		{
		case MAKE:
			MakePoint(A, &index, SIZE);
			break;
		case UPDATE:
			UpdatePoint();
			break;
		case INQUIRE:
			InquirePoint();
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
// 3. Menu driven
void PrintMenu() {
	cout << "--------------- MENU ---------------" << endl;
	// ��������� ��� ���ϴ� �� ä��� (ä��� �����ֱ�) index++ (index �� ä��� �� �̻� ä�� �� �����ϴ�..�޼���)
	cout << "1. (Point ��ǥ ä���)" << endl; 
	// �� ���� �޾Ƽ� ��ǥ ����. index�� 3�̸� 0,1,2 �� ä�����ִٴ� ���� �˷���.
	cout << "2. (Point ��ǥ �����ϱ�)" << endl;
	cout << "3. (��ü ��ȸ)" << endl;
	cout << "4. (���α׷� ����)" << endl;
}
void MakePoint(Point* A, int* indexPtr, int size)
{
	// ó������ ���������� ä������ ��.
	// index�� size���� �۰ų� ���ƾ� �Ѵ�.
	// �ε��� ��ġ�� ���� Point�� ������� ���� ä���.
	// index�� �ϳ� �����Ѵ�.
	cout << "MakePoint() ȣ��" << endl;
}
void UpdatePoint()
{
	// ����ڰ� ���ϴ� ��ġ�� �����.
	// ��ġ�� index���� �۰ų� ����. (size�� �ƴ϶� index���� �۰ų� ����)
	// �� ���� Point�� ������� ���� �Է� �޾Ƽ� �������ش�.
	cout << "UpdatePoint() ȣ��" << endl;
}
void InquirePoint()
{
	// ó������ index ��ġ���� ��ǥ(x, y) �����ֱ�.
	cout << "InquirePoint() ȣ��" << endl;
}