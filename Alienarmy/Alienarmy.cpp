#include "Alienarmy.h"

bool Alienarmy::AddUnit(Unitarmy* unit)
{
	if (unit->GetType() == "AS")
	{
		return AS_list.enqueue((dynamic_cast<Aliensoldier*>(unit)));
	}
	else if (unit->GetType() == "AD")
	{
		return AD_list.enqueue((dynamic_cast<AlienDrone*>(unit)));
	}
	else if (unit->GetType() == "AM")
	{
		// return AM_list.insertitem((dynamic_cast<Alienmonster*>(unit)));
		AM_list[AMcount++] = dynamic_cast<Alienmonster*>(unit);
		return true;
	}
	return false;
}

void Alienarmy::PrintAlien()
{
	AS_list.print();
	AD_list.print();
	//AM_list.print();
	std::cout << AMcount << " AM" << "[";
	for(int i = 0;i < AMcount;i++) {
		if (AM_list[i]) {
			AM_list[i]->print();
			std::cout << ",";
		}
	}
	std:: cout << "]" << endl;
}
