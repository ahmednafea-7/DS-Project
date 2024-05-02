#include "EarthTank.h"
#include "../Game/game.h"
EarthTank::EarthTank(int id, int tj, int health, int power, int attackcap, game* gptr, string type) :Unitarmy(id, tj, health, power, attackcap, type,gptr)
{
}

void EarthTank::attack()
{
    LinkedQueue<Unitarmy*>Temp_List;
    Unitarmy* U1;
    Unitarmy* U2;
    Unitarmy* am;

    for (int i = 0; i < AttackCapacity / 2; i++)
    {

        am = gameptr->getAlienarmy()->PickAm();
        if (am)
        {
            cout << "========= TEST ========" << "AM health Before attack: " << am->GetHealth() << endl;
            cout << "Damage is: " << CalcDmg(am) << endl;
            am->SetHealth(am->GetHealth() - CalcDmg(am));
            cout << "========= TEST ========" << "AM health After attack: " << am->GetHealth() << endl;
            if (am->GetHealth() == 0)
            {//
                gameptr->Kill(am);
            }
            else
                Temp_List.enqueue(am);
        }
    }
    cout << "Temp List after attacking AMs: ";
    if (!Temp_List.isEmpty())
        Temp_List.print();
    cout << endl;
    while (!Temp_List.isEmpty())
    {
        Temp_List.dequeue(U1);
        gameptr->getAlienarmy()->AddUnit(U1);
    }



    Aliensoldier* as = new Aliensoldier;
    for (int i = AttackCapacity/2 ; i < AttackCapacity; i++)
    {
        gameptr->getAlienarmy()->getAS_List().dequeue(as);
        if (as)
        {
            cout << "---------------This is for testing------------ as health before attacked :" << as->GetHealth() << endl;
            cout << "damage is : " << CalcDmg(as) << endl;
            as->SetHealth(as->GetHealth() - CalcDmg(as));
            cout << "---------------This is for testing------------ as health after attacked :" << as->GetHealth() << endl;
            if (as->GetHealth() == 0)
            {
                gameptr->Kill(as);
            }
            else
                Temp_List.enqueue(as);
        }
    }
    cout << "---------------This is for testing------------";
    gameptr->PrintKilled();
    cout << endl << " Temp list: ";
    Temp_List.print();
    cout << endl;
    cout << "---------------This is for testing------------" << endl;
    while (!gameptr->GetTemp().isEmpty())//gameptr->GetTemp().dequeue(U))//!gameptr->GetTemp().isEmpty())
    {
        Temp_List.dequeue(U2);
        gameptr->getAlienarmy()->AddUnit(U2);
    }

    return;
}