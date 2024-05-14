#pragma once
#include "../RandGen/RandGen.h"
#include "../Alienarmy/Alienarmy.h"
#include "../Eartharmy/Eartharmy.h"
#include<iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class game
{
	Eartharmy E_Army;
	Alienarmy A_Army;
	RandGen Generator;
	LinkedQueue<Unitarmy*> Killed_list;
	priQueue<Earthsoldier*> UML1;
	LinkedQueue<EarthTank*> UML2;
	int TS = 1; //Time step counter
	int N; //No. of army units generated
	int Earth_per[4];//Percentages of units for  Eartharmy in order(ES,ET,EG)
	int Alien_per[3]; // Percentages of units for alienarmy in order(AS,AM,AD)
	int Prob; // used by randgen
	int Earth_Ranges[6],Alien_Ranges[6]; // Ranges for unit power, health , attack capacity
	bool Mode = true; // True means Interactive, false means Silent mode
	void Readinput();
	void SetRandgen();
public:
	void WriteOutput();
	game();
	//char CheckUserinput();
	bool fight(); // generates units,makes the armies attack each other , print and move to next time step
	void Simulate();//it calls the Random generator then print the armies' lists and the killed list then increment timestep
	void Kill(Unitarmy* U); //add  to killed list
	Eartharmy* getEartharmy();
	Alienarmy* getAlienarmy();
	//RandGen* getRandgen();
	int getTimestep();
	void PrintKilled();
	void printUML();
	void SetMode(bool M);
	bool GetMode();
	int* GetCountofUnits();
	//void addToUML(Unitarmy* unit); //***
	priQueue<Earthsoldier*>& getUML_1(); //***
	LinkedQueue<EarthTank*>& getUML_2(); //***
	bool AddtoUML(Unitarmy* U);

};