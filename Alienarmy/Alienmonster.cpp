#include"Alienmonster.h"
#include"../Game/game.h"

Alienmonster::Alienmonster(int id, int tj, int health, int power, int attackcap,game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type, gptr)
{

}
void Alienmonster::attack()
{
	Unitarmy* U;  // used to store temp list in it
	LinkedQueue<Unitarmy*> Temp_list;
	Earthsoldier* es = new Earthsoldier; // to attack ES
	EarthTank* et = new EarthTank; // to attack ET
	int c = 0;
	if (gameptr && gameptr->GetMode())
		cout << "AM " << GetID() << " attacks [ ";
	//for (int i = 0; i < AttackCapacity / 2; i++)
	while (c < AttackCapacity)
	{
		
		//1st for loop to attack ES, until half attackcapacity is reached or no more es left
		gameptr->getEartharmy()->GetETList().pop(et);
		if (et)
		{
			if (gameptr && gameptr->GetMode())
				cout << et->GetID() << " ,";
			et->SetHealth(et->GetHealth() - CalcDmg(et));
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

		if (c == AttackCapacity || (gameptr->getEartharmy()->GetESList().isEmpty() && gameptr->getEartharmy()->GetETList().isEmpty()))
			break;

		gameptr->getEartharmy()->GetESList().dequeue(es);
		if (es)
		{
			if (gameptr && gameptr->GetMode())
				cout << es->GetID() << " ,";
			es->SetHealth(es->GetHealth() - CalcDmg(es));
			es->SetTa(gameptr->getTimestep());
			c++;
			if (es->GetHealth() == 0)
			{
				es->Setinfo(gameptr->getTimestep());
				gameptr->Kill(es);
			}
			else
				Temp_list.enqueue(es);
		}
	}// 2nd for loop to attack ET using the remaining attack capacity

	if (gameptr && gameptr->GetMode())
		cout << '\b' << " ]";

	//cout << endl << "Testing---------" << endl << "EG Attackcapacity = " << GetAttackcapacity() << endl;
	while (Temp_list.dequeue(U)) // to empty templist
	{
		gameptr->getEartharmy()->AddUnit(U);
	}
	return;
}