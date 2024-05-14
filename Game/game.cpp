#include "game.h"
#include "stdlib.h"
#include "windows.h"
game::game():Generator(this)
{
	Readinput();
	SetRandgen();
	//WriteOutput();
}

//char game::CheckUserinput()
//{
//	std::cout << "Press any key to move to next timestep(f to finish the battle): ";
//	/*std::cin >> key;
//	return key;*/
//	char key;
//	//if (_kbhit())
//	//{ // Check if a key is pressed
//	//	key = _getch(); // Get the pressed key
//	//	std::cout << "\nKey pressed: " << key << std::endl;
//	//	return key;
//	//}
//	//char key;
//	//std::cout << "Press Enter key to continue: ";
//
//	//// Wait for the Enter key to be pressed
//	while (true) {
//		std::cin.get(key);
//		if(key == 'f')
//		{
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'f'); // Clear input buffer
//			return 'f';
//			break;
//		}
//		if (key == '\n') {
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
//			return key;
//			break;
//		}
//	}
//}

bool game::fight()
{
	if (GetMode())
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<< Current Timestep " << TS << " >>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	Generator.generateUnit();
	if (GetMode())
	{
		getEartharmy()->printEarth();
		getAlienarmy()->PrintAlien();
	}
	if (GetMode())
	cout << "=========== Units Attacking at Current Timestep ===========" << endl;
	getEartharmy()->attack();
	if (TS > 40 && getAlienarmy()->isDefeated())
	{
		if (GetMode())
		{
			printUML();
			PrintKilled();
			cout << endl << endl;
			cout << endl << "Earth army wins !";
		}
		return false;
	}
	getAlienarmy()->attack();
	if (TS > 40 && getEartharmy()->isDefeated())
	{
		if (GetMode())
		{
			printUML();
			PrintKilled();
			cout << endl << endl;
			cout << endl << "Alien army wins !";
		}
		return false;
	}
	if (TS > 500)
	{
		if (GetMode())
		{
			printUML();
			PrintKilled();
			cout << endl << endl;
		}
		if (getEartharmy()->getTotalUnits() > getAlienarmy()->getTotalUnits() && GetMode())
			cout << endl << "Earth army has more alive units, if battle continues it will win";
		else if(GetMode())
			cout << endl << "Alien army has more alive units, if battle continues it will win";

		return false;
	}
	if (GetMode())
	{
		printUML();
		PrintKilled();
		cout << endl << endl;
	}
	SU_check();
	TS++;
	//cin.get();
	return true;
}

void game::Simulate()
{
	cout << "Enter 'Y' for Interactive mode and 'N' for silent mode" << endl;
	char interactive;
	cin.get(interactive);
	if (interactive == 'Y' || interactive == 'y')
		Mode = true;
	else if (interactive == 'N' || interactive == 'n')
		Mode = false;

	if(!GetMode())
	{
		while(fight())
		{
		}
		//system("cls");
		cout << "Silent Mode" << endl << "Simulation starts";
		for (int i = 0; i < 3; i++) {
			Sleep(500);
			cout << ".";
		}
		cout << endl;
		WriteOutput();
		cout << "Simulation ends,Outputfile is created" << endl;
		return;
	}
	bool finished;
	for (int i = 0; i < 40; i++) {
		finished = fight();
	}
	char key;
	while (finished)
	{
		finished = fight();
		if (!finished)
			break;
		cout << "Press Enter key to move to next timestep(f to finish the battle): ";
		cin.get(key);
		cout << endl;
		if (key == 'f')
		{
			while (true)
			{
				if (!finished) {
					cout << endl;
					break;
				}
				finished = fight();
			}
		}
	}
	WriteOutput();
}

void game::Readinput()
{
	/*ifstream myfile;
	cout << "Enter the simulation mode you want: ";
		int mode;
		cin >> mode;
		switch(mode) {
		case 1:
			myfile.open("inputfile.txt");
			break;
		case 2:
			myfile.open("inputfile1.txt");
			break;
		};*/
	ifstream myfile("inputfile.txt");
	if (myfile.is_open())
	{
		myfile >> N;
		myfile >> Earth_per[0];
		myfile >> Earth_per[1];
		myfile >> Earth_per[2];
		myfile >> Earth_per[3];
		//myfile >> Earth_per[4];
		myfile >> Alien_per[0];
		myfile >> Alien_per[1];
		myfile >> Alien_per[2];
		myfile >> Prob;
		myfile >> Infect_Prob;
		myfile >> Infect_threshold;
		myfile >> Earth_Ranges[0];
		myfile.ignore(); // to ignore the -
		myfile >> Earth_Ranges[1];
		myfile >> Earth_Ranges[2];
		myfile.ignore();
		myfile >> Earth_Ranges[3];
		myfile >> Earth_Ranges[4];
		myfile.ignore();
		myfile >> Earth_Ranges[5];
		myfile >> Alien_Ranges[0];
		myfile.ignore();
		myfile >> Alien_Ranges[1];
		myfile >> Alien_Ranges[2];
		myfile.ignore();
		myfile >> Alien_Ranges[3];
		myfile >> Alien_Ranges[4];
		myfile.ignore();
		myfile >> Alien_Ranges[5];

	}
}
void game::SetRandgen()
{
	Generator.setN_Prob(N, Prob,Infect_Prob,Infect_threshold);
	Generator.setE_per(Earth_per[0], Earth_per[1], Earth_per[2], Earth_per[3]);
	Generator.setA_per(Alien_per[0], Alien_per[1], Alien_per[2]);
	Generator.setA_Ranges(Alien_Ranges);
	Generator.setE_Ranges(Earth_Ranges);
}

