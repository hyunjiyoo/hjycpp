#include <iostream>
#include "Point.h"
using namespace std;

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
void Point::SetX(int v) {
	this->x = v;
}
void Point::SetY(int v) {
	this->y = v;
}
int Point::GetX() {
	return this->x;
}
int Point::GetY() {
	return this->y;
}