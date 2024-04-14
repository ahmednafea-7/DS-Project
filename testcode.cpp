#include <iostream>
#include "Game/game.h"
using namespace std;

int main()
{

	game g1;
	/*for(int i = 0;i < 6;i++)
	cout << g1.getRanges()[i] << " ";*/
	g1.Simulate();
	Earthsoldier* a{};
//	cout << "testing the getters of unit army : " << a->GetHealth() << a->GetType();
	/*int x = rand() %100+1;*/
	int x = 5;
	if (x > 0 && x < 10)
	{
		g1.getEartharmy()->AddUnit(g1.getEartharmy()->RemoveUnit("ES"));
	}
	else if (x > 10 && x < 20)
	{
		g1.Kill("ET");
	}
	else if (x > 20 && x < 30)
	{
		//g1.getEartharmy()->printEarth();
		Unitarmy* U = g1.getEartharmy()->RemoveUnit("EG");
		cout << "The health before:" << U->GetHealth()<<endl;
		U->SetHealth((U->GetHealth()) / 2);
		cout << "The health after:" << U->GetHealth();
		g1.getEartharmy()->AddUnit(U);
	}
	else if (x > 30 && x < 40)
	{

	}
	else if (x > 40 && x < 50)
	{
		for (int i = 0;i < 5;i++)
		{
			Unitarmy* U;
			g1.getAlienarmy()->RemoveUnit("AM", U);
		}

	}
	else if (x > 50 && x < 60)
	{
		g1.Kill("AD");
		g1.Kill("AD");
		g1.Kill("AD");
	}

	cout << endl;
	//g1.Simulate();
}

