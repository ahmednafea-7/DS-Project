#include <iostream>
#include "Game/game.h"
using namespace std;

int* Arr(int x, int y)
{
	int* A[] = { &x,&y };
	return *A+1;
}
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
	/*int x = 1, y = 2;
	int* z = Arr(x, y);
	cout <<"z = " << *z << "  z+1 = " << * (z + 1) << endl;*/
}

