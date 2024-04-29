#include <iostream>
#include "Game/game.h"

using namespace std;

int main()
{
	game g1;
	int x;
	random_device rd;
	uniform_int_distribution<int> random(1, 100);
	for (int i = 0; i < 10; i++)
		g1.Simulate();

	Unitarmy* U;
	for (int i = 0; i < 5; i++)
	{
		//U = g1.getAlienarmy()->RemoveUnit("AS", U);
		Aliensoldier* as;
		g1.getAlienarmy()->getAS_List().peek(as);
		if (as) {
		//	cout << "The health before:" << as->GetHealth() << endl;
			g1.getEartharmy()->attack();
		//	cout << "The health after:" << as->GetHealth() << endl;
			//g1.GetTemp().enqueue(as);
			cout << "Temp List after ADDITION: ";
			g1.GetTemp().print();
			cout << endl;
		}
	}
	/*for (int i = 0; i < 50; i++) {
		g1.Simulate();
		x = random(rd);		
		cout << endl << "x = " << x << endl;
		if (x > 0 && x <= 10)
		{
			cout << "Pick ES and insert it again " << endl;
			Unitarmy* E = g1.getEartharmy()->RemoveUnit("ES");
			g1.getEartharmy()->AddUnit(E);
		}
		else if (x > 10 && x <= 20)
		{
			cout << "Pick ET and move it to killed list" << endl;
			g1.Kill("ET");
		}
		else if (x > 20 && x <= 30)
		{
			cout << "Pick EG and decrement its health to half and insert it again" << endl;
			Unitarmy* U = g1.getEartharmy()->RemoveUnit("EG");
			if (U)
			{
				cout << "The health of EG ID:(" << U->GetID() << ")before:" << U->GetHealth() << endl;
				U->SetHealth((U->GetHealth()) / 2);
				cout << "The health EG ID:(" << U->GetID() << ")after:" << U->GetHealth() << endl;
				g1.getEartharmy()->AddUnit(U);
			}
			else
				cout << "EG list is empty" << endl;
		}
		else if (x > 30 && x <= 40)
		{
			cout << "Pick 5 AS , decrement their health(by 10) , move them to temp list and insert them again" << endl;
			Unitarmy* U;
			for (int i = 0; i < 5; i++)
			{
				U = g1.getAlienarmy()->RemoveUnit("AS", U);
				if (U) {
					cout << "The health before:" << U->GetHealth() << endl;
					U->SetHealth((U->GetHealth()) - 10);
					cout << "The health after:" << U->GetHealth() << endl;
					g1.GetTemp().enqueue(U);
					cout << "Temp List after ADDITION: ";
					g1.GetTemp().print(); cout << endl;
				}
			}
			for(int i = 0;i < 5;i++)
			{
				g1.GetTemp().dequeue(U);
				g1.getAlienarmy()->AddUnit(U);
			}
			cout << "Temp List After Dequeueing: ";
			g1.GetTemp().print(); cout << endl;
		}
		else if (x > 40 && x <= 50)
		{
			cout << "Pick 5 AM and insert them again " << endl;
			for (int i = 0; i < 5; i++)
			{
				Unitarmy* U = g1.getAlienarmy()->RemoveUnit("AM", U);
				g1.getAlienarmy()->AddUnit(U);
			}
		}
		else if (x > 50 && x <= 60)
		{
			cout << "Pick 6 drones from front and rear and move them to killed list" << endl;
			g1.Kill("AD");
			g1.Kill("AD");
			g1.Kill("AD");
		}
	}*/
	cout << endl;
}

