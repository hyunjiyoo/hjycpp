#include <iostream>
using namespace std;

/* ADT ������ ���� */
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
	this->radius = 1; // (*this).radius = 1; �� ����

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
/* ADT ������ �� */

// Ŭ���̾�Ʈ�� ����
int main() {
	// 1. ȭ��ǥ ������
	/*Circle donut;
	Circle pizza(30);
	Circle waffle(pizza);
	Circle* p = &donut;

	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
	p = &waffle;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;*/

	// 2. ���� ��ü�迭 ������ ȣ�� (���ø޸𸮸� ���)
	//Circle A[3]; // ���ھ��� ������ 3�� ȣ��
	//Circle B2[3] = { Circle(10), Circle(A[0]), Circle(A[1]) }; // �����ִ� ������ 1�� + ��������� 2��
	//// A�� 1��° ����� ������ �ٲٱ� (3���� ���)
	//(A[1]).setRadius(15);
	//(*(A + 1)).setRadius(25);
	//(A + 1)->setRadius(35);
	//Circle* p = A;
	//cout << (p + 1)->getArea() << endl;

	// 3. ���� �迭 ��ü 
	//int num;
	//cout << "�� ���� ��ü�� ����ڼ�? ";
	//cin >> num;
	//Circle *B = new Circle[num];
	//
	/* 3���� ��� */
	////B[1].radius = 5;
	////(*(B + 1)).radius = 5;
	////(B + 1)->radius = 5;
	//
	//// ����ڿ��� radius �Է¹ޱ�
	//for (int i = 0; i < num; i++) {
	//	cout << i << "��° �Է�: ";
	//	cin >> B[i].radius; // (B + i)->radius
	//}
	//// ����ڿ��� ���� �����ֱ�
	//Circle* p = B;
	//for (int i = 0; i < num; i++) {
	//	cout << i << "��° ����: " << p->getArea() << endl;
	//	p++;
	//}
	//
	//delete[] B; B = NULL;

	// 4. ���� ��ü ������ �迭
	// 3��° ������� �ι�° ����� �������� 5�� ä���ּ���.
	Circle* C[3];
	
	C[2]->radius = 5; // C[2]�� ������Ÿ���� (Circle*)
	(*(C + 2))->radius = 5; // *(C + 2)�� ������Ÿ���� (Circle*)
	(*C[2]).radius = 5; // *C[2]�� ������Ÿ���� (Circle)
	(**(C + 2)).radius = 5; // *(*(C + 2))�� ������Ÿ���� (Circle)

	// return 0 �϶� �Ҹ��� ȣ�� (�Լ��� ������ ����� �� �Ҹ��� ȣ��)
	return 0;
}