#include "Earthsoldier.h"


Earthsoldier::Earthsoldier(int id, int tj, int health, int power, int attackcap, string type ) :Unitarmy(id, tj, health, power, attackcap, type)
{
    
}
bool Earthsoldier::attack()
{
    return false;
}