#include "Eartharmy.h"

bool Eartharmy::AddUnit(Unitarmy* unit)
{
	if (unit->GetType() == "ES")
	{
		return ES_list.enqueue(dynamic_cast<Earthsoldier*>(unit));
	}
	else if (unit->GetType() == "EG")
	{
		return EG_list.enqueue(dynamic_cast<EarthGunnery*>(unit), dynamic_cast<EarthGunnery*>(unit)->GetPri());
	}
	else if (unit->GetType() == "ET")
	{
		return ET_list.push(dynamic_cast<EarthTank*>(unit));
	}
	return false;
}

void Eartharmy::printEarth()
{
	cout << ES_list.GetCount() << " ES ["; ES_list.print();
	cout << endl;
	cout << EG_list.GetCount() << " EG ["; EG_list.print();
	cout << endl;
	cout << ET_list.GetCount() << " ET ["; ET_list.print();
	cout << endl;
}
