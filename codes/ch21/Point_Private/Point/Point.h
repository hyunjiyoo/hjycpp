#pragma once
// 무조건 .h 파일에는 파일의 이름과 동일한 심볼을 만들어라.
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
	// 접근자
	void SetX(int v);
	void SetY(int v);
	int GetX();
	int GetY();
};
#endif