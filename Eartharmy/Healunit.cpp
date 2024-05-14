#include "Healunit.h"
#include "../Game/game.h"

HealUnit::HealUnit(int id, int tj, int health, int power, int capacity, game* gptr, string type) :Unitarmy(id, tj, health, power, capacity, type, gptr)
{
	
}
int HealUnit::Totalhealed = 0;

int HealUnit::CalcHealing(Unitarmy* U)
{
    int Heal;
    Heal =  (GetPower() * (float(GetHealth()) / 100)) / sqrt(U->GetHealth());
    if (Heal > 15)
        Heal = 15;
    return Heal;
}

bool HealUnit::IsInfected() const
{
	return false;
}

void HealUnit::attack() // heal //***
{
    Earthsoldier* es;
    EarthTank* et;
    Unitarmy* UA;
    HealUnit* HU;
    int pri = 0;
    int capacity = 0;
    LinkedQueue<Unitarmy*>Temp_list;
    //LinkedQueue<EarthTank*>Temp_list2;
   /* LinkedQueue<Unitarmy*>& UML = gameptr->getUML_list();
    ArrayStack<HealUnit*>& HU_List = gameptr->getEartharmy()->GetHUList();*/

    //gameptr->getEartharmy()->GetHUList().peek(HU);

    if (gameptr && gameptr->GetMode())
        cout << "HU " << GetID() << " heals [ ";

    // soliders 
    while (!gameptr->getEartharmy()->GetHUList().isEmpty() && !gameptr->getUML_1().isEmpty() && capacity <= GetAttackcapacity())
    {
      
        gameptr->getUML_1().dequeue(es, pri);//Not peeking , we dequeue to heal then enqueue


        if (gameptr && gameptr->GetMode())
        cout << es->GetID() << ",";

       
        if (es) {
            if (es->IsInfected())
                es->SetHealth(es->GetHealth() + CalcHealing(es) / 2); //Heals slower (double the time of normal ES)
            else
                es->SetHealth(es->GetHealth() + CalcHealing(es));  //(GetPower() * (float(GetHealth()) / 100)) / sqrt(es->GetHealth()));

            capacity++;
            Totalhealed++;

            if (gameptr->getTimestep() - es->getUML_Tj() > 10) //dead
                gameptr->Kill(es);
            else if (es->GetHealth() <= (0.2 * es->getinitialHealth()))
                Temp_list.enqueue(es);
            else
            {
                if (es->IsInfected())
                {
                    es->SetInfected(false);
                    es->SetImmune(true);
                    int y = es->GetInfCount();
                    es->SetInfCount(--y);
                }
                    gameptr->getEartharmy()->AddUnit(es);
            }
        }

        capacity++;

        if (capacity > GetAttackcapacity() || gameptr->getUML_1().isEmpty()) {
            gameptr->getEartharmy()->GetHUList().pop(HU); //may need to be edited
            break;
        }

    }

    while (!gameptr->getEartharmy()->GetHUList().isEmpty() && !gameptr->getUML_2().isEmpty() && capacity <= GetAttackcapacity())
    {
         //Not peeking , we dequeue to heal then enqueue
        gameptr->getUML_2().dequeue(et);


         /* No need to peek another HU */
        if (gameptr && gameptr->GetMode())
        cout << et->GetID() << ",";
        if (et) {
            
            et->SetHealth(et->GetHealth() + CalcHealing(et));//(GetPower() * (float(GetHealth()) / 100)) / sqrt(et->GetHealth()));
            Totalhealed++;
            capacity++;
            //cout << "Health After healing :" << et->GetHealth() << endl; // this is for testing

            if (gameptr->getTimestep() - et->getUML_Tj() > 10) //dead
                gameptr->Kill(et);
            else if (et->GetHealth() <= (0.2 * et->getinitialHealth()))
                Temp_list.enqueue(et);
            else
                gameptr->getEartharmy()->AddUnit(et);
        }

        if (capacity > GetAttackcapacity() || (gameptr->getUML_1().isEmpty() && gameptr->getUML_2().isEmpty()))
            gameptr->getEartharmy()->GetHUList().pop(HU);

    }
    while (Temp_list.dequeue(UA))
    {
        gameptr->getEartharmy()->AddUnit(UA);
    }

    //HU_List.pop(HU);
    if (gameptr && gameptr->GetMode())
        cout << "]" << endl << endl;
}

int HealUnit::getTotalhealed()
{
    return Totalhealed;
}



HealUnit::~HealUnit()
{

}