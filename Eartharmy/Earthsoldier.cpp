#include "Earthsoldier.h"


Earthsoldier::Earthsoldier(int id, int tj, int health, int power, int attackcap, string type ) :Unitarmy(id, tj, health, power, attackcap, type)
{
    
}
void Earthsoldier::print()
{
    cout << this->GetID();
}

bool Earthsoldier::attack()
{
    return false;
}


