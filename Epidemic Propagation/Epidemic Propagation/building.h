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
	int buildingID;
	int numOfSicks;
	//float coefficient;
	
	Building();//int,int,string,int,int,float);
	~Building(void);
	void createBuidings(int,int);//,string,float);		// zoneID,number of buildings of this type, //type, coefficient
};


#endif