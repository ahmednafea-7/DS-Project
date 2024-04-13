#pragma once
#include"../Unitarmy/Unitarmy.h"
class Alienmonster : public Unitarmy
{
public:
	Alienmonster(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, string type = "AM");
	void print();
	bool attack();

};
inline ostream& operator<<(ostream& os, const Alienmonster& am)
{
	os << "AM ID:" << am.GetID() << endl;
}
