#pragma once

#include"../Unitarmy/Unitarmy.h"

class EarthTank:public Unitarmy
{	
public:
	EarthTank(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, string type = "ET");
	void print();
	bool attack();
};
inline ostream& operator<<(ostream& os,const EarthTank& et) 
{
	os << et.GetID() <<", ";
	return os;
}

