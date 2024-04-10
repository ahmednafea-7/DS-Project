#pragma once
#include "Aliensoldier.h"
#include "Alienmonster.h"
#include "AlienDrone.h"
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"
#include "../Queue/DoubleQueue.h"


class Alienarmy
{
	// initialize the lists of all units
	/*LinkedQueue<Aliensoldier> AS_list;*/
	DoubleQueue<AlienDrone> AD_list;

	// LinkedQueue<Aliensoldier> AS_list;

public:
	bool AddUnit(Unitarmy* unit);
	//bool RemoveUnit(Unitarmy* unit);
	void PrintAlien();
};
