#pragma once
#include"../Unitarmy/Unitarmy.h"
class Alienmonster : public Unitarmy
{
	int Infect_Prob;
	//int Rand_Inf; 
public:
	Alienmonster(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, game* gptr = nullptr, string type = "AM", int infp=50);
	void attack();
	virtual bool IsInfected() const;
};
