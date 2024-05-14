#pragma once               
#include"../Unitarmy/Unitarmy.h"
class Aliensoldier :public Unitarmy
{
public:
	Aliensoldier(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, game* gptr = nullptr, string type = "AS");
	virtual bool IsInfected() const;
	void attack();
};
inline ostream& operator<<(ostream& os, const Aliensoldier& as)
{
	os <<as.GetID()<<" , ";
	return os;
}
