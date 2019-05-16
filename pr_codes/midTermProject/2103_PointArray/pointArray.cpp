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
	cout << "인자 없는 생성자" << endl;
	this->x = 0;
	this->y = 0;
}
Point::Point(int initX, int initY) {
	cout << "인자 있는 생성자" << endl;
	this->x = initX;
	this->y = initY;
}
Point::Point(const Point& p) {
	cout << "복사 생성자" << endl;
	this->x = p.x;
	this->y = p.y;
}
Point::~Point() {
	cout << "소멸자" << endl;
}
void Point::Print() {
	cout << "(" << this->x << ", " << this->y << ")";
}
int Point::getArea() {
	return this->x * this->y;
}
int main() {
	cout << "1. 정적 객체 배열 방식" << endl;
	Point A[3];
	cout << "2. 동적 객체 배열 방식" << endl;
	Point* B = new Point[3];
	cout << "3. 객체 포인터 배열 방식" << endl;
	Point* C[3];

	// 사용자에게 x y 값을 물어서 값을 채우기 (for이용)
	for (int i = 0; i < 3; i++) {
		C[i] = new Point; // C의 타입이 (Point*)이기때문에 new Point[] 아님
		cout << "x값 입력: "; cin >> C[i]->x;
		cout << "y값 입력: "; cin >> C[i]->y;
	}

	// 면적을 보이기
	for (int i = 0; i < 3; i++) {
		cout << i << "번째 면적: " << endl;
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