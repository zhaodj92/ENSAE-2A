#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "person.h"	
#include "building.h"
#include "trajectory.h"

#include "goToHospital.h"
#include "goToWork.h"
#include "weekend.h"

#include "functions.h"
;using namespace std;


//next work to do: code the programme to define everyone's home and work


void main()
{
	//test

	
	//end

	//random
	srand( (unsigned)time( NULL ) );
	//beginning of code
	//city size
	int numOfChildren;
	cout << "please enter the number of CHILDREN you want to create"<<endl;
	cin >> numOfChildren;
	int numOfAdults;
	cout << "please enter the number of ADULTS you want to create"<<endl;
	cin >> numOfAdults;
	int numOfOlds;
	cout << "please enter the number of OLDS you want to create"<<endl;
	cin >> numOfOlds;
	vector<Person> VILLIGERS;
	VILLIGERS=createPersons(VILLIGERS,numOfChildren,numOfAdults,numOfOlds);

	//test
	cout << VILLIGERS[3].age<< endl;
	cout << VILLIGERS[15].age<< endl;
	cout << VILLIGERS[24].age<< endl;


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
	int numOfZones;
	cout << "please enter the number of zones you want to create"<< endl;
	cin >> numOfZones;
	int BuilingNum=10;						//this variable is the number of buildings which were already created +10
	for (int i=1;i <= numOfZones;i++ )	//i is zoneID
	{
		int j;
		cout << "please enter the number of HOMES you want to create in zone"<< i << endl;
		cin >> j;
		HOMES=createBuildings(HOMES,i,j,BuilingNum);
		cout << "please enter the number of OFFICES you want to create in zone"<< i << endl;
		cin >> j;
		OFFICES=createBuildings(OFFICES,i,j,BuilingNum);
		cout << "please enter the number of STORES you want to create in zone"<< i << endl;
		cin >> j;
		STORES=createBuildings(STORES,i,j,BuilingNum);
		cout << "please enter the number of HOSPITALS you want to create in zone"<< i << endl;
		cin >> j;
		HOSPITALS=createBuildings(HOSPITALS,i,j,BuilingNum);
		cout << "please enter the number of SCHOOLS you want to create in zone"<< i << endl;
		cin >> j;
		SCHOOLS=createBuildings(SCHOOLS,i,j,BuilingNum);
		cout << "please enter the number of PARCS you want to create in zone"<< i << endl;
		cin >> j;
		PARCS=createBuildings(PARCS,i,j,BuilingNum);
		cout << "please enter the number of BUSES you want to create in zone"<< i << endl;
		cin >> j;
		BUSES=createBuildings(BUSES,i,j,BuilingNum);
	}
	

	//creation of trajectories
	vector<GoToWork> GOTOWORK;
	vector<GoToHospital> GOTOHOSPITAL;
	vector<Weekend> WEEKEND;
	cout << "ok"<< endl;
	GOTOWORK=createGoToWork(GOTOWORK);
	cout << "ok"<< endl;
	GOTOHOSPITAL=createGoToHospital(GOTOHOSPITAL);
	cout << "ok"<< endl;
	WEEKEND=createWeekend(WEEKEND);
	cout << "ok" << endl;

	//define everyone's home and work
	VILLIGERS=defineHome_Work(VILLIGERS,HOMES.size(),OFFICES.size(),SCHOOLS.size());

	cout<< "ok" << endl;
	//test

	cout<< VILLIGERS[1].homeID <<endl;
	cout<< VILLIGERS[2].homeID <<endl;
	cout<< VILLIGERS[3].homeID <<endl;
	cout<< VILLIGERS[4].homeID <<endl;
	cout<< VILLIGERS[5].homeID <<endl;
	cout<< VILLIGERS[6].homeID <<endl;
	cout<< VILLIGERS[7].homeID <<endl;

	//end of test

	system("pause");

};