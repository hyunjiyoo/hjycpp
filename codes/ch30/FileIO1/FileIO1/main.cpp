#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout;
	fout.open("foo.txt"); // default�� overwrite(=> trunc)
	// ������ �� ������ �� (������ ���� ���) error �޼��� ���.
	if (!fout) {
		cout << "file�� �� �� �����ϴ�." << endl;
		return 0;
	}
	fout << "�̰��� �츮�� ����� ù��° �����̴�." << endl;
	fout << "5�� 28���� ��ſ� mid3rd ���� ��~" << endl;
	fout << "Stay hungry! Stay foolish!!" << endl;

	fout.close();
	cout << "file�� �� ����������� ��� ���빰�� display �Ͻÿ�." << endl;
	
	ifstream fin;
	/*char filename[100];
	strcpy_s(filename, strlen("foo.txt") + 1, "foo.txt");
	fin.open(filename);*/
	fin.open("foo.txt");
	if (!fin) {
		cout << "�а��� ������ ������ ����" << endl;
		return 0;
	}

	char tmp[100];
	// ������ ���� �ƴ϶�� ��� �о��
	while (!fin.eof()) {
		fin.getline(tmp, 100, '\n');
		cout << tmp << endl;
	}
	fin.close();

	return 0;
}