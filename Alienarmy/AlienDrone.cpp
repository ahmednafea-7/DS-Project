#include "AlienDrone.h"


AlienDrone::AlienDrone(int id, int tj, int health, int power, int attackcap, string type) :Unitarmy(id, tj, health, power, attackcap, type)
{

}
bool AlienDrone::attack()
{
    return false;
}