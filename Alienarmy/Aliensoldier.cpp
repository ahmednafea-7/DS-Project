#include "Aliensoldier.h"
#include"../Game/game.h"

Aliensoldier::Aliensoldier(int id, int tj, int health, int power, int attackcap, game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type, gptr)
{

}
bool Aliensoldier::IsInfected() const
{
	return false;
}
void Aliensoldier::attack()
{
	Unitarmy* U;  // used to store temp list in it
	LinkedQueue<Unitarmy*> Temp_list;
	Earthsoldier* es = new Earthsoldier; // to attack ES
	int counter = 0;
	if (gameptr && gameptr->GetMode())
		cout << "AS " << GetID() << " shots[ ";
	for (int i = 0; i < AttackCapacity; i++)
	{
		gameptr->getEartharmy()->GetESList().dequeue(es);
		if (es)
		{
			if (gameptr && gameptr->GetMode())
				cout << *es << "";
			es->SetHealth(es->GetHealth() - CalcDmg(es));
			//cout << "Health after shot" << es->GetHealth() << " Initial health = " << es->getinitialHealth() << endl; to test initial health
			es->SetTa(gameptr->getTimestep());
			if (es->GetHealth() == 0)
			{
				es->Setinfo(gameptr->getTimestep());
				if (es->IsInfected())
				{
					int y = es->GetInfCount();
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
	}
	if (gameptr && gameptr->GetMode())
		cout << '\b' << "]" <<endl;
	/* cout << endl << "---------------This is for testing------------";
	cout << endl << " Temp list:";
	Temp_list.print();
	cout << endl;
	std::cout << "---------------This is for testing------------" << endl;*/
	while (Temp_list.dequeue(U))
	{
		gameptr->getEartharmy()->AddUnit(U);
	}
	return;
}