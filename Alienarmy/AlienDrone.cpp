#include "AlienDrone.h"


AlienDrone::AlienDrone(int id, int tj, int health, int power, int attackcap, game* gptr, string type):Unitarmy(id, tj, health, power, attackcap, type,gptr)
{

}
bool AlienDrone::attack()
{
    return false;
}