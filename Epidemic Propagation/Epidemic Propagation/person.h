#include <iostream>
#include <string>
#include "building.h"
using namespace std;


#ifndef Person_H
#define Person_H


class Person
{
public:
	//int id;				//identification of the person	//useless
	string age;			//"child" or "adult" or "old"
	int zoneID;
	Building* buildingID;
	int homeZone;
	int anotherZone;		//a person will go to only one another zone
	bool isHealthful;
	bool realize;				//false if this person don't realize he's sick
	float p;
	Building* trajectory[32];
	Building* homeID;
	Building* workID;			//it represents where he works or where is his school if this person is still a student, 0 if retraite

	Person();//string,int,int,int,int,bool,float,int,int,int);
	~Person(void);
	void createOnePerson(string,Building*,Building*);		//age,homeID,workID
	
};

#endif