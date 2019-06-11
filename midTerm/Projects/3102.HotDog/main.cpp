#include <iostream>
#include "HotDog.h"
using namespace std;

int main() {
	int num;
	while (true) {
		cout << "핫도그 가판대를 몇 개 만들 것인가요: ";
		cin >> num;
		if (num < 3 || num > 9)
			cout << "3~9 사이의 값을 입력해주세요" << endl;
		else
			break;
	}

	HotDog* hd = new HotDog[num];

	for (int i = 0; i < num; i++) {
		hd[i].setId(i);
		hd[i].setDayCnt(0);
	}

	while (true) {
		cout << "가판대 ID 입력(종료를 원하시면 q나 Q 입력): ";

		char input; cin >> input;
		cin.clear(); cin.ignore();
		int id = input - 48;
		if (id == hd[id].getId()) {
			hd[id].JustSold();
			cout << "[" << hd[id].getId() << "]" << "가판대 핫도그 판매량: " << hd[id].getDayCnt() << endl;
		}
		else if (input == 'q' || input == 'Q') {
			break;
		}
		else if (id >= num || id < 0) {
			cout << "존재하지 않는 가판대ID 입니다." << endl;
			cout << "0~" << num - 1 << "사이의 값을 입력해주세요" << endl;
		}
	}
	cout << "-------------------------------------" << endl;
	for (int j = 0; j < num; j++) {
		cout << "[" << hd[j].getId() << "]";
		cout << "가판대의 판매량: " << hd[j].getDayCnt() << endl;
	}
	cout << "-------------------------------------" << endl;
	cout << "총 판매량: " << hd->getTotCnt() << endl;

	if (hd != NULL) {
		delete[] hd;
		hd = NULL;
	}

	return 0;
}