#include "Earthsoldier.h"
#include "../Game/game.h"


int Earthsoldier::Infected_Count = 0;

Earthsoldier::Earthsoldier(int id, int tj, int health, int power, int attackcap, game* gptr ,string type, bool infected,bool immune):Unitarmy(id, tj, health, power, attackcap, type , gptr)
{
    Immune = immune;
    Infected = infected;
}
void Earthsoldier::SetinitialHealth(int health)
{   
    initialHealth = health;
}
int Earthsoldier::getinitialHealth()
{
    return initialHealth;
}
void Earthsoldier::SetInfected(bool infected)
{
    Infected = infected;
}
void Earthsoldier::SetImmune(bool immune)
{
    Immune = immune;
}
bool Earthsoldier::IsInfected() const
{
    return Infected;
}
bool Earthsoldier::IsImmune()
{
    return Immune;
}
void Earthsoldier::SetInfCount(int count)
{
    Infected_Count = count;
}
int Earthsoldier::GetInfCount()
{
    return Infected_Count;
}

void Earthsoldier::attack()
{
    Unitarmy* U; //  to store temp list units in it
    LinkedQueue<Unitarmy*> Temp_list; // to store units shot but not killed
    Aliensoldier* as = new Aliensoldier; // to store attacked AS 
    int counter = 0;

    if (gameptr && gameptr->GetMode())
        cout << "ES " << GetID() << " shots [ ";
    for (int i = 0; i < AttackCapacity; i++)
    {
       gameptr->getAlienarmy()->getAS_List().dequeue(as);
       if (as&&!IsInfected())
       {
           if (gameptr && gameptr->GetMode())
               cout << as->GetID() << " ,";
           as->SetHealth(as->GetHealth() - CalcDmg(as));
           as->SetTa(gameptr->getTimestep());
           if (as->GetHealth() == 0)
           {
               as->Setinfo(gameptr->getTimestep());
               gameptr->Kill(as);
           }
           else
               Temp_list.enqueue(as);
       }
    }
    if (gameptr && gameptr->GetMode())
        cout << '\b' << " ]" << endl;


   

   /* cout << endl << "---------------This is for testing------------";
    cout << endl << " Temp list:";
    Temp_list.print();
    cout << endl;
    std::cout << "---------------This is for testing------------" << endl;*/
    while (Temp_list.dequeue(U))
    {
     gameptr->getAlienarmy()->AddUnit(U);
    }

    return;
}

void Earthsoldier::InfAttack()
{
    Unitarmy* U; //  to store temp list units in it
    LinkedQueue<Unitarmy*> Temp_list; // to store units shot but not killed
    Earthsoldier* es = new Earthsoldier;
    if (gameptr && gameptr->GetMode())
        cout << "Infected ES !!" << GetID() << " shots [ ";
    for (int i = 0; i < AttackCapacity; i++)
    {
        gameptr->getEartharmy()->GetESList().dequeue(es);
        if (es)
        {
            if (gameptr && gameptr->GetMode())
                cout << es->GetID() << " ,";
            es->SetHealth(es->GetHealth() - CalcDmg(es));
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
            else
                Temp_list.enqueue(es);
        }
    }
    if (gameptr && gameptr->GetMode())
        cout << '\b' << " ]";

    while (Temp_list.dequeue(U))
    {
        gameptr->getEartharmy()->AddUnit(U);
    }

    return;
}

void Earthsoldier::setUML_Tj(int tj)
{
    UML_Tj = tj;
}
int Earthsoldier::getUML_Tj()
{
    return UML_Tj;
}