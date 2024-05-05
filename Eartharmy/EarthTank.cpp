#include "EarthTank.h"
#include "../Game/game.h"
EarthTank::EarthTank(int id, int tj, int health, int power, int attackcap, game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type,gptr)
{

}
bool EarthTank::Cond = false;  

void EarthTank::SetinitialHealth(int health)
{
    initialHealth = health;
}
int EarthTank::getinitialHealth()
{
    return initialHealth;
}
void EarthTank::attack()
{
    int c = 0; // represents number of units attacked untill reaches capacity
    int EScount = gameptr->getEartharmy()->GetESList().GetCount();
    int AScount = gameptr->getAlienarmy()->getAS_List().GetCount();
    LinkedQueue<Unitarmy*>Temp_list;
    Unitarmy* U;
    Alienmonster* am = new Alienmonster;
    Aliensoldier* as = new Aliensoldier;
    
    if (gameptr && gameptr->GetMode())
        cout << "ET " << GetID() << " shots [ ";
        /*for (int i = 0; i < AttackCapacity / 2; i++)
        {
           am = gameptr->getAlienarmy()->PickAm();
            if (am)
            {
                if (gameptr && gameptr->GetMode())
                    cout << am->GetID() << " ,";
                am->SetHealth(am->GetHealth() - CalcDmg(am));
                c++;
                am->SetTa(gameptr->getTimestep());
                if (am->GetHealth() == 0)
                {
                    am->Setinfo(gameptr->getTimestep());
                    gameptr->Kill(am);
                }
                else
                    Temp_list.enqueue(am);
            }
        }*/
        if (EScount <= 0.3 * AScount)
            Cond = true;
        else if (EScount >= 0.8 * AScount)
            Cond = false;
        if (Cond)
        {
            for (int i = 0; i < AttackCapacity/2; i++)
            {
                if (EScount >= 0.8 * AScount)
                {
                    c = i; // will be removed (probably)
                    Cond = false;
                    break;
                }
                gameptr->getAlienarmy()->getAS_List().dequeue(as);
                if (as)
                {
                    if (gameptr && gameptr->GetMode())
                        cout << as->GetID() << " ,";
                    as->SetHealth(as->GetHealth() - CalcDmg(as));
                    c++;
                    as->SetTa(gameptr->getTimestep());
                    if (as->GetHealth() == 0) {
                        as->Setinfo(gameptr->getTimestep());
                        gameptr->Kill(as);
                    }
                    else
                        Temp_list.enqueue(as);
                }

            }
        }
    for (int i = c; i < AttackCapacity; i++)
    {
        am = gameptr->getAlienarmy()->PickAm();
        if (am)
        {
            if (gameptr && gameptr->GetMode())
                cout << am->GetID() << " ,";
            am->SetHealth(am->GetHealth() - CalcDmg(am));
            am->SetTa(gameptr->getTimestep());
            if (am->GetHealth() == 0)
            {
                am->Setinfo(gameptr->getTimestep());
                gameptr->Kill(am);
            }
            else
                Temp_list.enqueue(am);
        }
    }

    if (gameptr && gameptr->GetMode())
        cout << '\b' << " ]";
    while (Temp_list.dequeue(U))
    {
        gameptr->getAlienarmy()->AddUnit(U);
    }
    return;
}


// if (es<0.3 as)
//     tank attack as & monsters
//         if(es>0.8 as)
//            break;
// else
// tank attack monsters 