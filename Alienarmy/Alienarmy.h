#pragma once
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"
#include "../Unitarmy/Unitarmy.h"

class Eartharmy
{
	// initialize the lists of all units
	// LinkedQueue<Aliensoldier> AS_list;


public:
	bool AddUnit(Unitarmy* unit);
	bool RemoveUnit(Unitarmy* unit);

		//LinkedQueue<Aliensoldier> AS_list;
	
public:
	bool AddUnit(Unitarmy* unit, int pri);
	void Print();
};