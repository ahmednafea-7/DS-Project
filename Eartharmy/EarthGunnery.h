#pragma once
#include "../Unitarmy/Unitarmy.h"

class EarthGunnery :public Unitarmy
{
	int Pri;

public:
	EarthGunnery(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0,game* gptr = nullptr, string type = "EG");
	int GetPri();
	void attack();
};
inline ostream& operator<<(ostream& os, const EarthGunnery& eg) {
	os << eg.GetID() <<", ";
	//os << "Priority : " << eg.GetPri() << endl;
	return os;
}