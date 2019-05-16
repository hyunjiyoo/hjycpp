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
	this->x = 0;
	this->y = 0;
}
// ���� �ִ� ������, Point ��ü�� �μ��� �ʱ�ȭ�� �� ȣ��Ǵ� ����Լ�
Point::Point(int initX, int initY) {
	cout << "���� �ִ� ������" << endl;
	this->x = initX;
	this->y = initY;
}
// ���� ������, Point ��ü�� Point ��ü�� ���۷��� �μ��� �ʱ�ȭ �� �� ȣ��Ǵ� ����Լ�
Point::Point(const Point &p) {
	cout << "���� ������" << endl;
	this->x = p.x;
	this->y = p.y;
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
void MakePoint(Point* Arr, int* indexPtr, int size);
void UpdatePoint(Point* Arr, int index);
void InquirePoint(Point* Arr, int index);
// ��� ����
enum {
	MAKE = 1,
	UPDATE,
	INQUIRE,
	EXIT
};
// main�Լ����� Point ��ü�� ��� ���� �迭�� �����ϰ� �������̽��� �ۼ��Ѵ�
int main() {
	int index = 0;
	const int SIZE = 10;
	Point Arr[SIZE];
	int choice;
	while (true) {
		PrintMenu();
		cout << "����:";
		cin >> choice;
		switch (choice) {
		case MAKE:
			MakePoint(Arr, &index, SIZE);
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
void MakePoint(Point* Arr, int* indexPtr, int size) {
	cout << "MakePoint() ȣ��" << endl;
	if (*indexPtr >= size) {
		cout << "Arr�� ���� á���ϴ�" << endl;
		return;
	}
	else {
		int inputX, inputY;
		cout << "x �� �Է�:";
		cin >> inputX;
		cout << "y �� �Է�:";
		cin >> inputY;

		Arr[*indexPtr].x = inputX;
		Arr[*indexPtr].y = inputY;
		++*indexPtr;
	}
}

// Point �迭���� ���ϴ� ��ġ�� ��ü�� �����ؼ� �� ��������� ���� �����ϴ� �Լ�
void UpdatePoint(Point* Arr, int index) {
	cout << "UpdatePoint() ȣ��" << endl;
	int loc;
	cout << "��ġ �Է�:";
	cin >> loc;

	if (0 <= loc && loc < index) {
		int inputX, inputY;
		cout << "x �� �Է�:";
		cin >> inputX;
		cout << "y �� �Է�:";
		cin >> inputY;

		Arr[loc].x = inputX;
		Arr[loc].y = inputY;
	}
	else {
		cout << "�Է��� ��ġ�� ��ü�� ��������� �ʾҽ��ϴ�" << endl;
		cout << "(���� �ε��� ��ġ: " << index << ")" << endl;
		return;
	}
}

// Point �迭���� ä���� ��� ��ü�� ������� ���� ����ϴ� �Լ�
void InquirePoint(Point* Arr, int index) {
	cout << "InquirePoint() ȣ��" << endl;
	for (int i = 0; i < index; i++) {
		cout << i << ": ";
		Arr[i].Print();
	}
}