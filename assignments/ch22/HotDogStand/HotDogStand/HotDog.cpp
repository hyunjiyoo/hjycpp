#include <iostream>
#include "HotDog.h"
using namespace std;

int HotDog::totCnt = 0; // static 멤버변수 초기화

HotDog::HotDog() {
	this->id = 0;
	this->dayCnt = 0;
}
HotDog::~HotDog() {
}
int HotDog::getId() {
	return this->id;
}
int HotDog::getDayCnt() {
	return this->dayCnt;
}
void HotDog::setId(int id) {
	this->id = id;
}
void HotDog::setDayCnt(int dayCnt) {
	this->dayCnt = dayCnt;
}

int HotDog::getTotCnt() {
	return totCnt;
}
void HotDog::setTotCnt(int _totCnt) {
	totCnt = _totCnt;
}
void HotDog::JustSold() {
	this->dayCnt++;
	totCnt++;
}