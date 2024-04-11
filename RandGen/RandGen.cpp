#include "RandGen.h"
#include "../Game/game.h"
//RandGen::RandGen(game* gptr)
//{
//	gameptr = gptr;
//}

RandGen::RandGen()
{
}

void RandGen::setN_Prob(int n, int P)
{
	N = n;
	Prob = P;
}

void RandGen::setE_per(int es, int et, int eg)
{
	ES = es;
	ET = et;
	EG = eg;
}

void RandGen::setA_per(int as, int am, int ad)
{
	AS = as;
	AM = am;
	AD = ad;
}
void RandGen::setE_Ranges(int* Eranges) // Power, int* Health, int* Attackcap)
{
	for (int i = 0; i < 2; i++) {
		E_PowerRa[i] = Eranges[i];
		E_HealthRa[i] = Eranges[i+2];
		E_AttackcapRa[i] = Eranges[i+4];
	}
}
void RandGen::setA_Ranges(int* Aranges) //, int* Health, int* Attackcap)
{
	for (int i = 0; i < 2; i++) 
	{
		A_PowerRa[i] = Aranges[i];
		A_HealthRa[i] = Aranges[i+2];
		A_AttackcapRa[i] = Aranges[i+4];
	}
}

void RandGen::generateUnit()
{
	srand(time(0));
	int A = rand() % 100 + 1;
	cout << "A = " << A;
	int B;
	if (A < Prob)
	{
		for (int i = 0; i < N; i++) {
			B = rand() % 100 + 1;
			int power = gen_random(E_PowerRa[0], E_PowerRa[1]);
			int Health = gen_random(E_HealthRa[0], E_HealthRa[1]);
			int Attackcap = gen_random(E_HealthRa[0], E_HealthRa[1]);
			if (B < ES)
				gameptr->getEartharmy()->AddUnit(new Earthsoldier(Earth_id++, power, Health, Attackcap));
			else if (B < ES + ET)
				gameptr->getEartharmy()->AddUnit(new EarthTank(Earth_id++, power, Health, Attackcap));
			else
				gameptr->getEartharmy()->AddUnit(new EarthGunnery(Earth_id++, power, Health, Attackcap));
			B = rand() % 100 + 1;
			//if (B < AS)
			//	// gameptr->getEartharmy()->AddUnit(new Aliensoldier(Alien_id++, power, Health, Attackcap));
			////else if (B < AS + AM)
			//	//gameptr->getEartharmy()->AddUnit(new AlienMonster(Alien_id++, power, Health, Attackcap));
			//else
			//	gameptr->getEartharmy()->AddUnit(new AlienDrone(Alien_id++, power, Health, Attackcap));
		}
	}
	else 
	{
		return;
	}
	return;
}