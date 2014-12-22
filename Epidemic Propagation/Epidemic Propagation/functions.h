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

vector<Building> createBuildings(vector<Building>,int,int,int);		//zoneID, number of buildings of this type
vector<Person> createPersons(vector<Person>,int,int,int);		//number of children, adults, odes
vector<GoToWork> createGoToWork(vector<GoToWork>);
vector<GoToHospital> createGoToHospital(vector<GoToHospital>);
vector<Weekend> createWeekend(vector<Weekend>);