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
	cout << "(" << x << ", " << y << ")" << endl;
}
enum { MAKE = 1, UPDATE, INQUIRE, EXIT };
void PrintMenu();
void MakePoint(Point* p, int& index, int size);
void UpdatePoint(Point* p, int index);
void InquirePoint(Point* p, int index);
int main() {
	// 1.Point 객체 만들어보기
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

	// 2. 생성자와 소멸자
	Point ppt1; ppt1.Print();
	Point ppt2(3, 5); ppt2.Print();
	Point ppt3(ppt2); ppt3.Print();
	
	// 3. Menu driven
	// Point ADT를 사용하는 클라이언트의 시작
	const int SIZE = 3;
	int index = 0;
	Point A[SIZE];
	int choice;
	while (true)
	{
		PrintMenu();
		cout << "선택: ";
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
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}
	return 0;
}
void PrintMenu() {
	cout << "---------MENU----------" << endl;
	cout << "1.(Point 좌표 채우기)" << endl;
	cout << "2.(Point 좌표 갱신하기)" << endl;
	cout << "3.(전체 조회)" << endl;
	cout << "4.(프로그램 종료)" << endl;
}
void MakePoint(Point* p, int& index, int size) {
	// Point* p = A;
	if (index >= size) {
		cout << "더이상 좌표를 입력할 수 없습니다." << endl;
		return;
	}
	cout << "MakePoint()" << endl;
	cout << "x좌표 입력: ";
	cin >> p[index].x;
	cout << "y좌표 입력: ";
	cin >> p[index].y;
	index++;
}
void UpdatePoint(Point* p, int index) {
	cout << "UpdatePoint()" << endl;
	while (true) {
		cout << "위치를 선택하세요: ";
		int num; cin >> num;
		if (index <= num || num < 0) {
			cout << "0부터 " << index - 1 << "사이의 값을 입력해주세요" << endl;
			continue;
		}
		cout << "변경할 x값 입력: ";
		cin >> p[num].x;
		cout << "변경할 y값 입력: ";
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