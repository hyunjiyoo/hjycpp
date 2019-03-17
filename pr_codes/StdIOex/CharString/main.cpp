#include <iostream>
using namespace std;
int main() {
	/*
	[ C++ 문자열 ]
	- char name1[6] =  { 'G', 'r', 'a', 'c', 'e', '\0' }; : 문자열 "Grace"
	- char name2[5] =  { 'G', 'r', 'a', 'c', 'e' }; : 단순 문자 배열
	- strcmp() : 문자열 비교
	- strlen() : 문자열 길이
	- strcpy() : 문자열 복사
	*/

	char test[6]; // 5개의 문자를 저장할 수 있는 char 배열
	cin >> test; // 키보드에서 문자열 읽어 name 배열에 저장

	// cin을 이용한 문자열 입력
	cout << "이름을 입력하세요: ";
	char name[11]; // 한글은 5개 글자, 영문은 10개까지 저장!!
	cin >> name; // 키보드로부터 문자열 읽는다.
	cout << "이름은 " << name << "입니다." << endl;

	// cin.getline() 함수
	cout << "cin.getline()으로 이름 입력: ";
	char getName[11];
	cin.getline(getName, 11, '\n');
	cout << "당신의 이름은 " << getName << "입니다." << endl;
	
	return 0;
}