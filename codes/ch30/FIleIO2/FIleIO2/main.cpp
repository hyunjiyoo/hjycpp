#include <iostream>
#include <fstream>
using namespace std;
// 키보드로부터 이름, 학번, 학과 입력받기 (서로간 공백 없음)
// 쓸 목적의 파일이름을 입력 받기
// 그 파일을 열어서 위에서 입력 받은 이름, 학번, 학과를 쓰기 (이 때 서로간 개행 할 것)
// 파일 닫기
// 사용자에게 읽고자 하는 파일명 물어보기
// 파일의 내용을 읽어 화면에 출력하기
// 그 파일을 닫기
int main() {
	char name[30]; int num; char major[100];
	cin >> name >> num >> major;
	
	char filename[100];
	cout << "파일이름을 입력하시오: ";
	cin >> filename;
	ofstream fout; 
	fout.open(filename);
	if (!fout) {
		cout << "열고자 하는 파일이 없음" << endl;
		return 0;
	}

	fout << name << endl;
	fout << num << endl;
	fout << major << endl;
	fout.close();

	ifstream fin;
	while (true) {
		cout << "파일명: ";
		char input[100]; cin >> input;
		if (strcmp(filename, input) == 0) {
			cout << "파일의 내용을 읽어 화면에 출력" << endl;
			fin.open(input);
			if (!fin) {
				cout << "파일을 열 수 없음" << endl;
				return 0;
			}
			break;
		}
		else {
			cout << "파일명을 다시 입력하시오" << endl;
		}
	}
	fin >> name;
	fin >> num;
	fin >> major;
	cout << "Name: " << name << endl;
	cout << "num: " << num << endl;
	cout << "major: " << major << endl;
	fin.close();
	
	return 0;
}