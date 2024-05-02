#include "game.h"

game::game():Generator(this)
{
	Readinput();
	SetRandgen();
	//WriteOutput();
}

void game::Simulate()
{
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<< Current Timestep " << TS <<" >>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	Generator.generateUnit();
	getEartharmy()->printEarth();
	getAlienarmy()->PrintAlien();
	getEartharmy()->attack();
	PrintKilled();
	cout << endl << endl;
	TS++;
}

void game::Readinput()
{
	ifstream myfile("inputfile.txt");
	if (myfile.is_open())
	{
		myfile >> N;
		myfile >> Earth_per[0];
		myfile >> Earth_per[1];
		myfile >> Earth_per[2];
		myfile >> Alien_per[0];
		myfile >> Alien_per[1];
		myfile >> Alien_per[2];
		myfile >> Prob;
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
	Generator.setN_Prob(N, Prob);
	Generator.setE_per(Earth_per[0], Earth_per[1], Earth_per[2]);
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
		Output << "Df Earth average: " << DfEarth_avg << endl;
		Output << "Dd Earth average: " << DdEarth_avg << endl;
		Output << "Db Earth average: " << DbEarth_avg << endl;
		Output << "Df/Db % = " << (DfEarth_avg / DbEarth_avg) * 100 << "%";
		Output << "__ Dd/Db % = " << (DdEarth_avg / DbEarth_avg) * 100 << "%" << endl;
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
		Output << "__ Dd/Db % = " << (DdAlien_avg / DbAlien_avg) * 100 << "%" << endl;
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

LinkedQueue<Unitarmy*>& game::GetTemp()
{
	return Temp_list;
}
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

void game::Kill(Unitarmy* U)
{
		Killed_list.enqueue(U);
	/*else if (U->GetType() == "AS" || U->GetType() == "AM")
		Killed_list.enqueue(getAlienarmy()->RemoveUnit(type, U));
	else if (U->GetType() == "ES" || type == "EG" || type == "ET")
		Killed_list.enqueue(getEartharmy()->RemoveUnit(type));*/
}