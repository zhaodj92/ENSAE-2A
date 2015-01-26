#include <iostream>
#include <string>
using namespace std;


#ifndef Building_H
#define Building_H

class Building
{
public:
	int zoneID;
	int x;				//coordinate
	int y;
	//string type;			//home school bureau store bus...
	Building* buildingID;			//maybe we should use the adress
	int numOfSicks;
	int numOfPersons;
	int newSicks;
	//float coefficient;
	
	Building();//int,int,string,int,int,float);
	~Building(void);
	void createOneBuiding(int);//,string,float);		// zoneID, coefficient
};


#endif