#include "Earthsoldier.h"
#include "../Game/game.h"

Earthsoldier::Earthsoldier(int id, int tj, int health, int power, int attackcap, game* gptr ,string type):Unitarmy(id, tj, health, power, attackcap, type , gptr)
{
    
}
bool Earthsoldier::attack()
{
    Unitarmy* U;
    Aliensoldier* as = new Aliensoldier;
    for (int i = 0; i < AttackCapacity; i++)
    {
      // as = dynamic_cast<Aliensoldier*>(gameptr->getAlienarmy()->getAS_List().dequeue(as));
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
               gameptr->GetTemp().enqueue(as);
       }
    }
    cout << "---------------This is for testing------------";
    gameptr->PrintKilled();
    cout << " Temp list:" << endl;
    gameptr->GetTemp().print();
    cout << endl;
    cout << "---------------This is for testing------------"<<endl;
    while (!gameptr->GetTemp().isEmpty())//gameptr->GetTemp().dequeue(U))//!gameptr->GetTemp().isEmpty())
    {
     gameptr->GetTemp().dequeue(U);
     gameptr->getAlienarmy()->AddUnit(U);
    }

    return false;
}