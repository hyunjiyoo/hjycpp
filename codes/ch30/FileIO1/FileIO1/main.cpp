#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout;
	fout.open("foo.txt"); // default는 overwrite(=> trunc)
	// 파일을 못 열었을 때 (파일이 없는 경우) error 메세지 출력.
	if (!fout) {
		cout << "file을 열 수 없습니다." << endl;
		return 0;
	}
	fout << "이것은 우리가 만드는 첫번째 파일이다." << endl;
	fout << "5월 28일은 즐거운 mid3rd 보는 날~" << endl;
	fout << "Stay hungry! Stay foolish!!" << endl;

	fout.close();
	cout << "file이 다 만들어졌으니 열어서 내용물을 display 하시오." << endl;
	
	ifstream fin;
	/*char filename[100];
	strcpy_s(filename, strlen("foo.txt") + 1, "foo.txt");
	fin.open(filename);*/
	fin.open("foo.txt");
	if (!fin) {
		cout << "읽고자 오픈한 파일이 없음" << endl;
		return 0;
	}

	char tmp[100];
	// 파일의 끝이 아니라면 계속 읽어라
	while (!fin.eof()) {
		fin.getline(tmp, 100, '\n');
		cout << tmp << endl;
	}
	fin.close();

	return 0;
}