#include "Eartharmy.h"
bool Eartharmy::AddUnit(Unitarmy* unit, int pri=0)
{
	if (unit->GetType() == "ES") 
	{
		return ES_list.enqueue(*(dynamic_cast<Earthsoldier*>(unit)));
	}
	else if (unit->GetType() == "EG")
	{
		return EG_list.enqueue(*(dynamic_cast<EarthGunnery*>(unit)), (dynamic_cast<EarthGunnery*>(unit)->GetPri()));
	}
	else if (unit->GetType() == "ET")
	{
		return ET_list.push(*dynamic_cast<EarthTank*>(unit));
	}
	return false;
}

void Eartharmy::Print()
{
}
