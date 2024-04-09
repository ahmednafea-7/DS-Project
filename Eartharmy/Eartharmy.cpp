#include "Eartharmy.h"

bool Eartharmy::AddUnit(Unitarmy* unit)
{
	if (unit->GetType() == "ES") {
		return ES_list.enqueue(*(dynamic_cast<Earthsoldier*>(unit)));
	}
	else if(unit->GetType() =="EG")
	{
		return false;
	}
	else if (unit->GetType() == "AD")
	{
		return;
	}
	return false;
}
bool Eartharmy::RemoveUnit(Unitarmy* unit)
{
	return false;
}

void Eartharmy::printEarth()
{
	ES_list.print();
}
