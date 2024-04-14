#include "game.h"

game::game():Generator(this)
{
	Readinput();
	SetRandgen();
}

void game::Simulate()
{
	cout << " ====================Current Timestep " << TS << "====================" << endl;
	Generator.generateUnit();
	getEartharmy()->printEarth();
	getAlienarmy()->PrintAlien();
	PrintKilled();
	TS++;
}

void game::Readinput()
{
	ifstream myfile("inputfile.txt");
	if (myfile.is_open())
	{
		myfile >> N;
		myfile >> Earth_per[0];
		myfile >> Earth_per[1];
		myfile >> Earth_per[2];
		myfile >> Alien_per[0];
		myfile >> Alien_per[1];
		myfile >> Alien_per[2];
		myfile >> Prob;
		myfile >> Earth_Ranges[0];
		myfile.ignore();
		myfile >> Earth_Ranges[1];
		myfile >> Earth_Ranges[2];
		myfile.ignore();
		myfile >> Earth_Ranges[3];
		myfile >> Earth_Ranges[4];
		myfile.ignore();
		myfile >> Earth_Ranges[5];
		myfile >> Alien_Ranges[0];
		myfile.ignore();
		myfile >> Alien_Ranges[1];
		myfile >> Alien_Ranges[2];
		myfile.ignore();
		myfile >> Alien_Ranges[3];
		myfile >> Alien_Ranges[4];
		myfile.ignore();
		myfile >> Alien_Ranges[5];

	}
}
void game::SetRandgen()
{
	Generator.setN_Prob(N, Prob);
	Generator.setE_per(Earth_per[0], Earth_per[1], Earth_per[2]);
	Generator.setA_per(Alien_per[0], Alien_per[1], Alien_per[2]);
	Generator.setA_Ranges(Alien_Ranges);
	Generator.setE_Ranges(Earth_Ranges);
}

void game::Kill(string type)
{
	Unitarmy* U = nullptr;
	if (type == "AD")
	{
		Killed_list.enqueue(getAlienarmy()->RemoveUnit(type,U));
		Killed_list.enqueue(U);
		return;
	}
	else if(type == "AS" || type == "AM")
	Killed_list.enqueue(getAlienarmy()->RemoveUnit(type,U));
	else if(type == "ES" || type == "EG" || type == "ET")
	Killed_list.enqueue(getEartharmy()->RemoveUnit(type));
}
Eartharmy* game::getEartharmy()
{
	return &E_Army;
}
Alienarmy* game::getAlienarmy()
{
	return &A_Army;
}

RandGen* game::getRandgen()
{
	return &Generator;
}

//int* game::getRanges() // to test
//{
//	return Earth_Ranges;
//}

int game::getTimestep()
{
	return TS;
}

void game::PrintKilled()
{
	cout<<Killed_list.GetCount() << " Killed units ";
	Killed_list.print();
}