void game::WriteOutput()
{
	ofstream Output("Outputfile.txt");
	if(Output.is_open())
	{
		int Sumearth = GetCountofUnits()[0] + GetCountofUnits()[1] + GetCountofUnits()[2];
		int SumAlien = GetCountofUnits()[3] + GetCountofUnits()[4] + GetCountofUnits()[5];
		float DfEarth_avg = 0,DdEarth_avg = 0,DbEarth_avg = 0;
		float DfAlien_avg = 0, DdAlien_avg = 0, DbAlien_avg = 0;
		int EarthKilledSum[3] = { 0,0,0 };// Total killed ES,ET,EG
		int AlienKilledSum[3] = { 0,0,0 }; //Total killed AS,AM,AD
		Unitarmy* U;
		if (getAlienarmy()->isDefeated())
			Output << "Earth Army wins!";
		else if(getEartharmy()->isDefeated())
			Output << "Alien Army wins!";
		else if (getEartharmy()->getTotalUnits() > getAlienarmy()->getTotalUnits())
			Output << "Earth army has more alive units, if battle continues,probably it will win";
		else
			Output << "Alien army has more alive units, if battle continues,probably it will win";
		Output << endl;
		while(Killed_list.dequeue(U))
		{
			if (U->GetID() < 1000) {
				DfEarth_avg += U->GetDf();
				DdEarth_avg += U->GetDd();
				DbEarth_avg += U->GetDb();
				if (U->GetType() == "ES")
					EarthKilledSum[0]++;
				else if (U->GetType() == "ET")
					EarthKilledSum[1]++;
				else
					EarthKilledSum[2]++;
			}
			else {
				DfAlien_avg += U->GetDf();
				DdAlien_avg += U->GetDd();
				DbAlien_avg += U->GetDb();
				if (U->GetType() == "AS")
					AlienKilledSum[0]++;
				else if (U->GetType() == "AM")
					AlienKilledSum[1]++;
				else
					AlienKilledSum[2]++;
			}
			Output << "Td\tID\tTj\tDf\tDd\tDb" << endl;
			Output << U->GetTd() << "\t";
			Output << U->GetID() << "\t";
			Output << U->GetTj() << "\t";
			Output << U->GetDf() << "\t";
			Output << U->GetDd() << "\t";
			Output << U->GetDb() << "\t" << endl;
		}
		DfEarth_avg /= (EarthKilledSum[0] + EarthKilledSum[1] + EarthKilledSum[2]);
		DdEarth_avg /= (EarthKilledSum[0] + EarthKilledSum[1] + EarthKilledSum[2]);
		DbEarth_avg /= (EarthKilledSum[0] + EarthKilledSum[1] + EarthKilledSum[2]);

		DfAlien_avg /= (AlienKilledSum[0] + AlienKilledSum[1] + AlienKilledSum[2]);
		DdAlien_avg /= (AlienKilledSum[0] + AlienKilledSum[1] + AlienKilledSum[2]);
		DbAlien_avg /= (AlienKilledSum[0] + AlienKilledSum[1] + AlienKilledSum[2]);

		// Output << "Earth army wins" << endl;
		Output << "Earth army statistics:- " << endl;
		Output << "ES total units generated: " << GetCountofUnits()[0] << endl;
		Output << "ET total units generated: " << GetCountofUnits()[1] << endl;
		Output << "EG total units generated: " << GetCountofUnits()[2] << endl;
		Output << "Percentages of destructed to total units " << endl;
		Output << "for ES: " << 100 * (float)EarthKilledSum[0] / (float)GetCountofUnits()[0] << "%" << endl;
		Output << "for ET: " << 100 * (float)EarthKilledSum[1] / (float)GetCountofUnits()[1] << "%" << endl;
		Output << "for EG: " << 100 * (float)EarthKilledSum[2] / (float)GetCountofUnits()[2] << "%" << endl;
		Output << "Percentages of total units healed: " << 100 * (float(HealUnit::getTotalhealed()) / getEartharmy()->getTotalUnits()) << "%" << endl;
		Output << "Percentages of total infected ES to total generated: " << 100 * (float(Earthsoldier::Gettotalinf()) / (GetCountofUnits()[0])) << "%" << endl;
		Output << "Df Earth average: " << DfEarth_avg << endl;
		Output << "Dd Earth average: " << DdEarth_avg << endl;
		Output << "Db Earth average: " << DbEarth_avg << endl;
		Output << "Df/Db % = " << (DfEarth_avg / DbEarth_avg) * 100 << "%";
		Output << "--- Dd/Db % = " << (DdEarth_avg / DbEarth_avg) * 100 << "%" << endl;
		// continue with other stats
		Output << "Alien army statistics:- " << endl;
		Output << "AS total units generated: " << GetCountofUnits()[3] << endl;
		Output << "AM total units generated: " << GetCountofUnits()[4] << endl;
		Output << "AD total units generated: " << GetCountofUnits()[5] << endl;
		Output << "Percentages of destructed to total units" << endl;
		Output << "for AS: " << 100 * (float)AlienKilledSum[0] / (float)GetCountofUnits()[3] << "%" << endl;
		Output << "for AM: " << 100 * (float)AlienKilledSum[1] / (float)GetCountofUnits()[4] << "%" << endl;
		Output << "for AD: " << 100 * (float)AlienKilledSum[2] / (float)GetCountofUnits()[5] << "%" << endl;

		Output << "Df Alien average: " << DfAlien_avg << endl;
		Output << "Dd Alien average: " << DdAlien_avg << endl;
		Output << "Db Alien average: " << DbAlien_avg << endl;
		Output << "Df/Db % = " << (DfAlien_avg / DbAlien_avg) * 100 << "%";
		Output << "--- Dd/Db % = " << (DdAlien_avg / DbAlien_avg) * 100 << "%" << endl;
	}
}

