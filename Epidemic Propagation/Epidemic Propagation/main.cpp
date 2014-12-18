#include <iostream>
#include <string>
#include <vector>

#include "person.h"	
#include "building.h"
#include "trajectory.h"

#include "goToHospital.h"
#include "goToWork.h"
#include "weekend.h"
;using namespace std;


void main()
{
	string age="child";
	int homeID=100;
	int workID=200;
	Person a;
	a.createOnePerson(age,homeID,workID);
	cout << a.age <<endl;


	GoToHospital work1;
	cout << work1.trajectoryID <<endl; 
	cout << work1.action[1] <<endl;


	//system("pause");


	//beginning of code
	//city size
	int numOfPersons;
	cin >> numOfPersons;
	vector<Person> VILLIGERS;
	//test
	VILLIGERS.push_back(a);
	cout << VILLIGERS[0].age <<endl;
	vector<int> intV;
	intV.push_back(1);
	cout << intV[0];

	system("pause");
	//end of test

	vector<Building> HOMES;
	vector<Building> OFFICES;
	vector<Building> STORES;
	vector<Building> HOSPITALS;
	vector<Building> SCHOOLS;
	vector<Building> PARCS;
	int numOfZones;
	cin >> numOfZones;
	for (int i=1;i <= numOfZones;i++ )
	{
		int j;

	}
	

	system("pause");

};