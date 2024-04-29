#include "EarthTank.h"


EarthTank::EarthTank(int id, int tj, int health, int power, int attackcap, game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type,gptr)
{
    
}
bool EarthTank::attack()
{
    return false;
}
