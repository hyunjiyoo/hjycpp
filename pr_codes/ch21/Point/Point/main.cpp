#include <iostream>
using namespace std;
class Point 
{
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
void MakePoint(Point* Arr, int& indexPtr, int size);
void UpdatePoint(Point* Arr, int& indexPtr, int size);
void InquirePoint(Point* Arr, int& indexPtr);
int main() {
	/* 1.Point객체 만들어보기. */
	Point pt1, pt2;
	pt1.x = 500; pt1.y = 5;
	pt1.Print(); pt2.Print();
	cout << "sizeof(Point): " << sizeof(Point) << endl;
	cout << "sizeof(pt1): " << sizeof(pt1) << endl;
	cout << "sizeof(pt2): " << sizeof(pt2) << endl;
	cout << "&pt1: " << &pt1 << endl;
	cout << "&pt1.x: " << &pt1.x << endl;
	cout << "&pt1.y: " << &pt1.y << endl;
	cout << "&pt2: " << &pt2 << endl;

	/* 2.생성자와 소멸자 */
	// Point ADT를 사용하는 클라이언트의 시작
	const int SIZE = 5;
	int index = 0;
	Point Arr[SIZE]; // 객체 10개 생성(인자없는 생성자가 SIZE만큼 호출)
	int choice;
	while (true)
	{
		PrintMenu();
		cout << "선택: ";
		cin >> choice;
		switch (choice)
		{
		case MAKE:
			MakePoint(Arr, index, SIZE);
			break;
		case UPDATE:
			UpdatePoint(Arr, index, SIZE);
			break;
		case INQUIRE:
			InquirePoint(Arr, index);
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
	cout << "----------------MENU-----------------" << endl;
	cout << "1.(Point 좌표 채우기)" << endl;
	cout << "2.(Point 좌표 갱신하기)" << endl;
	cout << "3.(전체 조회)" << endl;
	cout << "4.(프로그램 종료)" << endl;
}
void MakePoint(Point* Arr, int& indexPtr, int size) {
	cout << "MakePoint() 호출" << endl;
	while (true) {
		if (indexPtr >= size) {
			cout << "배열의 SIZE가 꽉 찼습니다." << endl;
			break;
		}
		cout << "좌표를 입력해주세요: ";
		cin >> Arr[indexPtr].x >> Arr[indexPtr].y;
		Arr[indexPtr].Print();
		indexPtr++;
		return;
	}
}
void UpdatePoint(Point* Arr, int& indexPtr, int size) {
	cout << "UpdatePoint() 호출" << endl;
	while (true) {
		cout << "수정할 좌표번호를 입력해주세요: ";
		int num; cin >> num;
		if (num > indexPtr) {
			cout << "더 작은 번호를 입력해주세요" << endl;
			return;
		}
		cout << "수정할 값을 입력해주세요: ";
		cin >> Arr[num-1].x >> Arr[num-1].y;
		return;
	}
}
void InquirePoint(Point* Arr, int& indexPtr) {
	cout << "InquirePoint() 호출" << endl;
	for (int i = 0; i < indexPtr; i++)
		Arr[i].Print();
}