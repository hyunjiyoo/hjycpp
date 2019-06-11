#include <iostream>
using namespace std;
/* ADT ������ ���� */
class Power {
public:
	int kick; int punch;
	Power();
	Power(int k, int p);
	Power(const Power& p);
	~Power();
	void show();
	Power& operator=(const Power& obj); // ���� ������
	bool operator==(const Power& obj); // == ������
	Power operator+(const Power& obj); // + ������
	Power& operator+=(int i); // += ������ with int
	Power& operator+=(const Power& obj); // += ������
};
Power::Power() {
	cout << "���� ���� ������" << endl;
	this->kick = 0;
	this->punch = 0;
}
Power::Power(int k, int p) {
	cout << "���� �ִ� ������" << endl;
	this->kick = k;
	this->punch = p;
}
Power::Power(const Power& p) {
	cout << "���� ������" << endl;
	this->kick = p.kick;
	this->punch = p.punch;
}
Power::~Power() {
	cout << "�Ҹ���" << endl;
}
void Power::show() {
	cout << "kick: " << this->kick << "  punch: " << this->punch << endl;
}
Power& Power::operator=(const Power& obj) {
	/* return type�� �����ΰ� �ȴ�. (�׶� call by ref Ÿ��)
	   p1 = p1; �϶��� �ƹ��� ���� �ʱ� ���� ���ǹ� �޾���.
	   p1.operator=(p1); this�� �Ű������� &obj�� ������. */

	   /* ���� ���� ������ overloading */
	if (this != &obj) {
		this->kick = obj.kick;
		this->punch = obj.punch;
	}
	return *this;
}
// p1 == p2;  |  p1.operator(p2); bool�� ����.
bool Power::operator==(const Power& obj) {
	/* this�� ����: "�� ��ü��" */
	if (this->kick == obj.kick && this->punch == obj.punch)
		return true;
	else
		return false;
}
// p1 = p2 + p3;  |  ���ο� Power��ü �����ؾ� �ؼ� tmp����� Power��ü ����.
Power Power::operator+(const Power& obj) {
	Power tmp;
	tmp.kick = this->kick + obj.kick;
	tmp.punch = this->punch + obj.punch;
	return tmp;
}
// p1 += p2;  | p1.operator(p2);
Power& Power::operator+=(const Power& obj) {
	this->kick += obj.kick;
	this->punch += obj.punch;
	return *this;
}
// p1 += 5;  | p1.operator(5);
Power& Power::operator+=(int i) {
	this->kick += i;
	this->punch += i;
	return *this;
}
/* ADT ������ �� */

/* Ŭ���̾�Ʈ�� ���� */
int main() {
	Power A(3, 5), B(4, 6), C(5, 50);
	C = A + B;
	C.show();
	if (A == B) {
		cout << "���� ��ü" << endl;
	}
	A = B;
	if (A == B) {
		cout << "���� ��ü" << endl;
	}
	else {
		cout << "�ٸ� ��ü" << endl;
	}
	A += B;
	A.show();
	A += 5;
	A.show();

	return 0;
}