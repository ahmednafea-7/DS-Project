#pragma once

//#include <stdlib.h>
//#include <time.h>
#include <random>
class game;
class RandGen
{
	game* gameptr;
	int N;
	int Earth_id = 1;
	int Alien_id = 2000;
	int ES, ET, EG; // Earth units percentages
	int AS, AM, AD; // Alien units percentages
	int Prob;
	int E_PowerRa[2], E_HealthRa[2], E_AttackcapRa[2];//Ranges for earth army
	int A_PowerRa[2], A_HealthRa[2], A_AttackcapRa[2];//Ranges for Alien army
	int Timestep;
	int gen_random(int lowerb, int upperb) // to generate a random number between two bounds
	{
		std::random_device rd;
		std::uniform_int_distribution<int> random(lowerb, upperb);
		return random(rd);
	};
	int* Totalunits = new int[6]; // total units at each list in order (ES,ET,EG,AS,AM,AD)
public:
	RandGen(game* gptr);
	void setN_Prob(int n, int P);  // sets N and Prob
	void setE_per(int es, int et, int eg); // set earth units' percentages
	void setA_per(int as, int am, int ad); // set Alien units' percentages
	void setE_Ranges(int* Eranges);// Power, int* Health, int* Attackcap);
	void setA_Ranges(int* Aranges);//, int* Health, int* Attackcap);
	void generateUnit();
	int* Passtotalcounts();
	
};