#include "Unitarmy.h"

Unitarmy::Unitarmy(int id, int tj, int health, int power, int attackcap, string type)
{
	ID = id;
	Tj = tj;
	Health = health;
	Power = power;
	AttackCapacity = attackcap;
	Type = type;
}
int Unitarmy::GetID() const { return ID; }
int Unitarmy::GetHealth() { return Health; }
int Unitarmy::GetPower() { return Power; }
int Unitarmy::GetAttackcapacity() { return AttackCapacity; }
string Unitarmy::GetType() { return Type; }
Unitarmy::~Unitarmy()
{
}
