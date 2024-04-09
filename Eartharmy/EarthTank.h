#pragma once
#include "../Stack/ArrayStack.h"
#include"../Unitarmy/Unitarmy.h"

class EarthTank:public Unitarmy
{
	int count;
	
public:
	EarthTank(int id, int tj, int health, int power, int attackcap, string type);
	void print();
	 
	bool attack();
};
inline ostream& operator<<(ostream& os,const EarthTank& et) {
	os <<"ET ID:" << et.GetID() << endl;
}