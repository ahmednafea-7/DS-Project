#include "Alienarmy.h"

bool Alienarmy::AddUnit(Unitarmy* unit)
{
	if (!unit)
		return false;
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
		AM_list[AMcount++] = dynamic_cast<Alienmonster*>(unit); // to add a monster and increment the count
		return true;
	}
	return false;
}

void Alienarmy::PrintAlien()
{
	cout << "=========== Alive Alien Units ===========" << endl;
	cout << AS_list.GetCount() << " AS "; AS_list.print();
	cout << endl;
	cout << AD_list.GetCount() << " AD "; AD_list.print();
	cout << endl;
	if (AMcount == 0) {
		cout << "0" << " AM [ ]" << endl;
		return;
	}
	std::cout << AMcount << " AM [  ";
	for (int i = 0;i < AMcount;i++) {
		if (AM_list[i]) {
			AM_list[i]->print();
			std::cout << ", ";
		}
	}
	cout << '\b' << '\b' << "  ";
	cout << "] There are " << AMcount << " Of this list" << endl;
}
//Remove unit takes Unitarmy pointer as a reference for the Alien drone to take the Backptr drone 
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
		if (AMcount == 0)
		{
			U = nullptr;
			return U;
		}
		std::random_device rd;
		std::uniform_int_distribution<int> random(0, AMcount);
		int x = random(rd);
		Alienmonster* temp = AM_list[x];
		AM_list[x] = AM_list[(AMcount--)-1]; // to swap between last element and the random one and decrement the count at the same time
		return temp; 
	}
	return nullptr;
}
