#include <iostream>
#include "Game/game.h"

using namespace std;

int main()
{
	game g1;
	int x;
	for (int i = 0; i < 50; i++) {
		g1.Simulate();
		std::random_device rd;
		std::uniform_int_distribution<int> random(1, 100);
		x = random(rd);		
		cout << endl << "x = " << x << endl<<endl;
		if (x > 0 && x <= 10)
		{
			Unitarmy* E = g1.getEartharmy()->RemoveUnit("ES");
			g1.getEartharmy()->AddUnit(E);
		}
		else if (x > 10 && x <= 20)
		{
			g1.Kill("ET");
		}
		else if (x > 20 && x <= 30)
		{
			Unitarmy* U = g1.getEartharmy()->RemoveUnit("EG");
			if (U) 
			{
				cout << "The health of EG ID:(" << U->GetID() <<")before:" << U->GetHealth() << endl;
				U->SetHealth((U->GetHealth()) / 2);
				cout << "The health EG ID:(" << U->GetID() << ")after:" << U->GetHealth() << endl;
				g1.getEartharmy()->AddUnit(U);
			}
		}
		else if (x > 30 && x <= 40)
		{
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
			for (int i = 0; i < 5; i++)
			{
				Unitarmy* U = g1.getAlienarmy()->RemoveUnit("AM", U);
				g1.getAlienarmy()->AddUnit(U);
			}
		}
		else if (x > 50 && x <= 60)
		{
			g1.Kill("AD");
			g1.Kill("AD");
			g1.Kill("AD");
		}
	}
	cout << endl;
}

