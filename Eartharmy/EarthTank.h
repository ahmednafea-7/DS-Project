#pragma once

#include"../Unitarmy/Unitarmy.h"

class EarthTank:public Unitarmy
{	
	int initialHealth;
public:
	EarthTank(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, game* gptr = nullptr, string type = "ET");
	void SetinitialHealth(int health);
	int getinitialHealth();
	void attack();
	static bool Cond;
};
inline ostream& operator<<(ostream& os,const EarthTank& et) 
{
	os << et.GetID() <<", ";
	return os;
}


