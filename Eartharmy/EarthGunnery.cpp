#include "EarthGunnery.h"
#include "../Game/game.h"
EarthGunnery::EarthGunnery(int id, int tj, int health, int power, int attackcap, game* gptr,string type):Unitarmy(id, tj, health, power, attackcap, type, gptr)
{
    Pri = sqrt(health* power); //combination for the priority
}
int EarthGunnery::GetPri()
{
    return Pri;
}
void EarthGunnery::attack() //Earth Gunnery Attacks Monsters randomly, Then attacks drones in pairs "If there is only 1 Drone exist, Pick it and attack"
{
 
    //Attacking Alien Monsters
    
    LinkedQueue<Unitarmy*>Temp_list;
    Unitarmy* U1;
    Unitarmy* U2;
    Unitarmy* am;
    int counter = 0;
    if (gameptr && gameptr->GetMode())
        cout << "EG " << GetID() << " shots [ ";
    for (int i = 0; i < AttackCapacity / 2; i++)
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
    while (Temp_list.dequeue(U1))
    {
        gameptr->getAlienarmy()->AddUnit(U1);
    }



    //Attacking Alien Drones

    AlienDrone* ad1 = new AlienDrone;
    AlienDrone* ad2 = new AlienDrone;
    int c = AttackCapacity;
    for (int i = AttackCapacity / 2; i < AttackCapacity;i++)
    {
        gameptr->getAlienarmy()->getAD_List().dequeue(ad1, ad2);

        if (ad1)
        {
            if (gameptr && gameptr->GetMode())
                cout << ad1->GetID() << " ,";
            ad1->SetHealth(ad1->GetHealth() - CalcDmg(ad1));
            ad1->SetTa(gameptr->getTimestep());
            if (ad1->GetHealth() == 0)
            {
                ad1->Setinfo(gameptr->getTimestep());
                gameptr->Kill(ad1);
            }
            else
                Temp_list.enqueue(ad1);
        }
        if (ad2 && (c != AttackCapacity / 2))
        {
            if (gameptr && gameptr->GetMode())
                cout << ad2->GetID() << " ,";
            ad2->SetHealth(ad2->GetHealth() - CalcDmg(ad2));
            ad2->SetTa(gameptr->getTimestep());
            if (ad2->GetHealth() == 0)
            {
                ad2->Setinfo(gameptr->getTimestep());
                gameptr->Kill(ad2);
            }
            else
                Temp_list.enqueue(ad2);
        }
    }
    if (gameptr && gameptr->GetMode())
        cout << '\b' << " ]";
    while (!Temp_list.isEmpty())
    {
        Temp_list.dequeue(U2);
        gameptr->getAlienarmy()->AddUnit(U2);
    }
    return;
}
