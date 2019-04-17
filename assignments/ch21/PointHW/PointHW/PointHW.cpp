#include <iostream>
using namespace std;
// 아래는 ADT(추상자료형) Point 정의, 코드를 수정하지 말 것
class Point
{
public:
	// 멤버 변수
	int x;
	int y;

	// 생성자
	Point();
	Point(int initX, int initY);
	Point(const Point &p);

	//소멸자
	~Point();

	// 일반적인 멤버 함수
	void Print();
};

// 인자 없는 생성자, Point 객체 선언시 자동으로 호출되는 멤버함수
Point::Point() {
	cout << "인자 없는 생성자" << endl;
	this->x = 0;		// x = 0;와 같다
	this->y = 0;		// y = 0;와 같다
}

// 인자 있는 생성자, Point 객체를 인수로 초기화할 때 호출되는 멤버함수
Point::Point(int initX, int initY) {
	cout << "인자 있는 생성자" << endl;
	this->x = initX;	// x = initX;와 같다
	this->y = initY;	// y = initY;와 같다
}

// 복사 생성자, Point 객체를 Point 객체의 레퍼런스 인수로 초기화 할 때 호출되는 멤버함수
Point::Point(const Point &p) {
	cout << "복사 생성자" << endl;
	this->x = p.x;		// x = p.x;와 같다
	this->y = p.y;		// y = p.y;와 같다
}

// 소멸자, 정적 객체는 선언한 곳의 함수가 종료될 때 자동으로 호출되는 멤버함수
Point::	~Point() {
	cout << "소멸자" << endl;
}

// Point의 멤버변수 x와 y의 값을 출력하는 멤버함수
void Point::Print() {
	cout << "(" << x << ", " << y << ")" << endl;
}
// 위는 ADT(추상자료형) Point 정의, 코드를 수정하지 말 것

// 아래부터 Point라는 ADT를 사용하는 클라이언트 시작...클라이언트 부분을 완성하는 것이 과제
// 함수의 원형 선언
void PrintMenu();
void MakePoint(Point* Arr, int& indexPtr, int size);
void UpdatePoint(Point* Arr, int& indexPtr);
void InquirePoint(Point* Arr, int& indexPtr);
// 상수 선언
enum {
	MAKE = 1,	//    MAKE라고 쓰면 1으로 인식한다
	UPDATE,		//  UPDATE라고 쓰면 2으로 인식한다
	INQUIRE,	// INQUIRE라고 쓰면 3으로 인식한다
	EXIT		//    EXIT라고 쓰면 4으로 인식한다
};
// main함수에서 Point 객체를 담는 정적 배열을 선언하고 인터페이스를 작성한다
int main() {
	int index = 0;			// index는 Point배열 Arr에서 Point 객체가 채워질 위치
	const int SIZE = 10;	// SIZE는 Arr의 크기
	Point Arr[SIZE];		// 인자 없는 생성자가 SIZE만큼 불려진다
	int choice;				// 사용자가 선택한 기능 번호를 저장할 변수
	while (true) {			// EXIT하지 않는다면 반복해서 실행한단
		PrintMenu();		// 선택 메뉴 출력하는 함수 호출
		cout << "선택:";
		cin >> choice;		// 선택하고 싶은 기능을 정수로 받는다
		switch (choice) {	// 선택한 기능을 실행한다
		case MAKE:
			MakePoint(Arr, index, SIZE);
			break;
		case UPDATE:
			UpdatePoint(Arr, index);
			break;
		case INQUIRE:
			InquirePoint(Arr, index);
			break;
		case EXIT:
			return 0;
		default:
			cout << "잘못된 선택" << endl;
			break;
		}
	}
	return 0;
}

// 선택 메뉴를 출력하는 함수
void PrintMenu() {
	cout << "---------------MENU----------------" << endl;
	cout << "1(Point 좌표 채우기)" << endl;
	cout << "2(Point 좌표 갱신하기)" << endl;
	cout << "3(전체 조회)" << endl;
	cout << "4(프로그램 종료)" << endl;
}

// index 위치에 있는 Point 배열의 객체에 접근해서 그 객체의 멤버 변수의 값을 채워주는 함수
void MakePoint(Point* Arr, int& indexPtr, int size) {
	cout << "MakePoint() 호출" << endl;
	if (indexPtr >= size) {
		cout << "Arr의 SIZE가 꽉 찼습니다." << endl << endl;
		return;
	}
	cout << "(x, y)를 입력하세요: ";
	cin >> Arr[indexPtr].x; cin >> Arr[indexPtr].y;
	indexPtr++;
}

// Point 배열에서 원하는 위치의 객체에 접근해서 그 멤버변수의 값을 갱신하는 함수
void UpdatePoint(Point* Arr, int& indexPtr) {
	cout << "UpdatePoint() 호출" << endl;
	while(1) {
		cout << "원하는 위치가 어디입니까: ";
		int i; cin >> i;
		if (i >= indexPtr + 1) {
			cout << "더 작은 수를 입력해주세요." << endl;
			continue;
		}
		cout << "원하는 값을 입력하세요: ";
		cin >> Arr[i-1].x >> Arr[i-1].y;
		Arr[i-1].Print();
		return;
	}
}

// Point 배열에서 채워진 모든 객체의 멤버변수 값을 출력하는 함수
void InquirePoint(Point* Arr, int& indexPtr) {
	cout << "InquirePoint() 호출" << endl;
	for (int i = 0; i < indexPtr; i++) {
		Arr[i].Print();
	}
}