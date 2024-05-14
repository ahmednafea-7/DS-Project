#pragma once
#include<iostream>

using namespace std;
class game;
class Unitarmy
{
protected:
	game* gameptr;
	int ID;
	int Tj;// time joined
	int Ta = 0; // First attacked time,
	int Td;  // time delayed
	int Health, Power, AttackCapacity;// att. cap. is the maximum no. of units could be attacked at 1 time step
	string Type;
	int Df,Dd,Db; // First attack delay, Destruction delay, battle time
	bool Infected = false;
public:
	Unitarmy(int id, int tj, int health , int power , int attackcap , string type, game* Gptr = nullptr);
	void SetID(int id);
	void SetTj(int tj);
	void SetHealth(int health);
	void SetTa(int TA);
	void Setinfo(int TD); // takes destruction time and sets all remaining definitions 
	int CalcDmg(Unitarmy* U);
	int GetID() const;
	int GetHealth();
	int GetPower();
	int GetAttackcapacity();
	int GetTj();//time joined
	int GetTa();// First attacked time
	int GetTd();
	int GetDf();
	int GetDd();
	int GetDb();
	virtual bool IsInfected()const = 0;
	string GetType() const;
	virtual void attack() = 0;
	~Unitarmy();
};
inline ostream& operator<<(ostream& os, const Unitarmy& U)
{
	if (U.IsInfected())
		os << "$" << U.GetID() << " , ";
	else
		os<<U.GetType() << U.GetID() << " , ";
	return os;
}
