#include <iostream>
using namespace std;
class AAA {
private:
	int a, b;
protected:
	int c;
public:
	int pub;
	void func() {
		cout << "I'm in AAA" << endl;
	}
	AAA();
	AAA(int a, int b, int c);
	~AAA();
	void print();
};
AAA::AAA() {
	cout << "AAA: ���� ���� ������" << endl;
	this->a = 0;
	this->b = 0;
	this->c = 0;
}
AAA::AAA(int a, int b, int c) {
	cout << "AAA: ���� �ִ� ������" << endl;
	this->a = a;
	this->b = b;
	this->c = c;
}
AAA::~AAA() {
	cout << "AAA: �Ҹ���" << endl;
}
void AAA::print() {
	cout << "a: " << this->a << " b: " << this->b << " c: " << this->c;
	cout << " pub: " << this->pub << endl;
}
// AAA�� ����ϴ� BBB
class BBB :public AAA {
private:
	int d;
	char name[18];
public:
	int pub;
	void func() {
		cout << "I'm in BBB" << endl;
	}
	BBB();
	BBB(int d, const char* name);
	~BBB();
	void print();
};
BBB::BBB() {
	cout << "BBB: ���� ���� ������" << endl;
	this->d = 0;
	this->name[0] = NULL;
}
BBB::BBB(int d, const char* name) {
	cout << "BBB: ���� �ִ� ������" << endl;
	this->d = d;
	strcpy_s(this->name, strlen(name) + 1, name);
}
BBB::~BBB() {
	cout << "BBB: �Ҹ���" << endl;
}
void BBB::print() {
	cout << "c: " << this->c << " d: " << this->d << " name: " << this->name;
	cout << " pub: " << this->pub << endl;
}
int main() {
	cout << "sizeof(AAA): " << sizeof(AAA) << endl; // 12
	cout << "sizeof(BBB): " << sizeof(BBB) << endl; // 36 (char name[18] ���� 4�� ����� �޸� ������. padding ������)
	BBB b(100, "�����");
	b.print();
	b.AAA::print();
	b.func();
	b.AAA::func();
	return 0;
}