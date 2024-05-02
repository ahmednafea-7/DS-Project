#pragma once
#include "Earthsoldier.h"
#include "EarthGunnery.h"
#include "EarthTank.h"
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"

class Eartharmy
{
	// initialize the lists of all units
	LinkedQueue<Earthsoldier*> ES_list;
	priQueue<EarthGunnery*> EG_list;
	ArrayStack<EarthTank*> ET_list;

public:
	bool AddUnit(Unitarmy* unit);
	Unitarmy* RemoveUnit(string type);
	void printEarth();
	void attack();
	LinkedQueue<Earthsoldier*>& GetESList();
	priQueue<EarthGunnery*>& GetEGList();
	ArrayStack<EarthTank*>& GetETList();

};