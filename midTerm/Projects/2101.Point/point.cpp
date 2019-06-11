#include <iostream>
using namespace std;
class Point
{
public:
	int x, y;
	// char c;
	// double d;

	/* 생성자 */
	Point();
	Point(int initX, int initY);
	Point(const Point& p);

	/* 소멸자 */
	~Point();

	void Print();
};

/* 생성자와 소멸자
   "this-> "는 "그 객체의"라는 의미
*/
/* 인자 없는 생성자 */
Point::Point() {
	cout << "인자 없는 생성자" << endl;
	this->x = 0;
	this->y = 0;
}
/* 인자 있는 생성자 */
Point::Point(int initX, int initY) {
	cout << "인자 있는 생성자" << endl;
	this->x = initX;
	this->y = initY;
}
/* 복사 생성자 */
// pt2의 값이 바뀌면 안되기때문에 const 키워드 붙여줌.
Point::Point(const Point& p) {
	cout << "복사 생성자" << endl;
	this->x = p.x;
	this->y = p.y;
}
/* 소멸자 */
Point::~Point() {
	cout << "소멸자" << endl;
}

void Point::Print()
{
	cout << "(" << x << " , " << y << ")" << endl;
}

// Point ADT를 사용하는 클라이언트의 시작 
// MAKE에 '1'을 주면 자동으로 2,3,4 들어감
enum { MAKE = 1, UPDATE, INQUIRE, EXIT };
void PrintMenu();
void MakePoint(Point* A, int& indexR, int size);
void UpdatePoint(Point* A, int index);
void InquirePoint(Point* A, int index);
int main() {

	// 1. Point 객체 만들어보기.
	Point pt1, pt2;
	pt1.x = 500; pt1.y = 5;
	pt1.Print(); pt2.Print();
	cout << "sizeof(Point): " << sizeof(Point) << endl; // char c; double d; 추가하면 총 17byte여야 하는데 메모리 간격?이 생겨서 24byte 나옴.
	cout << "sizeof(pt1): " << sizeof(pt1) << endl;
	cout << "sizeof(pt2): " << sizeof(pt2) << endl;
	cout << "&pt1: " << &pt1 << endl;
	cout << "&pt1.x: " << &pt1.x << endl;
	cout << "&pt1.y: " << &pt1.y << endl;
	cout << "&pt2: " << &pt2 << endl;

	// 2. 생성자와 소멸자
	Point pt1; pt1.Print(); // pt1.Point(); 생성자 실행
	Point pt2(3, 5); pt2.Print(); // pt2.Point(3, 5); 생성자 실행
	Point pt3(pt2); pt3.Print(); // pt3.Point(pt2); 생성자 실행

	// 3. Menu driven
	// Point ADT를 사용하는 클라이언트의 시작 
	const int SIZE = 10;
	int index = 0;
	Point A[SIZE]; // 객체가 10개 생성 (인자 없는 생성자가 SIZE만큼 호출)
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
// 3. Menu driven
void PrintMenu() {
	cout << "--------------- MENU ---------------" << endl;
	cout << "1. (Point 좌표 채우기)" << endl;
	cout << "2. (Point 좌표 갱신하기)" << endl;
	cout << "3. (전체 조회)" << endl;
	cout << "4. (프로그램 종료)" << endl;
}
void MakePoint(Point* A, int& indexR, int size)
{
	cout << "MakePoint() 호출" << endl;
	if (indexR >= size) {
		cout << "배열이 꽉 찼습니다." << endl;
		return;
	}
	cout << "x, y를 입력하세요.";
	cin >> A[indexR].x >> A[indexR].y;
	indexR++;
}
void UpdatePoint(Point* A, int index)
{
	cout << "UpdatePoint() 호출" << endl;
	while (true) {
		cout << "원하는 위치가 어디입니까?";
		int position; cin >> position;
		if (position < 0 || position >= index) {
			cout << "0부터" << index-1 << "사이의 값을 입력해주세요." << endl;
			continue;
		}
		cout << "원하는 값을 입력해주세요.";
		cin >> A[position].x >> A[position].y;
		return;
	}
}
void InquirePoint(Point* A, int index)
{
	cout << "InquirePoint() 호출" << endl;
	for (int i = 0; i < index; i++) 
		A[i].Print();
}