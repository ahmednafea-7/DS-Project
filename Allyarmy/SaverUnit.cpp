#include "SaverUnit.h"
#include "../Unitarmy/Unitarmy.h"
#include "../Game/game.h"

SaverUnit::SaverUnit(int id, int tj, int health, int power, int attackcap, game* gptr, string type) : Unitarmy(id, tj, health, power, attackcap, type, gptr)
{
};
bool SaverUnit::IsInfected() const
{
    return false;
}
void SaverUnit::attack()
{

    Unitarmy* U; //  to store temp list units in it
    LinkedQueue<Unitarmy*> Temp_list; // to store units shot but not killed
    Aliensoldier* as = new Aliensoldier; // to store attacked AS 
    int counter = 0;

    if (gameptr && gameptr->GetMode())
        cout << "SU " << GetID() << " shots [ ";
    for (int i = 0; i < AttackCapacity; i++)
    {
        gameptr->getAlienarmy()->getAS_List().dequeue(as);
        if (as)
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