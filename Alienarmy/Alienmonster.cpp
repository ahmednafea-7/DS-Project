#include"Alienmonster.h"
Alienmonster::Alienmonster(int id, int tj, int health, int power, int attackcap,game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type, gptr)
{

}
bool Alienmonster::attack()
{
	return false;
}