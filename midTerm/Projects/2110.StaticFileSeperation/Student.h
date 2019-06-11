#ifndef STUDENT_H
#define STUDENT_H
class Student {
	// ��ü �����
private:
	char name[100];
	int sNo;
public:
	Student(const char* name, int stdNum);
	~Student();
	// ������
	const char* getName();
	int getSNo();
	void SetName(const char* name);
	void SetSNo(int stdNum);

	// static �����
private:
	static int s_cnt;
public:
	static int getScnt();
	static void setScnt(int val);
	static void printScnt();
};
#endif STUDENT_H