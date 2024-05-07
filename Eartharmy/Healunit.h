
#pragma once
#include<iostream>
#include"../Unitarmy/Unitarmy.h"
using namespace std;


class HealUnit :public Unitarmy
{
private:
    //int Power;    // Power of the Healing Unit (in % -> 5 == 5%)->5% is the percentage of its generation
    //int Capacity; //Attackcapacity is Number of units it can heal in a single timestep ////// no need for another capacity

public:
    HealUnit(int id = 0, int tj = 0, int health = 0, int power = 0, int attackcap = 0, game* gptr = nullptr, string type = "HU");
    //HealUnit(int power, int capacity);
    //void healUnits(Unitarmy* unitList[], int listSize);
    virtual bool IsInfected()const;

    void attack(); // heal

    ~HealUnit();
};




// fe healing list (HL) ba7ot feha el healing units (HU) LIFO       DONE
// el UML de feha el unitarmy ely a2al mn 20% w lessa mamatoosh     DONE

// scenario

// lets say en ana khalas generated                                 DONE
// el healing unit ha ttcheck lw fe haga fl UML                     
// kda lazem a3ml UML el awel                                       DONE



// Heal Unit(HU), Heal List(HL) and Unit Maintenance List(UML)
// - HU is an Earth unit(for Earth army only), that is capable of healing soldiers and fixing tanks
// - The attack capacity of HU is the number of units it can heal in a single timestep.               DONE
// - All available HUs are stored in HL as LIFO                                                       DONE
// - When a soldier's health or a tank's health is greater than 0 % and less than 20 %                
// of its initial health, it should be moved to(UML) and wait for a HU to be free to                  DONE
// act on it.Notice that a unit with health 0 (or less) should be moved directly to the
// killed list as it is already dead and couldn't be healed.                                          TEAM DIDIT
// - Each timestep, if there is a unit(or more) in UML that needs healing and If there is a
// free HU in HL :
//     -pick the HU and make it act on the units in UML by picking units from UML
//     according to HU capacity.                                                                      DONE
//     - When picking from UML, the HU gives priority to soldiers over tanks.So
//     first it heals soldiers then it heals tanks.                                                   NOT YET
//     - When picking from soldiers, the HU gives priority to soldiers with highest
//     damage(i.e lowest health).But when picking from tanks, it picks them in
//     the same order they are placed in the UML.                                                     NOT YET
//     - After picking a unit and before healing, If it has spent more than 10
//     timesteps in UML it should be moved to killed list.Otherwise, start healing.                   NOT YET (M7TAG AGHAYAR FL UNITS)
//     
//     - After healing a unit,
//         -fits health is above 20 % (of its original health), make it join the
//         battle again.                                                                              DONE
//         - Otherwise, store it in a temp list                                                       DONE
//         - Healing ends at current timestep when HU heals a number of units = its
//         capacity OR no more units to heal                                                          DONE
//         - After healing, move all units from temp list back to UML and KILL the HU.                DONE
//         - Healing improves the health of a unit U as follows :
//         health Improvement = (HUpower * HUhealth / 100) / ~/ Uhealth                               DONE BUT WHAT IS HUhealth
//         - Required Modifications(in phase2) :
//             -Modify the input file and add the percentage of HU in line 2. Notice that the         
//             percentage of HU should never exceed 5 % .                                             NOT YET
//             - Modify the random generator to generate HU according to its percentage.              NOT YET
//             - Modify the output screen to print both HL and UML                                    DONE
//             - Modify the output file and add one line showing the percentage of units that were
//             healed successfully relative to total earth units                                      NOT YET
//             - Add new class for HU and override its attack function to heal units                  DONE
//             - Add lists to represent UML and HL                                                    DONE


// msh 3arfa a handle el comma
// 3mlt generate ll HU kol marra ES yt3mlo generate
// el mafrood yb2a feh max health aw current health 3shan ageeb 20% mno
// 3ayza agrb aktr mn UML ashouf byt3mlohom hwal f nafs el timestep walla la
// 3ayeza agrb el UML feh max heals


// UML priority : lw solider: 100*health bta3to 
//                  counter l kol tank btdkhol 


// Unit army: variable TimeInUML: kol time step el unit hatb2a f uml ++ w lw wsl l 10 hayroo7 killed w lw got healed -> hayt3mlo reset
// fl attack function