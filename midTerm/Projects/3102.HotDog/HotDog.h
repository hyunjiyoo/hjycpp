#pragma once
#ifndef HOTDOG_H
#define HOTDOG_H
class HotDog {
private:
	int id;
	int dayCnt;

public:
	HotDog();
	~HotDog();
	int getId();
	int getDayCnt();
	void setId(int id);
	void setDayCnt(int dayCnt);

	/* static */
private:
	static int totCnt;
public:
	static int getTotCnt();
	static void setTotCnt(int _totCnt);
	void JustSold();
};
#endif HOTDOG_H