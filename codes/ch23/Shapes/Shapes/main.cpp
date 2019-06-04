#include <iostream>
using namespace std;
class Shape 
{
//private: Shape* next; // ��ũ�� ����Ʈ�� ���� �غ���
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
	cout << "Shape: �Ҹ���" << endl;
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
	cout << "Circle: �Ҹ���" << endl;
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
	cout << "Rectangle: �Ҹ���" << endl;
}
void Rectangle::Draw() 
{
	cout << "[Rectangle] x: " << this->x << " y: " << this->y << " width: " << this->w << " height: " << this->h << endl;
}
const int MAX = 100;
enum { ADD_CIRCLE = 1, ADD_RECT, DRAW_ALL, QUIT };
void showMenu() {
	cout << "1: Circle �߰�" << endl;
	cout << "2: Rectangle �߰�" << endl;
	cout << "3: ��ü �׸���" << endl;
	cout << "4: ����" << endl;
}
int main() {
	/*Shape* sp1 = new Rectangle(5, 10, 100, 200);
	sp1->Draw();
	delete sp1;*/
	
	Shape* C[MAX];
	int count = 0; // ��ũ�帮��Ʈ�� ������ �� ����
	int choice;
	int x, y, w, h;
	double r;
	while (true) {
		showMenu();
		cout << "�Է�: "; cin >> choice;
		switch (choice) {
		case ADD_CIRCLE:
			cout << "x �Է�: "; cin >> x;
			cout << "y �Է�: "; cin >> y;
			cout << "r �Է�: "; cin >> r;
			C[count] = new Circle(x, y, r); // bp = dp; (��ĳ����)
			count++;
			break;
		case ADD_RECT:
			cout << "x �Է�: "; cin >> x;
			cout << "y �Է�: "; cin >> y;
			cout << "w �Է�: "; cin >> w;
			cout << "h �Է�: "; cin >> h;
			C[count] = new Rectangle(x, y, w, h); // bp = dp; (��ĳ����)
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
			cout << "�߸��� ���ڸ� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}

	return 0;
}