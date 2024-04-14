#include "RandGen.h"
#include "../Game/game.h"
RandGen::RandGen(game* gptr)
{
	gameptr = gptr;
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
	/*int A = rand() % 100 + 1;*/
	int A = 15;
	cout << "A = " << A << endl;
	int B;
	if (A < Prob)
	{
		for (int i = 0; i < N; i++) {
			//B = rand() % 100 + 1;
			B = 95;
			int power = gen_random(E_PowerRa[0], E_PowerRa[1]);
			int Health = gen_random(E_HealthRa[0], E_HealthRa[1]);
			int Attackcap = gen_random(E_HealthRa[0], E_HealthRa[1]);
			if (B < ES)
			{
				Earthsoldier* E = new Earthsoldier(Earth_id++, 0, Health, power, Attackcap);
				gameptr->getEartharmy()->AddUnit(E);
			}
			else if (B < ES + ET)
				gameptr->getEartharmy()->AddUnit(new EarthTank(Earth_id++, 0, Health, power, Attackcap));
			else
				gameptr->getEartharmy()->AddUnit(new EarthGunnery(Earth_id++, 0, Health, power, Attackcap));


			B = 85;
			if (B < AS)
			    gameptr->getAlienarmy()->AddUnit(new Aliensoldier(Alien_id++,0,Health, power, Attackcap));
			else if (B < AS + AM)
			{
				gameptr->getAlienarmy()->AddUnit(new Alienmonster(Alien_id++, 0, Health, power, Attackcap));
			}
			else
				gameptr->getAlienarmy()->AddUnit(new AlienDrone(Alien_id++,0,Health, power, Attackcap));
		}
	}
	else 
	{
		return;
	}
	return;
}