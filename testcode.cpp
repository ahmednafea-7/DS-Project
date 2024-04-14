#include <iostream>
#include "Game/game.h"
using namespace std;

int main()
{

	game g1;
	for (int i = 0;i < 6;i++)
	{
		g1.Simulate();
		Earthsoldier* a{};
		//int x = rand() % 100 + 1;
		int x = 5;
		cout<<endl<< "Current X is: " << x << endl;
		//int x = 5;
		if (x > 0 && x < 10)
		{
			Unitarmy* ES = g1.getEartharmy()->RemoveUnit("ES");
			if (!ES)
				return 0;

			g1.getEartharmy()->AddUnit(ES);
		}
		else if (x >= 10 && x < 20)
		{
			g1.Kill("ET");
		}
		else if (x >= 20 && x < 30)
		{
			Unitarmy* U = g1.getEartharmy()->RemoveUnit("EG");
			if (!U)
				return 0;

			cout << "The health before:" << U->GetHealth() << endl;
			U->SetHealth((U->GetHealth()) / 2);
			cout << "The health after:" << U->GetHealth();
			g1.getEartharmy()->AddUnit(U);
		}
		else if (x >= 30 && x < 40)
		{
			for (int i = 0;i < 5;i++)
			{
				Unitarmy* U;
				g1.getAlienarmy()->RemoveUnit("AS", U);
			}
		}
		else if (x >= 40 && x < 50)
		{
			for (int i = 0;i < 5;i++)
			{
				Unitarmy* U;
				g1.getAlienarmy()->RemoveUnit("AM", U);
				g1.getAlienarmy()->AddUnit(U);
			}

		}
		else if (x >= 50 && x < 60)
		{
			g1.Kill("AD");
			g1.Kill("AD");
			g1.Kill("AD");
		}

		cout<< endl << "<<<<At End Of TimeStep" << g1.getTimestep() <<">>>>" << endl;
		g1.getEartharmy()->printEarth();
		g1.getAlienarmy()->PrintAlien();
		cout << endl;
	}
}

