#include <iostream>
using namespace std;
// �Ʒ��� ADT(�߻��ڷ���) Point ����, �ڵ带 �������� �� ��
class Point
{
public:
	// ��� ����
	int x;
	int y;

	// ������
	Point();
	Point(int initX, int initY);
	Point(const Point &p);

	//�Ҹ���
	~Point();

	// �Ϲ����� ��� �Լ�
	void Print();
};

// ���� ���� ������, Point ��ü ����� �ڵ����� ȣ��Ǵ� ����Լ�
Point::Point() {
	cout << "���� ���� ������" << endl;
	this->x = 0;		// x = 0;�� ����
	this->y = 0;		// y = 0;�� ����
}

// ���� �ִ� ������, Point ��ü�� �μ��� �ʱ�ȭ�� �� ȣ��Ǵ� ����Լ�
Point::Point(int initX, int initY) {
	cout << "���� �ִ� ������" << endl;
	this->x = initX;	// x = initX;�� ����
	this->y = initY;	// y = initY;�� ����
}

// ���� ������, Point ��ü�� Point ��ü�� ���۷��� �μ��� �ʱ�ȭ �� �� ȣ��Ǵ� ����Լ�
Point::Point(const Point &p) {
	cout << "���� ������" << endl;
	this->x = p.x;		// x = p.x;�� ����
	this->y = p.y;		// y = p.y;�� ����
}

// �Ҹ���, ���� ��ü�� ������ ���� �Լ��� ����� �� �ڵ����� ȣ��Ǵ� ����Լ�
Point::	~Point() {
	cout << "�Ҹ���" << endl;
}

// Point�� ������� x�� y�� ���� ����ϴ� ����Լ�
void Point::Print() {
	cout << "(" << x << ", " << y << ")" << endl;
}
// ���� ADT(�߻��ڷ���) Point ����, �ڵ带 �������� �� ��

// �Ʒ����� Point��� ADT�� ����ϴ� Ŭ���̾�Ʈ ����...Ŭ���̾�Ʈ �κ��� �ϼ��ϴ� ���� ����
// �Լ��� ���� ����
void PrintMenu();
void MakePoint(Point* Arr, int& indexPtr, int size);
void UpdatePoint(Point* Arr, int& indexPtr);
void InquirePoint(Point* Arr, int& indexPtr);
// ��� ����
enum {
	MAKE = 1,	//    MAKE��� ���� 1���� �ν��Ѵ�
	UPDATE,		//  UPDATE��� ���� 2���� �ν��Ѵ�
	INQUIRE,	// INQUIRE��� ���� 3���� �ν��Ѵ�
	EXIT		//    EXIT��� ���� 4���� �ν��Ѵ�
};
// main�Լ����� Point ��ü�� ��� ���� �迭�� �����ϰ� �������̽��� �ۼ��Ѵ�
int main() {
	int index = 0;			// index�� Point�迭 Arr���� Point ��ü�� ä���� ��ġ
	const int SIZE = 10;	// SIZE�� Arr�� ũ��
	Point Arr[SIZE];		// ���� ���� �����ڰ� SIZE��ŭ �ҷ�����
	int choice;				// ����ڰ� ������ ��� ��ȣ�� ������ ����
	while (true) {			// EXIT���� �ʴ´ٸ� �ݺ��ؼ� �����Ѵ�
		PrintMenu();		// ���� �޴� ����ϴ� �Լ� ȣ��
		cout << "����:";
		cin >> choice;		// �����ϰ� ���� ����� ������ �޴´�
		switch (choice) {	// ������ ����� �����Ѵ�
		case MAKE:
			MakePoint(Arr, index, SIZE);
			break;
		case UPDATE:
			UpdatePoint(Arr, index);
			break;
		case INQUIRE:
			InquirePoint(Arr, index);
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� ����" << endl;
			break;
		}
	}
	return 0;
}

// ���� �޴��� ����ϴ� �Լ�
void PrintMenu() {
	cout << "---------------MENU----------------" << endl;
	cout << "1(Point ��ǥ ä���)" << endl;
	cout << "2(Point ��ǥ �����ϱ�)" << endl;
	cout << "3(��ü ��ȸ)" << endl;
	cout << "4(���α׷� ����)" << endl;
}

// index ��ġ�� �ִ� Point �迭�� ��ü�� �����ؼ� �� ��ü�� ��� ������ ���� ä���ִ� �Լ�
void MakePoint(Point* Arr, int& indexPtr, int size) {
	cout << "MakePoint() ȣ��" << endl;
	if (indexPtr >= size) {
		cout << "Arr�� SIZE�� �� á���ϴ�." << endl << endl;
		return;
	}
	cout << "(x, y)�� �Է��ϼ���: ";
	cin >> Arr[indexPtr].x; cin >> Arr[indexPtr].y;
	indexPtr++;
}

// Point �迭���� ���ϴ� ��ġ�� ��ü�� �����ؼ� �� ��������� ���� �����ϴ� �Լ�
void UpdatePoint(Point* Arr, int& indexPtr) {
	cout << "UpdatePoint() ȣ��" << endl;
	while(1) {
		cout << "���ϴ� ��ġ�� ����Դϱ�: ";
		int i; cin >> i;
		if (i >= indexPtr + 1) {
			cout << "�� ���� ���� �Է����ּ���." << endl;
			continue;
		}
		cout << "���ϴ� ���� �Է��ϼ���: ";
		cin >> Arr[i-1].x >> Arr[i-1].y;
		Arr[i-1].Print();
		return;
	}
}

// Point �迭���� ä���� ��� ��ü�� ������� ���� ����ϴ� �Լ�
void InquirePoint(Point* Arr, int& indexPtr) {
	cout << "InquirePoint() ȣ��" << endl;
	for (int i = 0; i < indexPtr; i++) {
		Arr[i].Print();
	}
}