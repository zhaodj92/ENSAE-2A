#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "person.h"	
#include "building.h"
#include "trajectory.h"

#include "functions.h"
;using namespace std;


//following work to do: code a hour


void main()
{
	//test
	Person c;
	Person* pc=&c;
	cout << pc << endl;
	//end

	//random
	srand( (unsigned)time( NULL ) );
	//beginning of code
	//city size
	int numOfChildren=10;
	cout << "please enter the number of CHILDREN you want to create"<<endl;
	//////cin >> numOfChildren;
	int numOfAdults=10;
	cout << "please enter the number of ADULTS you want to create"<<endl;
	/////cin >> numOfAdults;
	int numOfOlds=10;
	cout << "please enter the number of OLDS you want to create"<<endl;
	/////cin >> numOfOlds;
	vector<Person> CITIZENS;
	CITIZENS=createPersons(CITIZENS,numOfChildren,numOfAdults,numOfOlds);

	//test
	cout << CITIZENS[3].age<< endl;
	cout << CITIZENS[15].age<< endl;
	cout << CITIZENS[24].age<< endl;


	float n=rand()%101/100.0;
	cout << n<<endl;

	//end of test

	vector<Building> HOMES;
	vector<Building> OFFICES;
	vector<Building> STORES;
	vector<Building> HOSPITALS;
	vector<Building> SCHOOLS;
	vector<Building> PARCS;
	vector<Building> BUSES;
	int numOfZones=1;
	cout << "please enter the number of zones you want to create"<< endl;
	/////cin >> numOfZones;
	int BuilingNum=10;						//this variable is the number of buildings which were already created +10
	vector<int> nHOMES;
	vector<int> nOFFICES;
	vector<int> nSTORES;
	vector<int> nHOSPITALS;
	vector<int> nSCHOOLS;
	vector<int> nPARCS;
	vector<int> nBUSES;
	for (int i=1;i <= numOfZones;i++ )	//i is zoneID
	{
		int j=5;
		cout << "please enter the number of HOMES you want to create in zone"<< i << endl;
		/////cin >> j;
		HOMES=createBuildings(HOMES,i,j,false);//BuilingNum);
		nHOMES.push_back(j);
		cout << "please enter the number of OFFICES you want to create in zone"<< i << endl;
		/////cin >> j;
		OFFICES=createBuildings(OFFICES,i,j,false);//BuilingNum);
		nOFFICES.push_back(j);
		cout << "please enter the number of STORES you want to create in zone"<< i << endl;
		/////cin >> j;

		j=1;
		STORES=createBuildings(STORES,i,j,false);//BuilingNum);
		nSTORES.push_back(j);
		cout << "please enter the number of HOSPITALS you want to create in zone"<< i << endl;
		/////cin >> j;
		HOSPITALS=createBuildings(HOSPITALS,i,j,true);//BuilingNum);
		nHOSPITALS.push_back(j);
		cout << "please enter the number of SCHOOLS you want to create in zone"<< i << endl;
		/////cin >> j;
		SCHOOLS=createBuildings(SCHOOLS,i,j,false);//BuilingNum);
		nSCHOOLS.push_back(j);
		cout << "please enter the number of PARCS you want to create in zone"<< i << endl;
		/////cin >> j;
		PARCS=createBuildings(PARCS,i,j,false);//BuilingNum);
		nPARCS.push_back(j);
		//cout << "please enter the number of BUSES you want to create in zone"<< i << endl;
		//cin >> j;
		BUSES=createBuildings(BUSES,i,1,false);//BuilingNum);
		nBUSES.push_back(1);
	}
	
	vector<Building*> ALLBUILDINGS;

	for (int i=0; i<HOMES.size();i++)
	{
		HOMES[i].buildingID=&HOMES[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}
	for (int i=0; i<OFFICES.size();i++)
	{
		OFFICES[i].buildingID=&OFFICES[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}
	for (int i=0; i<STORES.size();i++)
	{
		STORES[i].buildingID=&STORES[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}
	for (int i=0; i<HOSPITALS.size();i++)
	{
		HOSPITALS[i].buildingID=&HOSPITALS[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}
	for (int i=0; i<SCHOOLS.size();i++)
	{
		SCHOOLS[i].buildingID=&SCHOOLS[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}
	for (int i=0; i<PARCS.size();i++)
	{
		PARCS[i].buildingID=&PARCS[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}
	for (int i=0; i<BUSES.size();i++)
	{
		BUSES[i].buildingID=&BUSES[i];
		ALLBUILDINGS.push_back(&HOMES[i]);
	}

	//creation of trajectories
	vector<Trajectory> GOTOWORK;
	vector<Trajectory> GOTOHOSPITAL;
	vector<Trajectory> WEEKEND;
	cout << "ok"<< endl;
	GOTOWORK=createGoToWork(GOTOWORK);
	cout << "ok"<< endl;
	GOTOHOSPITAL=createGoToHospital(GOTOHOSPITAL);
	cout << "ok"<< endl;
	WEEKEND=createWeekend(WEEKEND);
	cout << "ok" << endl;

	//define everyone's home and work
	CITIZENS=defineHome_Work(CITIZENS,HOMES.size(),OFFICES.size(),SCHOOLS.size(),HOMES,OFFICES,SCHOOLS);

	//some persons are already sick
	cout << "number of sicks" << endl;
	int SICKS;
	cin >> SICKS;
	CITIZENS=createSicks(CITIZENS,SICKS);//,HOMES,OFFICES,STORES,HOSPITALS,SCHOOLS,PARCS,BUSES);
	int* pSICKS=&SICKS;
	cout << "OK sicks" << endl;

	//*********************************code*****************************//


	int DAY=0;
	string NextDay="yes";//we begin with monday
	while (NextDay=="yes")
	{
		DAY++;
		DAY=DAY%7;

		//realize someone is sick
		CITIZENS=realize(CITIZENS);

		//choice of trajectory
		
		CITIZENS=typeOfTrajectory(CITIZENS,DAY,GOTOWORK,GOTOHOSPITAL,WEEKEND,nSTORES,HOMES,STORES,HOSPITALS,PARCS,BUSES);
		

		for (int T=0; T<32;	T++)		// T time
		{
			//movement and infection

			CITIZENS=mouvementAndInfected(CITIZENS,T,pSICKS);	//every building has the same infection coefficient

			cout << "T" << endl;
			cout << T << endl;
			//new sicks
			newSicks(ALLBUILDINGS);
			
			//result
			cout << SICKS << endl;
		}


		NextDay="no";
		cout << "Do you want to simulate the propagation in the next day? (yes or no)"<< endl;
		cin >> NextDay;
	}



	system("pause");



};