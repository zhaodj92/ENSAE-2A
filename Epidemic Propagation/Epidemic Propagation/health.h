#include <iostream>
#include <string>
using namespace std;


#ifndef Health_H
#define Health_H

class Health:public Person
{
public:
	bool isHealthful;	//1=healthful 0=sick
	float p;			//probability to be infected

	Health(bool,float);
	~Health(void);
	void probability(int, string, int);
};

#endif