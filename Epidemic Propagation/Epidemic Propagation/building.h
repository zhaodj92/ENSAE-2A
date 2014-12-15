#include <iostream>
#include <string>
using namespace std;


#ifndef Building_H
#define Building_H

class Building:public Person
{
public:
	int x;				//coordinate
	int y;
	char type;			//home school bureau store bus...
	int buildingID;
	int numOfSicks;
	
	Building(int,int,const char,int,int);
	~Building(void);
	void functionInBuiding();
};


#endif