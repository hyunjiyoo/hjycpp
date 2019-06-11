#include <iostream>
#include "Point.h"
using namespace std;

Point::Point() {
	cout << "���� ���� ������" << endl;
	this->x = 0;
	this->y = 0;
}
Point::Point(int initX, int initY) {
	cout << "���� �ִ� ������" << endl;
	this->x = initX;
	this->y = initY;
}
Point::Point(const Point& p) {
	cout << "���� ������" << endl;
	this->x = p.x;
	this->y = p.y;
}
Point::~Point() {
	cout << "�Ҹ���" << endl;
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