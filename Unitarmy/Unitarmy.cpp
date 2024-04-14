#include "../Unitarmy/Unitarmy.h"

Unitarmy::Unitarmy(int id, int tj, int health, int power, int attackcap, string type)
{
	ID = id;
	Tj = tj;
	Health = health;
	Power = power;
	AttackCapacity = attackcap;
	Type = type;
}
void Unitarmy::SetID(int id)
{
	ID = id;
}
void Unitarmy::SetTj(int tj) {Tj = tj;}
void Unitarmy::SetHealth(int health) { Health = health;}
void Unitarmy::SetPower(int power) {Power = power;}
void Unitarmy::SetAttackCapacity(int attackcap) {AttackCapacity = attackcap;}

int Unitarmy::GetID() const { return ID; }
int Unitarmy::GetHealth() { return Health; }
int Unitarmy::GetPower() { return Power; }
int Unitarmy::GetAttackcapacity() { return AttackCapacity; }
string Unitarmy::GetType() const { return Type; }
Unitarmy::~Unitarmy()
{
}
