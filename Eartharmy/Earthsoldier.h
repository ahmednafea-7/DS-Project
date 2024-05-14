#pragma once

#include"../Unitarmy/Unitarmy.h"

class Earthsoldier:public Unitarmy
{	
	int initialHealth;
	int UML_Tj;
	bool Infected;
	bool Immune;
	static int Infected_Count;
	
public:
	Earthsoldier(int id=0 ,int tj = 0, int health = 0, int power = 0, int attackcap = 0,game* gptr = nullptr, string type = "ES" ,bool infected=false, bool immune=false);
	void SetinitialHealth(int health);
	int getinitialHealth();
	void SetInfected(bool infected);
	void SetImmune(bool immune);
	virtual bool IsInfected() const;
	bool IsImmune();
	static void SetInfCount(int count);
	static int GetInfCount();
	void attack();
	void setUML_Tj(int tj);
	int getUML_Tj();
	void InfAttack();
	
};
inline ostream& operator<<(ostream& os,const Earthsoldier& es) 
{
	if (es.IsInfected())
		os << "$" << es.GetID() << " ,";
	else
		os << es.GetType() <<es.GetID() << " ,";
	return os;
}