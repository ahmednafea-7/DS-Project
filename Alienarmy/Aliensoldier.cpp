#include "Aliensoldier.h"
Aliensoldier::Aliensoldier(int id, int tj, int health, int power, int attackcap, string type) :Unitarmy(id, tj, health, power, attackcap, type) 
{

}
void Aliensoldier::print()
{
	cout << this->GetID();
}
bool Aliensoldier::attack()
{
	return false;
}