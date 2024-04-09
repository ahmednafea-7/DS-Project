#pragma once
#include "Earthsoldier.h"
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"

class Eartharmy
{
	// initialize the lists of all units
	LinkedQueue<Earthsoldier> ES_list;
	// LinkedQueue<Aliensoldier> AS_list;

public:
	bool AddUnit(Unitarmy* unit);
	bool RemoveUnit(Unitarmy* unit);
};