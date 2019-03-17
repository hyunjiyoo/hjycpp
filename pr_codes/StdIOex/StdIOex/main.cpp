#include <iostream>

double area(int r); // 함수의 원형 선언 (declaration)
int main() {
	/*
	[ cout 객체 ]
	- 스크린 출력장치에 연결된 표준 C++ 출력 스트림 객체
	- <iostream> 헤더파일에 선언
	- std 이름 공간에 선언: std::cout으로 사용
	
	[ << 연산자 ]
	- 스트림 삽입 연산자 (stream insertion operator)
	- C++ 기본 산술 시프트 연산자(<<)가 '스트립 삽입 연산자'로 재정의됨
	- ostream 클래스에 구현됨
	- 오른쪽 피연산자를 왼쪽 스트림 객체(std::cout)에 삽입
	- cout 객체에 연결된 화면에 출력
	- 여러개의 << 연산자로 여러값 출력
	*/

	// 문자열 및 기본 타입의 데이터 출력
	int n = 3; char c = '#';
	std::cout << "기본타입 데이터 출력: " << c << 5.5 << '-' << n << "hello" << std::endl;
	
	// std::boolalpha 사용
	std::cout << "boolalpha 사용X: " << true << std::endl; // 1
	std::cout << "boolalpha 사용O: " << std::boolalpha << true << std::endl; // true

	// 다음줄로 넘어가기 '\n'와 std::endl 사용
	std::cout << '\n' << std::endl;

	// 연산식뿐 아니라 함수 호출도 가능
	std::cout << "연산식 출력: " << "n + 5 = " << n + 5;
	std::cout << "함수의 리턴값 출력: " << area(n); // 함수 area(3)의 리턴값 출력
	
	return 0;
}

// 함수의 정의 (definition)
double area(int r) {
	return 3.14*r*r;
}