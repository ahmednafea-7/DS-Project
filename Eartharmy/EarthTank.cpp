#include "EarthTank.h"


EarthTank::EarthTank(int id, int tj, int health, int power, int attackcap, string type ) :Unitarmy(id, tj, health, power, attackcap, type)
{
    
}
void EarthTank::print()
{
    cout << this->GetID();
}

bool EarthTank::attack()
{
    return false;
}
