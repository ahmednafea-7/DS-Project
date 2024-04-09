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
	LinkedQueue<Earthsoldier> ES_list;
	// LinkedQueue<Aliensoldier> AS_list;

public:
	bool AddUnit(Unitarmy* unit);
	bool RemoveUnit(Unitarmy* unit);
	//LinkedQueue<Aliensoldier> AS_list;
	priQueue<EarthGunnery> EG_list;
	ArrayStack<EarthTank>ET_list;
public:
	bool AddUnit(Unitarmy* unit, int pri);
	void Print();
	void PrintEarth();
};