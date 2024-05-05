#include "../Eartharmy/Healunit.h"
#include "../Game/game.h"

HealUnit::HealUnit(int id, int tj, int health, int power, int capacity, game* gptr, string type) :Unitarmy(id, tj, health, power, capacity, type, gptr)
{
	
}

void HealUnit::attack() // heal //***
{
//    Unitarmy* UA;
//    HealUnit* HU;
//    int capacity = 0;
//    LinkedQueue<Unitarmy*>Temp_list;
//    LinkedQueue<Unitarmy*>& UML = gameptr->getUML_list();
//    ArrayStack<HealUnit*>& HU_List = gameptr->getEartharmy()->GetHUList();
//
//    HU_List.peek(HU);
//
//    if (gameptr && gameptr->GetMode())
//        cout << "HU " << HU->GetID() << " heals [ ";
//
//    while (!HU_List.isEmpty() && !UML.isEmpty())
//    {
//        UML.peek(UA);
//        //HU_List.peek(HU);
//
//        //(HUpower* HUhealth / 100) / ~/ Uhealth
//
//        //if (gameptr && gameptr->GetMode())
//        cout << UA->GetID() << " ";
//
//        Earthsoldier* es = dynamic_cast<Earthsoldier*>(UA);
//        if (es) {
//            es->SetHealth((HU->getPower() * (HU->getPower() / 100)) / sqrt(es->GetHealth()));
//            //gameptr->getEartharmy()->AddUnit(es);
//        }
//        if (es->GetHealth() <= 20)
//            Temp_list.enqueue(UA);
//        else
//            gameptr->getEartharmy()->AddUnit(es);
//
//
//        EarthTank* et = dynamic_cast<EarthTank*>(UA);
//        if (et) {
//            et->SetHealth((HU->getPower() * (HU->getPower() / 100)) / sqrt(et->GetHealth()));
//            //gameptr->getEartharmy()->AddUnit(et);
//        }
//        if (et->GetHealth() <= 20)
//            Temp_list.enqueue(UA);
//        else
//            gameptr->getEartharmy()->AddUnit(et);
//
//        EarthGunnery* eg = dynamic_cast<EarthGunnery*>(UA);
//        if (eg) {
//            eg->SetHealth((HU->getPower() * (HU->getPower() / 100)) / sqrt(eg->GetHealth()));
//            //gameptr->getEartharmy()->AddUnit(eg);
//        }
//        if (eg->GetHealth() <= 20)
//            Temp_list.enqueue(UA);
//        else
//            gameptr->getEartharmy()->AddUnit(eg);
//
//
//        UML.dequeue(UA);
//
//        capacity++;
//        if (capacity > HU->getCapacity() || UML.isEmpty())
//            HU_List.pop(HU);
//    }
//    while (Temp_list.dequeue(UA))
//    {
//        gameptr->getEartharmy()->AddUnit(UA);
//    }
//    //HU_List.pop(HU);
//    if (gameptr && gameptr->GetMode())
//        cout << "]" << endl;
}





HealUnit::~HealUnit()
{

}