#include "Alienarmy.h"

bool Alienarmy::AddUnit(Unitarmy* unit)
{
	if (!unit)
		return false;
	if (unit->GetType() == "AS")
	{
		return AS_list.enqueue(dynamic_cast<Aliensoldier*>(unit));
	}
	else if (unit->GetType() == "AD")
	{
		  return AD_list.enqueue(dynamic_cast<AlienDrone*>(unit));
	}
	else if (unit->GetType() == "AM")
	{
		AM_list[AMcount++] = dynamic_cast<Alienmonster*>(unit); // to add a monster and increment the count
		return true;
	}
	return false;
}

int Alienarmy::GetAmCount()
{
	return AMcount;
}
void Alienarmy::PrintAlien()
{
	cout << "=========== Alive Alien Units ===========" << endl;
	cout << AS_list.GetCount() << " AS "; AS_list.print();
	cout << endl;
	if (AMcount == 0)
		cout << "0" << " AM [ ]" << endl;
	else {
		cout << AMcount << " AM [  ";
		for (int i = 0; i < AMcount; i++) {
			/*if (AM_list[i])*/ // to check if there is a monster in that (no need as there will be no gaps inside the array)
			cout << AM_list[i]->GetID() << ", ";
		}
		cout << '\b' << '\b' << "  ";
		cout << "]" << endl;
	}
	cout << AD_list.GetCount() << " AD "; AD_list.print();
	cout << endl << endl;
}
void Alienarmy::attack()
{
	Aliensoldier* AS = new Aliensoldier;
	AS_list.peek(AS);
	if (AS)
		AS->attack();
	else
		cout << "NO AS";
	cout << endl;

	if (AMcount)
		PickAm()->attack();
	else
		cout << "NO AM";
	cout << endl;
}
//Remove unit takes Unitarmy pointer as a reference for the Alien drone to take the Backptr drone 
//Unitarmy* Alienarmy::RemoveUnit(string type, Unitarmy*& U) 
//{
//	if (type == "AS")
//	{
//		Aliensoldier* a = new Aliensoldier;
//		AS_list.dequeue(a);
//		return a;
//	}
//	else if (type == "AD")
//	{
//		AlienDrone* D_Front = new AlienDrone;
//		AlienDrone* D_Back  = new AlienDrone;
//		AD_list.dequeue(D_Front,D_Back);
//		U = D_Back;
//		return D_Front;
//	}
//	else if (type == "AM")
//	{
//		if (AMcount == 0)
//			return nullptr;
//		std::random_device rd;
//		std::uniform_int_distribution<int> random(0, AMcount-1);
//		int x = random(rd);
//		Alienmonster* temp = AM_list[x];
//		AM_list[x] = AM_list[--AMcount]; // to swap between last element and the random one and decrement the count
//		return temp; 
//	}
//	return nullptr;
//}





LinkedQueue<Aliensoldier*>& Alienarmy::getAS_List()
{
	return AS_list;
}

DoubleQueue<AlienDrone*>& Alienarmy::getAD_List()
{
	return AD_list;
}

Alienmonster** Alienarmy::getAM_List()
{
	return AM_list;
}

Alienmonster* Alienarmy::PickAm()
{
	if (AMcount == 0)
		return nullptr;
	std::random_device rd;
	std::uniform_int_distribution<int> random(0, AMcount - 1);
	int x = random(rd);
	Alienmonster* temp = AM_list[x];
	AM_list[x] = AM_list[--AMcount]; // to swap between last element and the random one and decrement the count
	return temp;
}
