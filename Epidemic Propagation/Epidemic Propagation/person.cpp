#include <iostream>
#include "person.h"
#include "building.h"
;using namespace std;

Person::Person()
{
}

Person::~Person(void)
{
}

void Person::createOnePerson(string a,Building* h,Building* w)		//a age, h homeID, w workID
{
	age=a;
	homeID=h;
	workID=w;
	isHealthful=true;
	know=false;
}