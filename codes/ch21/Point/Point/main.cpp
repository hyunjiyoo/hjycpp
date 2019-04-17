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
void MakePoint(Point* A, int* indexPtr, int size);
void UpdatePoint();
void InquirePoint();
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
			MakePoint(A, &index, SIZE);
			break;
		case UPDATE:
			UpdatePoint();
			break;
		case INQUIRE:
			InquirePoint();
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
	// 사용자한테 물어서 원하는 값 채우기 (채운값만 보여주기) index++ (index 다 채우면 더 이상 채울 수 없습니다..메세지)
	cout << "1. (Point 좌표 채우기)" << endl; 
	// 새 값을 받아서 좌표 갱신. index가 3이면 0,1,2 만 채워져있다는 것을 알려줌.
	cout << "2. (Point 좌표 갱신하기)" << endl;
	cout << "3. (전체 조회)" << endl;
	cout << "4. (프로그램 종료)" << endl;
}
void MakePoint(Point* A, int* indexPtr, int size)
{
	// 처음부터 순차적으로 채워가는 것.
	// index는 size보다 작거나 같아야 한다.
	// 인덱스 위치에 가서 Point의 멤버변수 값을 채운다.
	// index를 하나 증가한다.
	cout << "MakePoint() 호출" << endl;
}
void UpdatePoint()
{
	// 사용자가 원하는 위치를 물어본다.
	// 위치는 index보다 작거나 같다. (size가 아니라 index보다 작거나 같다)
	// 그 다음 Point의 멤버변수 값을 입력 받아서 갱신해준다.
	cout << "UpdatePoint() 호출" << endl;
}
void InquirePoint()
{
	// 처음부터 index 위치까지 좌표(x, y) 보여주기.
	cout << "InquirePoint() 호출" << endl;
}