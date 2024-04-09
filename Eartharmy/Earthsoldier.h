#pragma once
#include"../Queue/LinkedQueue.h"
#include"../Unitarmy/Unitarmy.h"

class Earthsoldier:public Unitarmy
{
	int count;
	
public:
	Earthsoldier(int id, int tj, int health, int power, int attackcap, string type);
	void print();
	 
	bool attack();
};
inline ostream& operator<<(ostream& os,const Earthsoldier& es) 
{
	os <<"ES ID:" << es.GetID() << endl;
}