#include <iostream>
#include "Point.h"
using namespace std;

int main() {
	Point p1(50, 60);
	Point p2(8, 7);
	// private �̹Ƿ�, ���� �׼��� �Ұ�.
	// cout << "p1.x: " << p1.x << endl;
	cout << "p1.x: " << p1.GetX() << endl;
	// p1.x = 500; -> private �̶� �׼��� �ȵ�.
	p1.SetX(500);

	return 0;
}