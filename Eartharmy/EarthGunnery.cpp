#include "EarthGunnery.h"
EarthGunnery::EarthGunnery(int id, int tj, int health, int power, int attackcap, game* gptr,string type):Unitarmy(id, tj, health, power, attackcap, type, gptr)
{
    Pri = sqrt(health* power); //combination for the priority
}

int EarthGunnery::GetPri()
{
    return Pri;
}
bool EarthGunnery::attack()
{
    return false;
}