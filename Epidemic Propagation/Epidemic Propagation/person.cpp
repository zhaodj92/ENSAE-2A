#include <iostream>
#include "person.h"
;using namespace std;

Person::Person()
{
}

Person::~Person(void)
{
}

void Person::createOnePerson(string a,int h,int w)		//a age, h homeID, w workID
{
	age=a;
	homeID=h;
	workID=w;
	isHealthful=true;
}