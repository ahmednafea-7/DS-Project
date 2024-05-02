#include "../Unitarmy/Unitarmy.h"
#include "../Game/game.h"
Unitarmy::Unitarmy(int id, int tj, int health, int power, int attackcap,string type, game* Gptr)
{
	ID = id;
	Tj = tj;
	Health = health;
	Power = power;
	AttackCapacity = attackcap;
	Type = type;
	gameptr = Gptr;
}
void Unitarmy::SetID(int id)
{
	ID = id;
}
void Unitarmy::SetTj(int tj) {Tj = tj;}
void Unitarmy::SetHealth(int health) {
	if (health < 0)
	{
		Health = 0;
		return;
	}
	Health = health;
}
void Unitarmy::SetTa(int TA)
{
	if(!Ta)
	Ta = TA;
}
void Unitarmy::Setinfo(int TD)
{
	Td = TD;
	Df = Ta - Tj;
	Dd = Td - Ta;
	Db = Td - Tj;
}
int Unitarmy::CalcDmg(Unitarmy* U)
{
	//int dmg = (Power * ((float)Health / 100)) / sqrt(U->GetHealth());
	
	return (Power * ((float)Health / 100)) / sqrt(U->GetHealth());
}

int Unitarmy::GetID() const { return ID; }
int Unitarmy::GetHealth() { return Health; }
int Unitarmy::GetPower() { return Power; }
int Unitarmy::GetAttackcapacity() { return AttackCapacity; }
int Unitarmy::GetTd()
{
	return Td;
}
int Unitarmy::GetTj()
{
	return Tj;
}
int Unitarmy::GetTa()
{
	return Ta;
}
int Unitarmy::GetDf()
{
	return Df;
}
int Unitarmy::GetDd()
{
	return Dd;
}
int Unitarmy::GetDb()
{
	return Db;
}

string Unitarmy::GetType() const { return Type; }


Unitarmy::~Unitarmy()
{
}
