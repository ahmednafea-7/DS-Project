#pragma once
#include "../RandGen/RandGen.h"
#include "../Alienarmy/Alienarmy.h"
#include "../Eartharmy/Eartharmy.h"
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

class game
{
	Eartharmy E_Army;
	Alienarmy A_Army;
	RandGen Generator;
	LinkedQueue<Unitarmy*> Killed_list;
	LinkedQueue<Unitarmy*> Temp_list;
	int TS = 0; //Time step counter
	int N; //No. of army units generated
	int Earth_per[3];//Percentages of units for  Eartharmy in order(ES,ET,EG)
	int Alien_per[3]; // Percentages of units for alienarmy in order(AS,AM,AD)
	int Prob; // useb by randgen
	int Earth_Ranges[6],Alien_Ranges[6]; // Ranges for unit power, health , attack capacity
public:
	game();
	void Simulate();
	void Readinput();
	void SetRandgen();
	void createunit();
	//void RemoveEarthunit(string type);
	void Kill(string type); // Remove the unit from its list and add it to killed list
	Eartharmy* getEartharmy();
	Alienarmy* getAlienarmy();
	RandGen* getRandgen();
	//int* getRanges();
	int getTimestep();
	void PrintKilled();
};