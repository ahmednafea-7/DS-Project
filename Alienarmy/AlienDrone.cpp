#include "AlienDrone.h"


AlienDrone::AlienDrone(int id, int tj, int health, int power, int attackcap, string type = "AD") :Unitarmy(id, tj, health, power, attackcap, type)
{

}
void AlienDrone::print()
{
    cout << this->GetID();
}

bool AlienDrone::attack()
{
    return false;
}