#pragma once
#include"../Queue/LinkedQueue.h"
#include "../Unitarmy/Unitarmy.h"
#include "../Queue/DoubleQueue.h"
class AlienDrone:public Unitarmy
{
public:
	AlienDrone(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, game* gptr = nullptr,string type = "AD");
	void attack();
	void attack(AlienDrone* ad1);
	virtual bool IsInfected() const;
};
inline ostream& operator<<(ostream& os, const AlienDrone& ad)
{
	os<< ad.GetID() <<" , ";
	return os;
}
