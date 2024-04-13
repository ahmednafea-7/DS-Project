#pragma once
#include<iostream>

using namespace std;

class Unitarmy
{
	int ID;
	int Tj; // time joined
	int Health, Power, AttackCapacity;// att. cap. is the maximum no. of units could be attacked at 1 time step
	string Type;
public:
	Unitarmy(int id, int tj, int health, int power, int attackcap, string type);
	int GetID() const;
	int GetHealth();
	int GetPower();
	int GetAttackcapacity();
	string GetType();

	virtual bool attack() = 0;
	virtual void print() = 0;
	~Unitarmy();
};
inline ostream& operator<<(ostream& os, const Unitarmy& U)
{
	os << "Unit ID" << U.GetID() << endl;
	return os;
}