#include "Alienarmy.h"

bool Alienarmy::AddUnit(Unitarmy* unit)
{
	if (unit->GetType() == "AS")
	{
		 // return AS_list.enqueue((dynamic_cast<Earthsoldier*>(unit)));
	}
	else if (unit->GetType() == "AD")
	{
		return AD_list.enqueue((dynamic_cast<AlienDrone*>(unit)));
	}
	else if (unit->GetType() == "AM")
	{
		// return ET_list.push(dynamic_cast<EarthTank*>(unit));
	}
	return false;
}

void Alienarmy::PrintAlien()
{
	AD_list.print();
}
