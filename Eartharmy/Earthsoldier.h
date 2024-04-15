#pragma once

#include"../Unitarmy/Unitarmy.h"

class Earthsoldier:public Unitarmy
{	
public:
	Earthsoldier(int id , int tj , int health, int power, int attackcap, string type = "ES");
	bool attack();
};
inline ostream& operator<<(ostream& os,const Earthsoldier& es) 
{
	os << es.GetID() << ", ";
	return os;
}