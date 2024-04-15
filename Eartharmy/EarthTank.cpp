#include "EarthTank.h"


EarthTank::EarthTank(int id, int tj, int health, int power, int attackcap, string type ) :Unitarmy(id, tj, health, power, attackcap, type)
{
    
}
bool EarthTank::attack()
{
    return false;
}
