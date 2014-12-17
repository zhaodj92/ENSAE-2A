#include <iostream>
#include <string>
using namespace std;


#ifndef Person_H
#define Person_H


class Person
{
public:
	//int id;				//identification of the person	//useless
	string age;			//"child" or "adult" or "old"
	int zoneID;
	int buildingID;
	int x;
	int y;
	bool isHealthful;
	float p;
	int trajectoryID;
	int homeID;
	int workID;			//it represents where he works or where is his school if this person is still a student, 0 if retraite

	Person();//string,int,int,int,int,bool,float,int,int,int);
	~Person(void);
	void functionInPerson();
	
};

#endif