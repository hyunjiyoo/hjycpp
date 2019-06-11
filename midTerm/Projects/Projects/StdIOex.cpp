#include <iostream>
using namespace std;
double area(int r); // 함수의 선언(declaration)(원형)
int main() {
	// 1.출력 연습
	int n = 3; char c = '#';
	cout << c << 5.5 << '-' << endl;
	// boolalpha : 'true'를 1로 나타내지않고 'true' 그대로 출력.
	cout << boolalpha << true << "hello world" << endl;
	cout << "n + 5 = " << n + 5 << endl;
	// area(n) : 함수의 call
	cout << "면적은 " << area(n) << endl;
	cout << "stdio ex" << endl;

	// 2.입력 연습
	cout << "너비 : ";
	int width;
	cin >> width;
	cout << "높이 : ";
	int height;
	cin >> height;
	cout << "면적 : " << width * height << endl;

	// 3.문자열 입력 연습
	// 이름: '알파 고'라고 입력하면 '알파'만 나옴. (delimit때문에 '알파'에서 잘림)
	cout << "이름입력 : ";
	char gname[100];
	cin >> gname;
	cout << "당신의 이름은 " << gname << " 입니다." << endl;

	// 4.cin.getline() 함수 연습
	cout << "이름입력 : ";
	char name[10]; // 0123456789012 입력시, 012345678 까지 출력 (size 10 때문에 index 9 에 먼저 도달)
	cin.getline(name, 10, '\n');
	cout << "당신의 이름은 " << name << " 입니다." << endl;

	return 0;
}
// 함수의 정의(definition)
double area(int r) {
	return 3.14*r*r;
}