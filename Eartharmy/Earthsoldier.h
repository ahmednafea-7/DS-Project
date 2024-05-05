#pragma once

#include"../Unitarmy/Unitarmy.h"

class Earthsoldier:public Unitarmy
{	
	int initialHealth;
public:
	Earthsoldier(int id=0 ,int tj = 0, int health = 0, int power = 0, int attackcap = 0,game* gptr = nullptr, string type = "ES" );
	void SetinitialHealth(int health);
	int getinitialHealth();
	void attack();
};
inline ostream& operator<<(ostream& os,const Earthsoldier& es) 
{
	os << es.GetID() << ", ";
	return os;
}