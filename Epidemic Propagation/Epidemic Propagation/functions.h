#include <iostream>
#include <string>
#include <vector>

#include "person.h"	
#include "building.h"
#include "trajectory.h"


;using namespace std;

vector<Building> createBuildings(vector<Building>,int,int,int);		//zoneID, number of buildings of this type
vector<Person> createPersons(vector<Person>,int,int,int);		//number of children, adults, odes
vector<Trajectory> createGoToWork(vector<Trajectory>);
vector<Trajectory> createGoToHospital(vector<Trajectory>);
vector<Trajectory> createWeekend(vector<Trajectory>);

vector<Person> defineHome_Work(vector<Person>,int,int,int);	//number of Homes, Offices, Schools

Person choiceOfTrajectory(Person,vector<Trajectory>);
vector<Person> typeOfTrajectory(vector<Person>,int,vector<Trajectory>,vector<Trajectory>,vector<Trajectory>);	//work hospital weekend
