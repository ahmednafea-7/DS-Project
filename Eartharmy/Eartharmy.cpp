#include "Eartharmy.h"

bool Eartharmy::AddUnit(Unitarmy* unit)
{
	if (!unit)
		return false;
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
Unitarmy* Eartharmy::RemoveUnit(string type)
{
	if (type == "ES")
	{
		Earthsoldier* a = new Earthsoldier; //(ask about that if the new is better for memory ? )
		ES_list.dequeue(a);
		return a;
	}
	else if (type == "EG")
	{
		EarthGunnery* G = new EarthGunnery;
		int x = 0;
		EG_list.dequeue(G, x);
		return G;
	}
	else if (type == "ET")
	{
		EarthTank* T = new EarthTank;
		ET_list.pop(T);
		return T;
	}
	return nullptr;
}

void Eartharmy::printEarth()
{
	cout<<endl << "=========== ALive Earth Units ===========" << endl;

	cout << ES_list.GetCount() << " ES "; ES_list.print();
	cout << endl;
	cout << EG_list.GetCount() << " EG "; EG_list.print();
	cout << endl;
	cout << ET_list.GetCount() << " ET "; ET_list.print();
	cout << endl;
}

void Eartharmy::attack()
{

	Earthsoldier* a = new Earthsoldier;
	ES_list.peek(a);
	a->attack();
	cout << endl;

	EarthGunnery* EG = new EarthGunnery;
	int pri;
	EG_list.peek(EG, pri);
	EG->attack();
	cout << endl;



}
LinkedQueue<Earthsoldier*>& Eartharmy::GetESList()
{
	return ES_list;
}
priQueue<EarthGunnery*>& Eartharmy::GetEGList()
{
	return EG_list;
}
ArrayStack<EarthTank*>& Eartharmy::GetETList()
{
	return ET_list;
}