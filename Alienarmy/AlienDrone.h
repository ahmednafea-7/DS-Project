#pragma once
#include"../Queue/LinkedQueue.h"
#include "../Unitarmy/Unitarmy.h"
#include "../Queue/DoubleQueue.h"
class AlienDrone:public Unitarmy
{
	int count;

public:
	AlienDrone(int id, int tj, int health, int power, int attackcap, string type);
	void print();
	bool attack();
};
inline ostream& operator<<(ostream& os, const AlienDrone& ad)
{
	os << "AD ID:" << ad.GetID() << endl;
}
