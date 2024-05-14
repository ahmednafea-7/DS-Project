#pragma once

#include"../Unitarmy/Unitarmy.h"

class Earthsoldier:public Unitarmy
{	
	int initialHealth;
	int UML_Tj;
	bool Infected;
	
public:
	Earthsoldier(int id=0 ,int tj = 0, int health = 0, int power = 0, int attackcap = 0,game* gptr = nullptr, string type = "ES" ,bool infected=false);
	void SetinitialHealth(int health);
	int getinitialHealth();
	void SetInfected(bool infected);
	virtual bool IsInfected() const;
	void SetInfCount(int count);
	int GetInfCount();
	void attack();
	void setUML_Tj(int tj);
	int getUML_Tj();
	void InfAttack();
	static int Infected_Count;
};
inline ostream& operator<<(ostream& os,const Earthsoldier& es) 
{
	if (es.IsInfected())
		os << "$" << es.GetID() << ", ";
	else
		os << es.GetType() <<es.GetID() << ", ";
	return os;
}