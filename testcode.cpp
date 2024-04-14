#include <iostream>
#include "Game/game.h"
using namespace std;

int main()
{

	game g1;
	g1.Readinput();
	g1.SetRandgen();
	for(int i = 0;i < 6;i++)
	cout << g1.getRanges()[i] << " ";
	g1.createunit();
	g1.getEartharmy()->printEarth();
	g1.getAlienarmy()->PrintAlien();


	/*int x = rand() %100+1;*/
	int x = 25;
	if (x > 0 && x < 10)
	{
		g1.getEartharmy()->AddUnit(g1.getEartharmy()->RemoveUnit("ES"));
	}
	else if (x > 10 && x < 20)
	{
		g1.RemoveEarthunit("ET");
	}
	else if (x > 20 && x < 30)
	{
		Unitarmy* U = g1.getEartharmy()->RemoveUnit("EG");
		U->SetHealth((U->GetHealth()) / 2);
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
		g1.RemoveAlienunit("AD");
		g1.RemoveAlienunit("AD");
		g1.RemoveAlienunit("AD");
	}

	cout << endl;
	g1.getEartharmy()->printEarth();
	g1.getAlienarmy()->PrintAlien();
	g1.PrintKilled();
}