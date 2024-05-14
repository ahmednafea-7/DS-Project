#include"Alienmonster.h"
#include"../Game/game.h"

Alienmonster::Alienmonster(int id, int tj, int health, int power, int attackcap,game* gptr, string type,int infp) :Unitarmy(id, tj, health, power, attackcap, type, gptr)
{
	Infect_Prob = infp;
}
bool Alienmonster::IsInfected() const
{
	return false;
}
void Alienmonster::attack()
{
	Unitarmy* U;  // used to store temp list in it
	LinkedQueue<Unitarmy*> Temp_list;
	Earthsoldier* es = new Earthsoldier; // to attack ES
	EarthTank* et = new EarthTank; // to attack ET
	int c = 0;
	int y;
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
				cout<<et->GetType() << et->GetID() << " ,";
			et->SetHealth(et->GetHealth() - CalcDmg(et));
			et->SetTa(gameptr->getTimestep());
			c++;
			if (et->GetHealth() == 0)
			{
				et->Setinfo(gameptr->getTimestep());
				gameptr->Kill(et);
			}
			else if (et->GetHealth() < (0.2 * et->getinitialHealth()))
			{
				et->setUML_Tj(gameptr->getTimestep());
				gameptr->AddtoUML(et);
			}
			else
				Temp_list.enqueue(et);
		}

		if (c == AttackCapacity || (gameptr->getEartharmy()->GetESList().isEmpty() && gameptr->getEartharmy()->GetETList().isEmpty()))
			break;

		gameptr->getEartharmy()->GetESList().dequeue(es);
		if (es)
		{
			std::random_device rd;
			std::uniform_int_distribution<int> random(1, 100);
			int Rand_Inf = random(rd);

			if (gameptr && gameptr->GetMode())
				cout << *es;
			es->SetHealth(es->GetHealth() - CalcDmg(es));
			if (Rand_Inf < Infect_Prob)
			{
				if (!es->IsInfected() && !es->IsImmune())
				{
					es->addinf();
					es->SetInfected(true);
					y = es->GetInfCount();
					es->SetInfCount(++y);
				}
			}
			es->SetTa(gameptr->getTimestep());
			c++;
			if (es->GetHealth() == 0)
			{
				es->Setinfo(gameptr->getTimestep());
				if (es->IsInfected())
				{
					y = es->GetInfCount();
					es->SetInfCount(--y);
				}
				gameptr->Kill(es);
			}
			else if (es->GetHealth() < (0.2 * es->getinitialHealth()))
			{
				es->setUML_Tj(gameptr->getTimestep());
				gameptr->AddtoUML(es);
			}
			else
				Temp_list.enqueue(es);
		}
	}// 2nd for loop to attack ET using the remaining attack capacity

	if (gameptr && gameptr->GetMode())
		cout << '\b' << " ]" << endl;

	//cout << endl << "Testing---------" << endl << "EG Attackcapacity = " << GetAttackcapacity() << endl;
	while (Temp_list.dequeue(U)) // to empty templist
	{
		gameptr->getEartharmy()->AddUnit(U);
	}
	return;
}