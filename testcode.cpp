#include <iostream>
#include "Game/game.h"
using namespace std;

int main()
{
	game g1;
	g1.Readinput();
	g1.SetRandgen();
	/*for(int i = 0;i < 6;i++)
	cout << g1.getRanges()[i] << " " << endl;*/
	g1.createunit();
	g1.getEartharmy()->printEarth();
	g1.getAlienarmy()->PrintAlien();
	g1.PrintKilled();
	g1.Removeunit("ES");
	g1.getEartharmy()->printEarth();
	g1.PrintKilled();
	g1.Removeunit("ES");
	g1.Removeunit("ES");
	g1.getEartharmy()->printEarth();
	g1.PrintKilled();
}