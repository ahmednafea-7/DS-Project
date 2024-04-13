#include "Eartharmy.h"

bool Eartharmy::AddUnit(Unitarmy* unit)
{
	if (unit->GetType() == "ES")
	{
		/*Earthsoldier a;
		a.increment();*/
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
//Unitarmy* Eartharmy::RemoveUnit(Unitarmy* unit)
//{
//	if (unit->GetType() == "ES")
//	{
//		Earthsoldier* a = dynamic_cast<Earthsoldier*>(unit);
//		ES_list.dequeue(a);
//		return a;
//	}
//	else if (unit->GetType() == "EG")
//	{
//		EarthGunnery* G = dynamic_cast<EarthGunnery*>(unit);
//		int x = 0;
//		EG_list.dequeue(G,x);
//	}
//	else if (unit->GetType() == "ET")
//	{
//		EarthTank* T = dynamic_cast<EarthTank*>(unit);
//		ET_list.pop(T);
//		return T;
//	}
//	return unit;
//}
Unitarmy* Eartharmy::RemoveUnit(string type)
{
	if (type == "ES")
	{
		Earthsoldier* a;// = dynamic_cast<Earthsoldier*>(unit);
		ES_list.dequeue(a);
		return a;
	}
	else if (type == "EG")
	{
		EarthGunnery* G;// = dynamic_cast<EarthGunnery*>(unit);
		int x = 0;
		EG_list.dequeue(G, x);
	}
	else if (type == "ET")
	{
		EarthTank* T; // = dynamic_cast<EarthTank*>(unit);
		ET_list.pop(T);
		return T;
	}
	return nullptr;
}

