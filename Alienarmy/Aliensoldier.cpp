#include "Aliensoldier.h"
Aliensoldier::Aliensoldier(int id, int tj, int health, int power, int attackcap, game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type, gptr)
{

}
bool Aliensoldier::attack()
{
	return false;
}