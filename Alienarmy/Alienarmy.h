#pragma once
#include "Aliensoldier.h"
#include "Alienmonster.h"
#include "AlienDrone.h"
#include "../Array/Array.h"
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"
#include "../Queue/DoubleQueue.h"
#include <iostream>

#define MAX 1000

class Alienarmy
{
	// initialize the lists of all units
	LinkedQueue<Aliensoldier*> AS_list;
	DoubleQueue<AlienDrone*> AD_list;
	//Array<Alienmonster*> AM_list;
	Alienmonster* AM_list[MAX];
	int AMcount = 0;
public:
	bool AddUnit(Unitarmy* unit);
	void PrintAlien();
};
