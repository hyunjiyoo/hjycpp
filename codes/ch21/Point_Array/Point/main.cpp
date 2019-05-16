#include <iostream>
using namespace std;
/* ADT ������ ���� */
class Point 
{
public:
	int x, y;

	Point();
	Point(int initX, int initY);
	Point(const Point& p);
	~Point();

	void Print();
	int getArea(); // x�� width, y�� height�� ����
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
void Point::Print() 
{
	cout << "(" << x << " , " << y << ")" << endl;
}
int Point::getArea() 
{
	return x * y;
}
/* ADT ������ �� */

// Ŭ���̾�Ʈ ����
int main() {
	cout << "1. ���� ��ü �迭 ���" << endl;
	Point A[3]; // A�� �ڵ����� �Ҹ��� ȣ�� (���� ��ü �迭�̱� ������)
	cout << "2. ���� ��ü �迭 ���" << endl;
	Point *B = new Point[3];
	// 3��° ����� �����͸� �������� �ʿ��Ҷ����� �޸𸮸� �������� ���� ��.
	// ��� �迭�� �ƴϱ⶧���� �ӵ��� ���� ����.
	cout << "3. ��ü ������ �迭 ���" << endl; // �߿�!
	Point *C[3];

	// ����ڿ��� x y ���� ��� ���� ä��� (for���� �̿�)
	for (int i = 0; i < 3; i++) {
		C[i] = new Point; // C�� Ÿ���� (Point*)�̱⶧���� new Point[] �� �ƴϴ�!!
		cout << i << "��° x, y �Է�: ";
		cin >> C[i]->x >> C[i]->y; // (*(C + i))->x  |  (*C[i]).x  | (**(C + i)).x
	}
	// ������ ���̱� (for���� �̿�)
	for (int i = 0; i < 3; i++) {
		cout << i << "��° ����: " << endl;
		cout << "ù��° ���: " << C[i]->getArea() << endl;
		cout << "�ι�° ���: " << (*(C + i))->getArea() << endl;
		cout << "����° ���: " << (*C[i]).getArea() << endl;
		cout << "�׹�° ���: " << (**(C + i)).getArea() << endl;
	}

	cout << "4. clean up" << endl;

	// B�� ��ü�迭�� delete
	delete[] B; B = NULL;

	// C�� ��ü�� delete
	// C�� ��� �ϳ��� �� delete �������.
	for (int i = 0; i < 3; i++) {
		// �����ϰ� �����ϱ� ���� if�� Ȱ��.
		if (C[i] != NULL) {
			delete C[i]; C[i] = NULL;
		}
	}

	return 0;