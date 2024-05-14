#pragma once
#include "Earthsoldier.h"
#include "EarthGunnery.h"
#include "EarthTank.h"
#include "Healunit.h"
#include"../Allyarmy/SaverUnit.h"
#include "../Queue/LinkedQueue.h"
#include "../Stack/ArrayStack.h"
#include "../PriorityQueue/priQueue.h"


class Eartharmy
{
	// initialize the lists of all units
	LinkedQueue<Earthsoldier*> ES_list;
	priQueue<EarthGunnery*> EG_list;
	ArrayStack<EarthTank*> ET_list;
	ArrayStack<HealUnit*> HU_list;
	LinkedQueue<SaverUnit*> SU_list;
public:
	bool AddUnit(Unitarmy* unit);
	Unitarmy* RemoveUnit(string type);
	void printEarth();
	void attack();
	bool isDefeated();
	int getTotalUnits();
	LinkedQueue<Earthsoldier*>& GetESList();
	priQueue<EarthGunnery*>& GetEGList();
	ArrayStack<EarthTank*>& GetETList();
	ArrayStack<HealUnit*>& GetHUList(); /**/
	LinkedQueue<SaverUnit*>& GetSUList();
};