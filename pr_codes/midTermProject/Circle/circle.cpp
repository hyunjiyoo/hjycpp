#include <iostream>
using namespace std;
class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	Circle(const Circle& c);
	~Circle();
	double getArea();
	void setRadius(int r);
};
Circle::Circle() {
	cout << "���� ���� ������" << endl;
	this->radius = 1;
}
Circle::Circle(int r) {
	cout << "���� �ִ� ������" << endl;
	this->radius = r;
}
Circle::Circle(const Circle& c) {
	cout << "���� ������" << endl;
	this->radius = c.radius;
}
Circle::~Circle() {
	cout << "�Ҹ���" << endl;
}
double Circle::getArea() {
	return this->radius * this->radius * 3.14;
}
void Circle::setRadius(int r) {
	this->radius = r;
}
int main() {
	Circle donut;
	Circle pizza(30);
	Circle waffle(pizza);

	Circle* p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &waffle;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	// 2. ���� ��ü�迭 ������ ȣ�� (���ø޸𸮸� ���)
	Circle A[3]; // ���ھ��� ������ 3�� ȣ��
	Circle B2[3] = { Circle(10), Circle(A[0]), Circle(A[1]) }; // �����ִ� ������ 1�� + ��������� 2��
	// A�� 1��° ��� ������ �ٲٱ� (3���� ���)
	A[1].setRadius(10);
	(*(A + 1)).setRadius(20);
	(A + 1)->setRadius(30);
	Circle* p1 = A;
	cout << (p1 + 1)->getArea() << endl;

	// 3. ���� �迭 ��ü
	int num;
	cout << "��� ��ü�� ����ڼ�? ";
	cin >> num;
	Circle* B = new Circle[num];

	// ����ڿ��� radius �Է¹ޱ�
	for (int i = 0; i < num; i++) {
		cout << i << "��° �������� �Է��ϼ���: ";
		cin >> B[i].radius; // (*(B + i)).radius || (B + i)->radius
	}
	// ����ڿ��� ���� �����ֱ�
	Circle* p2 = B;
	for (int i = 0; i < num; i++) {
		cout << i << "��° ������ " << B[i].getArea() << "�Դϴ�." << endl;
		cout << "for()���� B: " << B << endl;
		p2++;
	}
	cout << B->getArea() << " B: " << B << endl;
	delete[] B; B = NULL;

	// 4. ������ü ������ �迭
	Circle* C[3];
	C[2]->setRadius(5);
	(*(C + 2))->setRadius(5);
	(**(C + 2)).setRadius(5);
	(*C[2]).setRadius(5);

	return 0;
}