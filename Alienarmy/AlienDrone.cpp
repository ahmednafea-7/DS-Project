#include "AlienDrone.h"
#include "../Game/game.h"

AlienDrone::AlienDrone(int id, int tj, int health, int power, int attackcap, game* gptr, string type):Unitarmy(id, tj, health, power, attackcap, type,gptr)
{

}
void AlienDrone::attack()
{
    return ;
}

bool AlienDrone::IsInfected() const
{
    return false;
}
