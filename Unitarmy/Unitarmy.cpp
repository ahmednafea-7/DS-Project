#include "Unitarmy.h"

Unitarmy::Unitarmy(int id=0, int tj=0, int health=100, int power=100, int attackcap=1, string type)
{
	ID = id;
	Tj = tj;
	Health = health;
	Power = power;
	AttackCapacity = attackcap;
	Type = type;
}
int Unitarmy::GetID() const{ return ID; }
int Unitarmy::GetHealth() { return Health; }
int Unitarmy::GetPower() { return Power; }
int Unitarmy::GetAttackcapacity() { return AttackCapacity; }
string Unitarmy::GetType() { return Type; }
Unitarmy::~Unitarmy()
{
}
