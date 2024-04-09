#pragma once
#include "../PriorityQueue/priQueue.h"
#include "../Unitarmy/Unitarmy.h"
class EarthGunnery :public Unitarmy
{
	int count;
	int Pri;

public:
	EarthGunnery(int id, int tj, int health, int power, int attackcap, string type);
	void print();
	int GetPri();
	bool attack();
};
inline ostream& operator<<(ostream& os, const EarthGunnery& eg) {
	os << "EG ID:" << eg.GetID() << endl;
}