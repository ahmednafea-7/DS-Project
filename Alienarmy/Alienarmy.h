#pragma once
#include "Aliensoldier.h"
#include "Alienmonster.h"
#include "AlienDrone.h"
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"
#include "../Queue/DoubleQueue.h"
#include <iostream>
#include <random> // to pick mosnters randomly

#define MAX 1000

class Alienarmy
{
	// initialize the lists of all units
	LinkedQueue<Aliensoldier*> AS_list;
	DoubleQueue<AlienDrone*> AD_list;
	Alienmonster* AM_list[MAX];
	int AMcount = 0;
public:
	bool AddUnit(Unitarmy* unit);;
	void PrintAlien();
	//Unitarmy* RemoveUnit(string type, Unitarmy*& U);
	LinkedQueue<Aliensoldier*>& getAS_List();
	DoubleQueue<AlienDrone*>& getAD_List();
	Alienmonster** getAM_List();
	Alienmonster* PickAm();
};