//void game::Pick_Kill(string type)
//{
//	Unitarmy* U = nullptr;
//	if (type == "AD")
//	{
//		Killed_list.enqueue(getAlienarmy()->RemoveUnit(type, U));
//		Killed_list.enqueue(U);
//		return;
//	}
//	else if (type == "AM")
//		Killed_list.enqueue(getAlienarmy()->PickAm());
//	else if (type == "AS")
//	{
//		Aliensoldier* AS;
//		getAlienarmy()->getAS_List().dequeue(AS);
//		Killed_list.enqueue(AS);
//	}
//	else if(type == "ES" || type == "EG" || type == "ET")
//	Killed_list.enqueue(getEartharmy()->RemoveUnit(type));
//}

Eartharmy* game::getEartharmy()
{
	return &E_Army;
}
Alienarmy* game::getAlienarmy()
{
	return &A_Army;
}

//RandGen* game::getRandgen()
//{
//	return &Generator;
//}
int game::getTimestep()
{
	return TS;
}
void game::PrintKilled()
{
	cout<<endl << "=========== Killed/Destructed Units ===========" << endl;
	cout<<Killed_list.GetCount() << " Killed units ";
	Killed_list.print();
}
void game::printUML() //***
{
	cout << endl << "=========== Unit Maintanance Lists ===========" << endl;

	cout << UML1.GetCount() << " ES at UML1 "; UML1.print();
	cout << endl << UML2.GetCount() << " ET at UML2 "; UML2.print();
	cout << endl << endl;

}
void game::SetMode(bool M)
{
	Mode = M;
}

bool game::GetMode()
{
	return Mode;
}

int* game::GetCountofUnits()
{
	return Generator.Passtotalcounts();
}

LinkedQueue<EarthTank*>& game::getUML_2()
{
	return UML2;
}

bool game::AddtoUML(Unitarmy* U)
{
	if (U->GetType() == "ES")
		return UML1.enqueue(dynamic_cast<Earthsoldier*>(U), 20 - U->GetHealth());
	else if (U->GetType() == "ET")
		return UML2.enqueue(dynamic_cast<EarthTank*>(U));
	else
		return false;
}

// For Rewan :you can make function (PickUML() to pick a unit from UML 1 or 2 according to the type instead of getters of the lists

priQueue<Earthsoldier*>& game::getUML_1() 
{
	return UML1;
}

void game::Kill(Unitarmy* U)
{
		Killed_list.enqueue(U);
	/*else if (U->GetType() == "AS" || U->GetType() == "AM")
		Killed_list.enqueue(getAlienarmy()->RemoveUnit(type, U));
	else if (U->GetType() == "ES" || type == "EG" || type == "ET")
		Killed_list.enqueue(getEartharmy()->RemoveUnit(type));*/
}
bool game::SU_check()
{
	SaverUnit* su = new SaverUnit();
	Earthsoldier* es = new Earthsoldier;
	if (Earthsoldier::GetInfCount() == 0)
	{
		while (getEartharmy()->GetSUList().dequeue(su)) // to empty su list
			delete su;
		return true;
	}
	return false;
}