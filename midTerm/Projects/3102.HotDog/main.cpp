#include <iostream>
#include "HotDog.h"
using namespace std;

int main() {
	int num;
	while (true) {
		cout << "�ֵ��� ���Ǵ븦 �� �� ���� ���ΰ���: ";
		cin >> num;
		if (num < 3 || num > 9)
			cout << "3~9 ������ ���� �Է����ּ���" << endl;
		else
			break;
	}

	HotDog* hd = new HotDog[num];

	for (int i = 0; i < num; i++) {
		hd[i].setId(i);
		hd[i].setDayCnt(0);
	}

	while (true) {
		cout << "���Ǵ� ID �Է�(���Ḧ ���Ͻø� q�� Q �Է�): ";

		char input; cin >> input;
		cin.clear(); cin.ignore();
		int id = input - 48;
		if (id == hd[id].getId()) {
			hd[id].JustSold();
			cout << "[" << hd[id].getId() << "]" << "���Ǵ� �ֵ��� �Ǹŷ�: " << hd[id].getDayCnt() << endl;
		}
		else if (input == 'q' || input == 'Q') {
			break;
		}
		else if (id >= num || id < 0) {
			cout << "�������� �ʴ� ���Ǵ�ID �Դϴ�." << endl;
			cout << "0~" << num - 1 << "������ ���� �Է����ּ���" << endl;
		}
	}
	cout << "-------------------------------------" << endl;
	for (int j = 0; j < num; j++) {
		cout << "[" << hd[j].getId() << "]";
		cout << "���Ǵ��� �Ǹŷ�: " << hd[j].getDayCnt() << endl;
	}
	cout << "-------------------------------------" << endl;
	cout << "�� �Ǹŷ�: " << hd->getTotCnt() << endl;

	if (hd != NULL) {
		delete[] hd;
		hd = NULL;
	}

	return 0;
}