#include <iostream>
#include <string>
#include <vector>

#include "person.h"	
#include "building.h"
#include "trajectory.h"


;using namespace std;

vector<Building> createBuildings(vector<Building>,int,int,bool);		//zoneID, number of buildings of this type
vector<Person> createPersons(vector<Person>,int,int,int);		//number of children, adults, odes
vector<Trajectory> createGoToWork(vector<Trajectory>);
vector<Trajectory> createGoToHospital(vector<Trajectory>);
vector<Trajectory> createWeekend(vector<Trajectory>);

vector<Person> defineHome_Work(vector<Person>,int,int,int,vector<Building>,vector<Building>,vector<Building>);	//number of Homes, Offices, Schools

Person choiceOfTrajectory(Person,vector<Trajectory>,vector<int>,vector<Building>,vector<Building>,vector<Building>,vector<Building>,vector<Building>); //nb of stores, homes, stores, hospitals, parcs, buses
vector<Person> typeOfTrajectory(vector<Person>,int,vector<Trajectory>,vector<Trajectory>,vector<Trajectory>,vector<int>,vector<Building>,vector<Building>,vector<Building>,vector<Building>,vector<Building>);	//work hospital weekend

vector<Person> realize(vector<Person>);
vector<Person> createSicks(vector<Person>,int);//,vector<Building>,vector<Building>,vector<Building>,vector<Building>,vector<Building>,vector<Building>,vector<Building>);
vector<Person> mouvementAndInfected(vector<Person>,int,int*); //time(hour)

vector<int> vectorCumuler(vector<int>);
vector<Building> newSicks(vector<Building>);
