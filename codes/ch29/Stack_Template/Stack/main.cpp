#include <iostream>
#include "StackTemp.h"
#include "MyException.h"
using namespace std;
class Point
{
public:
	int x; int y;
	Point() { this->x = 0; this->y = 0; }
	Point(int x, int y) { this->x = x; this->y = y; }
	void Show() { cout << this->x << ", " << this->y << endl; }
};

int main() {

	// Stack 에 char를 집어넣어보자.
	Stack<char> S1(7);
	S1.push('a');
	S1.push('b');
	S1.push('c');
	for (int i = 0; i < 3; i++) {
		cout << S1.pop() << endl;
	}

	// Stack 에 int를 집어넣어보자.
	Stack<int> S2(5);
	S2.push(10);
	S2.push(20);
	S2.push(30);
	for (int i = 0; i < 3; i++) {
		cout << S2.pop() << endl;
	}

	// Stack 에 Point를 집어넣어보자.
	Stack<Point> S3(3);

	/* StackFullException */
	try
	{
		S3.push(Point(1, 1));
		S3.push(Point(2, 3));
		S3.push(Point(-5, 10));
		S3.push(Point(100, 2000)); // memory 침범!!
	}
	catch (MyException* ep)
	{
		ep->Report();
	}

	/* StackEmptyException */
	try
	{
		Point p;
		for (int i = 0; i < 4; i++) {
			p = S3.pop();
			p.Show();
		}
	}
	catch (MyException* ep)
	{
		ep->Report();
	}

	return 0;
}