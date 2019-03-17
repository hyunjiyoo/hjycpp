#include <iostream>
// std 이름 공간에 선언된 모든 이름에 std:: 생략
using namespace std;

int main() {
	/*
	[ namespace ]
	- 이름(identifier) 충돌 발생하는 경우
		- 여러 명이 서로 나누어 프로젝트 개발하는 경우
		- 오픈소스 혹은 다른사람의 소스 컴파일하는 경우
	- 이름 충돌 해결!!
	- 개발자가 자신만의 이름 공간을 생성할 수 있도록 함
	- 이름 공간 안에 선언된 이름은 다른 이름공간과 별도 구분
	- 이름 공간 생성 및 사용

	namespace alpha {
	// 이 곳에 선언된 모든 이름은 alpha 이름 공간에 생성
	}
	*/

	cout << "너비를 입력하세요: ";
	int width;
	cin >> width; // 키보드에서 너비를 읽어 width 변수에 저장
	cout << "높이를 입력하세요: ";
	int height;
	cin >> height; // 키보드에서 높이를 읽어 height 변수에 저장
	int area = width * height;
	cout << "면적은 " << area << endl;

	/*
	[ cin ]
	- 표준 입력 장치인 키보드를 연결하는 C++ 입력 스트림 객체
	
	[ >> 연산자 ]
	- 스트림 추출 연산자 (stream extraction operator)
	- C++ 산술 시프트 연산자(>>)가 <iostream> 헤더 파일에 스트림 추출 연산자로 재정의됨.
	- 입력 스트림에서 값을 읽어 변수에 저장
	- 연속된 >> 연산자 사용하여 여러 값 입력 가능
		cin >> width >> height;
	
	[ cin  특징 ]
	- (Enter)키를 칠 때 변수에 값 전달
	- 입력 버퍼 내장
	- (Enter)키가 입력될 때까지 입력된 키를 입력 버퍼에 저장
	- 도중에 (Backspace)키를 입력하면 입력된 키 삭제
	- '>>'연산자는 (Enter)키 입력되면 비로소 cin의 입력 버퍼에서 키값 읽어 변수에 전달
	*/

	return 0;
}