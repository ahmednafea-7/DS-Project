#include<iostream>

using namespace std;

class Unitarmy
{
	int ID;
	int Tj; // time joined
	int Health, Power, AttackCapacity;// att. cap. is the maximum no. of units could be attacked at 1 time step
	string Type;
public:
	Unitarmy(int id, int tj, int health, int power, int attackcap, string type) 
	{
		ID = id;
		Tj = tj;
		Health = health;
		Power = power;
		AttackCapacity = attackcap;
		Type = type;
	};
	int GetID() { return ID; }
	int GetHealth() { return Health; }
	int GetPower() { return Power; }
	int GetAttackcapacity() { return AttackCapacity; }
	string GetType() { return Type; }
	virtual bool attack() = 0;
	virtual void print() = 0;
	~Unitarmy();
};