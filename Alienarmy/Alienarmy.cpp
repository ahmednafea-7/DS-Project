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
		AM_list[AMcount++] = dynamic_cast<Alienmonster*>(unit);
		return true;
	}
	return false;
}

void Alienarmy::PrintAlien()
{
	cout << AS_list.GetCount() << " AS "; AS_list.print();
	cout << endl;
	cout << AD_list.GetCount() << " AD "; AD_list.print();
	cout << endl;

	//AM_list.print();
	std::cout << AMcount << " AM [";
	for (int i = 0;i < AMcount;i++) {
		if (AM_list[i]) {
			AM_list[i]->print();
			std::cout << ",";
		}
	}
	cout <<" ]";
	cout << endl;
}
Unitarmy* Alienarmy::RemoveUnit(string type, Unitarmy*& U)
{
	if (type == "AS")
	{
		Aliensoldier* a;
		AS_list.dequeue(a);
		return a;
	}
	else if (type == "AD")
	{
		AlienDrone* D_Front;
		AlienDrone* D_Back;
		AD_list.dequeue(D_Front,D_Back);
		U = D_Back;
		return D_Front;
	}
	else if (type == "AM")
	{
		int x = rand() % AMcount + 1;
		Alienmonster* temp = AM_list[x];
		AM_list[x] = AM_list[AMcount--];
		
		return temp;
	}
	return nullptr;
}
