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
void RandGen::setE_Ranges(int* Eranges) // Eranges is the ranges for health,power,attcap for Eartharmy
{
	for (int i = 0; i < 2; i++) {
		E_PowerRa[i] = Eranges[i];
		E_HealthRa[i] = Eranges[i+2];
		E_AttackcapRa[i] = Eranges[i+4];
	}
}
void RandGen::setA_Ranges(int* Aranges) // Aranges is the ranges for health,power,attcap for Eartharmy
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
	
	std::random_device rd;
	std::uniform_int_distribution<int> random(1, 100);
	int A = random(rd); // for Eartharmy
	int A2 = random(rd); // for the Alienarmy
	int B;
	int power;
	int Health;
	int Attackcap;
	if (A < Prob)
	{
		for (int i = 0; i < N; i++) {
			power = gen_random(E_PowerRa[0], E_PowerRa[1]);
			Health = gen_random(E_HealthRa[0], E_HealthRa[1]);
			Attackcap = gen_random(E_AttackcapRa[0], E_AttackcapRa[1]);
			B = random(rd);// the time joined given to units is the time step they were added to the list
			if (B < ES) // as there is no battle logic in this phase
				gameptr->getEartharmy()->AddUnit(new Earthsoldier(Earth_id++, gameptr->getTimestep(), Health, power, Attackcap,gameptr));
			else if (B < ES + ET)
				gameptr->getEartharmy()->AddUnit(new EarthTank(Earth_id++, gameptr->getTimestep(), Health, power, Attackcap, gameptr));
			else
				gameptr->getEartharmy()->AddUnit(new EarthGunnery(Earth_id++, gameptr->getTimestep(), Health, power, Attackcap , gameptr));
		}
	}
	if (A2 < Prob) {
	for (int i = 0; i < N; i++)
	{
		power = gen_random(A_PowerRa[0], A_PowerRa[1]);// Ranges for Aliens
		Health = gen_random(A_HealthRa[0], A_HealthRa[1]);
		Attackcap = gen_random(A_AttackcapRa[0], A_AttackcapRa[1]);
		B = random(rd);
			if (B < AS)
				gameptr->getAlienarmy()->AddUnit(new Aliensoldier(Alien_id++, gameptr->getTimestep(), Health, power, Attackcap , gameptr));
			else if (B < AS + AM)
				gameptr->getAlienarmy()->AddUnit(new Alienmonster(Alien_id++, gameptr->getTimestep(), Health, power, Attackcap));
			else
				gameptr->getAlienarmy()->AddUnit(new AlienDrone(Alien_id++, gameptr->getTimestep(), Health, power, Attackcap));
		}

	}
	return;
}