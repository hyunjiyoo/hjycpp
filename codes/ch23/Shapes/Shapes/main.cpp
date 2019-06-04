#include <iostream>
using namespace std;
class Shape 
{
//private: Shape* next; // 링크드 리스트로 구현 해보기
protected:
	int x; int y;
public:
	Shape();
	Shape(int x, int y);
	virtual ~Shape();
	virtual void Draw();
};
Shape::Shape()
{
	this->x = 0; 
	this->y = 0;
}
Shape::Shape(int x, int y) 
{
	this->x = x;
	this->y = y;
}
Shape::~Shape() 
{
	cout << "Shape: 소멸자" << endl;
}
void Shape::Draw() 
{
	cout << "[Shape] x: " << this->x << " y: " << this->y << endl;
}
class Circle :public Shape
{
protected:
	double radius;
public:
	Circle();
	Circle(int x, int y, double r);
	virtual ~Circle();
	void Draw();
};
Circle::Circle()
	:Shape(0, 0)
{
	this->radius = 1;
}
Circle::Circle(int x, int y, double r) 
	:Shape(x, y)
{
	this->radius = r;
}
Circle::~Circle() 
{
	cout << "Circle: 소멸자" << endl;
}
void Circle::Draw() 
{
	cout << "[Circle] x: " << this->x << " y: " << this->y << " radius: " << this->radius << endl;
}
class Rectangle :public Shape
{
protected:
	int w; int h;
public:
	Rectangle();
	Rectangle(int x, int y, int w, int h);
	virtual ~Rectangle();
	void Draw();
};
Rectangle::Rectangle()
	:Shape(0, 0)
{
	this->w = 0;
	this->h = 0;
}
Rectangle::Rectangle(int x, int y, int w, int h) 
	:Shape(x, y)
{
	this->w = w;
	this->h = h;
}
Rectangle::~Rectangle() 
{
	cout << "Rectangle: 소멸자" << endl;
}
void Rectangle::Draw() 
{
	cout << "[Rectangle] x: " << this->x << " y: " << this->y << " width: " << this->w << " height: " << this->h << endl;
}
const int MAX = 100;
enum { ADD_CIRCLE = 1, ADD_RECT, DRAW_ALL, QUIT };
void showMenu() {
	cout << "1: Circle 추가" << endl;
	cout << "2: Rectangle 추가" << endl;
	cout << "3: 전체 그리기" << endl;
	cout << "4: 종료" << endl;
}
int main() {
	/*Shape* sp1 = new Rectangle(5, 10, 100, 200);
	sp1->Draw();
	delete sp1;*/
	
	Shape* C[MAX];
	int count = 0; // 링크드리스트로 구현할 수 있음
	int choice;
	int x, y, w, h;
	double r;
	while (true) {
		showMenu();
		cout << "입력: "; cin >> choice;
		switch (choice) {
		case ADD_CIRCLE:
			cout << "x 입력: "; cin >> x;
			cout << "y 입력: "; cin >> y;
			cout << "r 입력: "; cin >> r;
			C[count] = new Circle(x, y, r); // bp = dp; (업캐스팅)
			count++;
			break;
		case ADD_RECT:
			cout << "x 입력: "; cin >> x;
			cout << "y 입력: "; cin >> y;
			cout << "w 입력: "; cin >> w;
			cout << "h 입력: "; cin >> h;
			C[count] = new Rectangle(x, y, w, h); // bp = dp; (업캐스팅)
			count++;
			break;
		case DRAW_ALL:
			for (int i = 0; i < count; i++) {
				C[i]->Draw();
				/*(*(C + i))->Draw();
				(*C[i]).Draw();
				(**(C + i)).Draw();*/
			}
			break;
		case QUIT:
			for (int i = 0; i < count; i++) {
				if (C[i] != NULL) {
					delete C[i];
					C[i] = NULL;
				}
			}
			return 0;
		default:
			cout << "잘못된 숫자를 입력하셨습니다." << endl;
			break;
		}
	}

	return 0;
}