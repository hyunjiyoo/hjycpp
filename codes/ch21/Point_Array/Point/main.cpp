#include <iostream>
using namespace std;
/* ADT 정의의 시작 */
class Point 
{
public:
	int x, y;

	Point();
	Point(int initX, int initY);
	Point(const Point& p);
	~Point();

	void Print();
	int getArea(); // x를 width, y를 height로 가정
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
void Point::Print() 
{
	cout << "(" << x << " , " << y << ")" << endl;
}
int Point::getArea() 
{
	return x * y;
}
/* ADT 정의의 끝 */

// 클라이언트 시작
int main() {
	cout << "1. 정적 객체 배열 방식" << endl;
	Point A[3]; // A는 자동으로 소멸자 호출 (정적 객체 배열이기 때문에)
	cout << "2. 동적 객체 배열 방식" << endl;
	Point *B = new Point[3];
	// 3번째 방식은 포인터만 만들어놓고 필요할때마다 메모리를 만들어놓고 쓰는 것.
	// 대신 배열이 아니기때문에 속도가 조금 느림.
	cout << "3. 객체 포인터 배열 방식" << endl; // 중요!
	Point *C[3];

	// 사용자에게 x y 값을 물어서 값을 채우기 (for루프 이용)
	for (int i = 0; i < 3; i++) {
		C[i] = new Point; // C의 타입이 (Point*)이기때문에 new Point[] 이 아니다!!
		cout << i << "번째 x, y 입력: ";
		cin >> C[i]->x >> C[i]->y; // (*(C + i))->x  |  (*C[i]).x  | (**(C + i)).x
	}
	// 면적을 보이기 (for루프 이용)
	for (int i = 0; i < 3; i++) {
		cout << i << "번째 면적: " << endl;
		cout << "첫번째 방법: " << C[i]->getArea() << endl;
		cout << "두번째 방법: " << (*(C + i))->getArea() << endl;
		cout << "세번째 방법: " << (*C[i]).getArea() << endl;
		cout << "네번째 방법: " << (**(C + i)).getArea() << endl;
	}

	cout << "4. clean up" << endl;

	// B는 객체배열을 delete
	delete[] B; B = NULL;

	// C는 객체를 delete
	// C의 경우 하나씩 다 delete 해줘야함.
	for (int i = 0; i < 3; i++) {
		// 안전하게 제거하기 위해 if문 활용.
		if (C[i] != NULL) {
			delete C[i]; C[i] = NULL;
		}
	}

	return 0;