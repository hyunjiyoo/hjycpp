#pragma once
// ������ .h ���Ͽ��� ������ �̸��� ������ �ɺ��� ������.
#ifndef POINT_H
#define POINT_H
class Point
{
private:
	int x, y;

public:
	Point();
	Point(int initX, int initY);
	Point(const Point& p);
	~Point();

	void Print();
	// ������
	void SetX(int v);
	void SetY(int v);
	int GetX();
	int GetY();
};
#endif