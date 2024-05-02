#include "Earthsoldier.h"
#include "../Game/game.h"

Earthsoldier::Earthsoldier(int id, int tj, int health, int power, int attackcap, game* gptr ,string type):Unitarmy(id, tj, health, power, attackcap, type , gptr)
{

}
void Earthsoldier::attack()
{
    Unitarmy* U; // to to store temp list units in it
    LinkedQueue<Unitarmy*> Temp_list; // to store units shot but not killed
    Aliensoldier* as = new Aliensoldier; // to store attacked AS 
    //int* Killed_Ids = new int[AttackCapacity];
    int counter = 0;
    if (gameptr && gameptr->GetMode())
        cout << "ES " << GetID() << " shots [ ";
    for (int i = 0; i < AttackCapacity; i++)
    {
      // as = dynamic_cast<Aliensoldier*>(gameptr->getAlienarmy()->getAS_List().dequeue(as));
        gameptr->getAlienarmy()->getAS_List().dequeue(as);
        //as = dynamic_cast<Aliensoldier*>(gameptr->getAlienarmy()->RemoveUnit("AS", U));
      //  LinkedQueue<Aliensoldier*> list = gameptr->getAlienarmy()->getAS_List();
       if (as)
       {
           if (gameptr && gameptr->GetMode())
               cout << as->GetID() << " ,";
          /*cout << "---------------This is for testing------------ as" << as->GetID() << "health before attacked : " << as->GetHealth() << endl;
           cout << "damage is : " << CalcDmg(as) << endl;*/
           as->SetHealth(as->GetHealth() - CalcDmg(as));
           as->SetTa(gameptr->getTimestep());
         //  cout << "---------------This is for testing------------ as" << as->GetID() << " health after attacked :" << as->GetHealth() << endl;
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
    cout << '\b' << " ]";
    //printing 
  /*  cout << "ES " << GetID() << " shots";
    Temp_list.print();
    cout << '\b';
    if (counter != 0) {
        for (int i = 0; i < counter; i++)
        {
            cout << Killed_Ids[i] << " , ";
        }
    }*/
    cout << endl << "---------------This is for testing------------";
    //gameptr->PrintKilled();
    cout << endl << " Temp list:";
    Temp_list.print();
    cout << endl;
    std::cout << "---------------This is for testing------------" << endl;
    while (Temp_list.dequeue(U))
    {
     //Temp_list.dequeue(U);
     gameptr->getAlienarmy()->AddUnit(U);
    }

    return;
}