#include"Alienmonster.h"
Alienmonster::Alienmonster(int id, int tj, int health, int power, int attackcap, string type) :Unitarmy(id, tj, health, power, attackcap, type)
{

}
void Alienmonster::print()
{
	cout << this->GetID();
}
bool Alienmonster::attack()
{
	return false;
}