#include "functions.h"
#include <time.h>

vector<Building> createBuildings(vector<Building> Vect,int i, int j,int BuilingNum)	//zoneID, number of buildings of this type
{
	for (int k=0;k<=j;k++)
	{
		Building b;
		b.zoneID=i;
		int *pBuilingNum=&BuilingNum;
		(*pBuilingNum)++;
		b.buildingID=BuilingNum;
		Vect.push_back(b);
	}
	return Vect;
}


vector<Person> createPersons(vector<Person> Vect,int c,int a,int o)			//number of children, adults, olds
{
	//create children
	for (int k=0;k<=c;k++)
	{
		Person person;
		person.age="child";
		Vect.push_back(person);
	}
	//create adults
	for (int k=0;k<=a;k++)
	{
		Person person;
		person.age="adult";
		Vect.push_back(person);
	}

	for (int k=0;k<=o;k++)
	{
		Person person;
		person.age="old";
		Vect.push_back(person);
	}
	return Vect;
}


//a person can go to work in the morning, and go home 9 hours later, he can also go to shop in the evening with a probability 0.5
vector<GoToWork> createGoToWork(vector<GoToWork> Vect)
{
	for (int k=0;k<=5;k++)
	{
		GoToWork a;
		a.action[k]=1;
		a.action[k+18]=2;
		Vect.push_back(a);
		GoToWork b;
		b.action[k]=1;
		b.action[k+18]=2;
		b.action[k+22]=4;
		Vect.push_back(a);
	}
	return Vect;

}

//when a person is sick, he can decide to work, or to stay at home or go to hospital 
vector<GoToHospital> createGoToHospital(vector<GoToHospital> Vect)
{
	GoToHospital a;
	Vect.push_back(a);
	GoToHospital b;
	for (int i=12; i<=14;i++)	//go to hospital before 1:00 pm, and go back 2 hours later
	{
		b.action[i]=5;
		b.action[i+4]=2;
	}
	return Vect;
}


vector<Weekend> createWeekend(vector<Weekend> Vect)
{
	Weekend w;
	Vect.push_back(w);		//stay at home and do nothing... I always do that... lol

	for (int i=0; i<20;i++)		//between 9:00 am and 19:00 pm, go to friends' home or shopping
	{
		Weekend a;			//suppose that a penson will do only one thing per day
		Weekend b;
		a.action[i+5]=6;
		b.action[i+5]=4;
		Vect.push_back(a);
		Vect.push_back(b);
	}
	return Vect;
}




vector<Person> defineHome_Work(vector<Person> P,int H,int O,int S)
{
	for(int i=0;i<(P.size());i++)
	{
		P[i].homeID=rand()%(H+1);
		if (P[i].age=="child")
		{
			P[i].workID=rand()%(S+1);
		}
		if (P[i].age=="adult")
		{
			P[i].workID=rand()%(O+1);
		}
	}
	return P;
}
