#include <iostream>
#include <fstream>
using namespace std;
// Ű����κ��� �̸�, �й�, �а� �Է¹ޱ� (���ΰ� ���� ����)
// �� ������ �����̸��� �Է� �ޱ�
// �� ������ ��� ������ �Է� ���� �̸�, �й�, �а��� ���� (�� �� ���ΰ� ���� �� ��)
// ���� �ݱ�
// ����ڿ��� �а��� �ϴ� ���ϸ� �����
// ������ ������ �о� ȭ�鿡 ����ϱ�
// �� ������ �ݱ�
int main() {
	char name[30]; int num; char major[100];
	cin >> name >> num >> major;
	
	char filename[100];
	cout << "�����̸��� �Է��Ͻÿ�: ";
	cin >> filename;
	ofstream fout; 
	fout.open(filename);
	if (!fout) {
		cout << "������ �ϴ� ������ ����" << endl;
		return 0;
	}

	fout << name << endl;
	fout << num << endl;
	fout << major << endl;
	fout.close();

	ifstream fin;
	while (true) {
		cout << "���ϸ�: ";
		char input[100]; cin >> input;
		if (strcmp(filename, input) == 0) {
			cout << "������ ������ �о� ȭ�鿡 ���" << endl;
			fin.open(input);
			if (!fin) {
				cout << "������ �� �� ����" << endl;
				return 0;
			}
			break;
		}
		else {
			cout << "���ϸ��� �ٽ� �Է��Ͻÿ�" << endl;
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