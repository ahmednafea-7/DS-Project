#pragma once
#pragma once
#include"../Unitarmy/Unitarmy.h"
class SaverUnit :public Unitarmy
{

public:
	SaverUnit(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, game* gptr = nullptr, string type = "SU");
	bool IsInfected() const;
	void attack();
};