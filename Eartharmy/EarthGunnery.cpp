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
bool EarthGunnery::IsInfected() const
{
    return false;
}
void EarthGunnery::attack() //Earth Gunnery Attacks Monsters randomly, Then attacks drones in pairs "If there is only 1 Drone exist, Pick it and attack"
{
    //Attacking Alien Monsters
    LinkedQueue<Unitarmy*>Temp_list;
    Unitarmy* U;
    Alienmonster* am;
    AlienDrone* ad1 = new AlienDrone;
    AlienDrone* ad2 = new AlienDrone;

    if (gameptr && gameptr->GetMode())
        cout << "EG " << GetID() << " shots [ ";

    int c = 0;

    while (c < AttackCapacity)
    {
        if (c == AttackCapacity || (gameptr->getAlienarmy()->GetAmCount() == 0 && gameptr->getAlienarmy()->getAD_List().isEmpty()))
            break;
        // for (int i = 0; i < AttackCapacity / 2; i++)
         //{
        am = gameptr->getAlienarmy()->PickAm();
        if (am)
        {
            if (gameptr && gameptr->GetMode())
                cout<<am->GetType() << am->GetID() << " ,";
            am->SetHealth(am->GetHealth() - CalcDmg(am));
            am->SetTa(gameptr->getTimestep());
            c++;
            if (am->GetHealth() == 0)
            {
                am->Setinfo(gameptr->getTimestep());
                gameptr->Kill(am);
            }
            else
                Temp_list.enqueue(am);
        }
        // }
        if (c == AttackCapacity || (gameptr->getAlienarmy()->GetAmCount() == 0 && gameptr->getAlienarmy()->getAD_List().isEmpty()))
            break;

        //Attacking Alien Drones

        //for (int i = c; i < AttackCapacity; i++)
        //{
            gameptr->getAlienarmy()->getAD_List().dequeue(ad1, ad2);

            if (ad1 && c+1 < AttackCapacity)
            {
                if (gameptr && gameptr->GetMode())
                    cout<<ad1->GetType() << ad1->GetID() << " ,";
                ad1->SetHealth(ad1->GetHealth() - CalcDmg(ad1));
                c++;
                ad1->SetTa(gameptr->getTimestep());
                if (ad1->GetHealth() == 0)
                {
                    ad1->Setinfo(gameptr->getTimestep());
                    gameptr->Kill(ad1);
                }
                else
                    Temp_list.enqueue(ad1);
            }
            if (ad2 && (c != AttackCapacity))
            {
                if (gameptr && gameptr->GetMode())
                    cout<<ad2->GetType() << ad2->GetID() << " ,";
                ad2->SetHealth(ad2->GetHealth() - CalcDmg(ad2));
                c++;
                ad2->SetTa(gameptr->getTimestep());
                if (ad2->GetHealth() == 0)
                {
                    ad2->Setinfo(gameptr->getTimestep());
                    gameptr->Kill(ad2);
                }
                else
                    Temp_list.enqueue(ad2);
            }
        //}//
    }

    if (gameptr && gameptr->GetMode())
        cout << '\b' << " ]" << endl;

    //cout << endl << "Testing---------" << endl << "EG Attackcapacity = " << GetAttackcapacity() << endl;
    while (Temp_list.dequeue(U))
    {
        gameptr->getAlienarmy()->AddUnit(U);
    }
    return;
}//
