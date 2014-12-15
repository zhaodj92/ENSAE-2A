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

	Person();
	~Person(void);
	void functionInPerson();
	
};

#endif