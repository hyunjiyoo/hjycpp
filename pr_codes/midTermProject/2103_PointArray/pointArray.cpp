#include <iostream>
using namespace std;
class Point {
public:
	int x, y;
	Point();
	Point(int initX, int initY);
	Point(const Point& p);
	~Point();
	void Print();
	int getArea();
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
	cout << "(" << this->x << ", " << this->y << ")";
}
int Point::getArea() {
	return this->x * this->y;
}
int main() {
	cout << "1. ���� ��ü �迭 ���" << endl;
	Point A[3];
	cout << "2. ���� ��ü �迭 ���" << endl;
	Point* B = new Point[3];
	cout << "3. ��ü ������ �迭 ���" << endl;
	Point* C[3];

	// ����ڿ��� x y ���� ��� ���� ä��� (for�̿�)
	for (int i = 0; i < 3; i++) {
		C[i] = new Point; // C�� Ÿ���� (Point*)�̱⶧���� new Point[] �ƴ�
		cout << "x�� �Է�: "; cin >> C[i]->x;
		cout << "y�� �Է�: "; cin >> C[i]->y;
	}

	// ������ ���̱�
	for (int i = 0; i < 3; i++) {
		cout << i << "��° ����: " << endl;
		cout << C[i]->getArea() << endl;
		cout << (*(C + i))->getArea() << endl;
		cout << (*C[i]).getArea() << endl;
		cout << (**(C + i)).getArea() << endl;
	}

	cout << "4. clean up" << endl;

	delete[] B; B = NULL;

	for (int i = 0; i < 3; i++) {
		if (C[i] != NULL) {
			delete C[i]; C[i] = NULL;
		}
	}
	return 0;
}