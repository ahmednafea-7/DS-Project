#include "AlienDrone.h"
#include "../Game/game.h"

AlienDrone::AlienDrone(int id, int tj, int health, int power, int attackcap, game* gptr, string type):Unitarmy(id, tj, health, power, attackcap, type,gptr)
{

}
void AlienDrone::attack()
{
    return ;
}
void AlienDrone::attack(AlienDrone* ad1)
{
	int ac;
	int pri1;
	ac = ad1->AttackCapacity + AttackCapacity;
	Unitarmy* U;  // used to store temp list in it
	LinkedQueue<Unitarmy*> Temp_list;
	EarthGunnery* eg = new EarthGunnery; // to attack EG
	EarthTank* et = new EarthTank; // to attack ET
	int c = 0;
	if (gameptr && gameptr->GetMode())
		cout << "AD " << GetID() << " and " << ad1->GetID() << " attack[ ";
	//for (int i = 0; i < AttackCapacity / 2; i++)
	while (c < ac)
	{

		//1st for loop to attack ES, until half attackcapacity is reached or no more es left
		gameptr->getEartharmy()->GetETList().pop(et);
		if (et)
		{
			if (gameptr && gameptr->GetMode())
				cout << et->GetType() << *et << " ,";
			et->SetHealth(et->GetHealth() - CalcDmg(et) - ad1->CalcDmg(et));
			et->SetTa(gameptr->getTimestep());
			c++;
			if (et->GetHealth() == 0)
			{
				et->Setinfo(gameptr->getTimestep());
				gameptr->Kill(et);
			}
			else
				Temp_list.enqueue(et);
		}

		if (c == ac || (gameptr->getEartharmy()->GetEGList().isEmpty() && gameptr->getEartharmy()->GetETList().isEmpty()))
			break;

		gameptr->getEartharmy()->GetEGList().dequeue(eg, pri1);
		if (eg)
		{
			if (gameptr && gameptr->GetMode())
				cout << eg->GetID() << " ,";
			eg->SetHealth(eg->GetHealth() - CalcDmg(eg) - ad1->CalcDmg(eg));
			eg->SetTa(gameptr->getTimestep());
			c++;
			if (eg->GetHealth() == 0)
			{
				eg->Setinfo(gameptr->getTimestep());
				gameptr->Kill(eg);
			}
			else
				Temp_list.enqueue(eg);
		}
	}// 2nd for loop to attack  using the remaining attack capacity

	if (gameptr && gameptr->GetMode())
		cout << '\b' << " ]" << endl << endl;

	//cout << endl << "Testing---------" << endl << "EG Attackcapacity = " << GetAttackcapacity() << endl;
	while (Temp_list.dequeue(U)) // to empty templist
	{
		gameptr->getEartharmy()->AddUnit(U);
	}
	return;
}