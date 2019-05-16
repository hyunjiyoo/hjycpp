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
	cout << "인자 없는 생성자" << endl;
	this->radius = 1;
}
Circle::Circle(int r) {
	cout << "인자 있는 생성자" << endl;
	this->radius = r;
}
Circle::Circle(const Circle& c) {
	cout << "복사 생성자" << endl;
	this->radius = c.radius;
}
Circle::~Circle() {
	cout << "소멸자" << endl;
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

	// 2. 정적 객체배열 생성자 호출 (스택메모리만 사용)
	Circle A[3]; // 인자없는 생성자 3개 호출
	Circle B2[3] = { Circle(10), Circle(A[0]), Circle(A[1]) }; // 인자있는 생성자 1개 + 복사생성자 2개
	// A의 1번째 요소 반지름 바꾸기 (3가지 방법)
	A[1].setRadius(10);
	(*(A + 1)).setRadius(20);
	(A + 1)->setRadius(30);
	Circle* p1 = A;
	cout << (p1 + 1)->getArea() << endl;

	// 3. 동적 배열 객체
	int num;
	cout << "몇개의 객체를 만들겠소? ";
	cin >> num;
	Circle* B = new Circle[num];

	// 사용자에게 radius 입력받기
	for (int i = 0; i < num; i++) {
		cout << i << "번째 반지름을 입력하세요: ";
		cin >> B[i].radius; // (*(B + i)).radius || (B + i)->radius
	}
	// 사용자에게 면적 보여주기
	Circle* p2 = B;
	for (int i = 0; i < num; i++) {
		cout << i << "번째 면적은 " << B[i].getArea() << "입니다." << endl;
		cout << "for()안의 B: " << B << endl;
		p2++;
	}
	cout << B->getArea() << " B: " << B << endl;
	delete[] B; B = NULL;

	// 4. 정적객체 포인터 배열
	Circle* C[3];
	C[2]->setRadius(5);
	(*(C + 2))->setRadius(5);
	(**(C + 2)).setRadius(5);
	(*C[2]).setRadius(5);

	return 0;
}