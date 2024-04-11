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

}