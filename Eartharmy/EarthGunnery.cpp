#include "EarthGunnery.h"
EarthGunnery::EarthGunnery(int id, int tj, int health, int power, int attackcap, string type ) :Unitarmy(id, tj, health, power, attackcap, type)
{
    Pri = sqrt(health* power);
}
void EarthGunnery::print()
{
    cout << this->GetID();
}

int EarthGunnery::GetPri()
{
    return Pri;
}
bool EarthGunnery::attack()
{
    return false;
}