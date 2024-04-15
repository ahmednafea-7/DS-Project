#pragma once

#include"../Unitarmy/Unitarmy.h"

class Earthsoldier:public Unitarmy
{	
public:
	Earthsoldier(int id=0 ,int tj = 0, int health = 0, int power = 0, int attackcap = 0, string type = "ES");
	bool attack();
};
inline ostream& operator<<(ostream& os,const Earthsoldier& es) 
{
	os << es.GetID() << ", ";
	return os;
}