#pragma once

#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"

class Alienarmy
{
	// initialize the lists of all units
	LinkedQueue<Aliensoldier> ES_list;
	

public:
	bool AddUnit(Unitarmy* unit);
	bool RemoveUnit(Unitarmy* unit);
};