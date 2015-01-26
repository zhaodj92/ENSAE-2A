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
vector<Trajectory> createGoToWork(vector<Trajectory> Vect)
{
	for (int k=0;k<=5;k++)
	{
		Trajectory a;
		a.action[k]=3;
		a.action[k+1]=8;
		a.action[k+2]=1;
		a.action[k+18]=8;
		a.action[k+19]=3;
		a.action[k+20]=2;
		Vect.push_back(a);
		Trajectory b;
		b.action[k]=3;
		b.action[k+1]=8;
		b.action[k+2]=1;
		b.action[k+18]=8;
		b.action[k+19]=3;
		b.action[k+20]=2;
		b.action[k+21]=3;
		b.action[k+22]=4;
		b.action[k+23]=3;
		b.action[k+24]=2;
		Vect.push_back(a);
	}
	return Vect;

}

//when a person is sick, he can decide to work, or to stay at home or go to hospital 
vector<Trajectory> createGoToHospital(vector<Trajectory> Vect)
{
	Trajectory a;
	Vect.push_back(a);
	Trajectory b;
	for (int i=12; i<=14;i++)	//go to hospital before 1:00 pm, and go back 2 hours later
	{
		b.action[i-2]=3;
		b.action[i-1]=8;
		b.action[i]=5;
		b.action[i+4]=8;
		b.action[i+5]=3;
		b.action[i+6]=2;
	}
	return Vect;
}


vector<Trajectory> createWeekend(vector<Trajectory> Vect)
{
	Trajectory w;
	Vect.push_back(w);		//stay at home and do nothing... I always do that... lol

	for (int i=0; i<20;i++)		//between 9:00 am and 19:00 pm, go to friends' home or shopping
	{
		Trajectory a;			//suppose that a penson will do only one thing per day
		Trajectory b;
		Trajectory c;
		a.action[i+3]=3;
		a.action[i+4]=8;
		a.action[i+5]=6;
		a.action[i+11]=8;
		a.action[i+12]=3;
		a.action[i+13]=2;
		b.action[i+3]=3;
		b.action[i+4]=8;
		b.action[i+5]=9;
		b.action[i+11]=8;
		b.action[i+12]=3;
		b.action[i+13]=2;
		c.action[i+3]=3;
		c.action[i+4]=8;
		c.action[i+5]=7;
		c.action[i+11]=8;
		c.action[i+12]=3;
		c.action[i+13]=2;
		Vect.push_back(a);
		Vect.push_back(b);
		Vect.push_back(c);
	}
	return Vect;
}




vector<Person> defineHome_Work(vector<Person> P,int H,int O,int S,vector<Building> HOMES,vector<Building> OFFICES,vector<Building> SCHOOLS)
{
	for(int i=0;i<(P.size());i++)
	{
		P[i].homeID=HOMES[rand()%(H)].buildingID;
		P[i].homeZone=HOMES[rand()%(H)].zoneID;
		if (P[i].age=="child")
		{
			P[i].workID=SCHOOLS[rand()%(S)].buildingID;
		}
		if (P[i].age=="adult")
		{
			P[i].workID=OFFICES[rand()%(O)].buildingID;
		}
	}
	return P;
}

vector<int> vectorCumuler(vector<int> V)
{
	vector<int> W;
	W.push_back(V[0]);
	for (int i=1; i<V.size();i++)
	{
		W.push_back(W[i-1]+V[i]);
	}
	return W;
}



Person choiceOfTrajectory(Person P,vector<Trajectory> T,vector<int> nSTORES,vector<Building> HOMES,vector<Building> STORES,vector<Building> HOSPITALS,vector<Building> PARCS,vector<Building> BUSES)
{
	vector<int> ncSTORES=vectorCumuler(nSTORES);
	int n=rand()%(T.size());									//choice of the trajectory
	P.anotherZone=0;
	vector<int> bus8;
	for (int k=0;k<32;k++)
		{
			if (T[n].action[k]=0)//T[n].action[k];				//define actions of a person
			{
				P.trajectory[k]=0;
			}
			if (T[n].action[k]=1)
			{
				P.trajectory[k]=P.workID;
			}
			if (T[n].action[k]=2)
			{
				P.trajectory[k]=P.homeID;
			}
			if (T[n].action[k]=3)
			{
				P.trajectory[k]=BUSES[P.homeZone].buildingID;
			}
			if (T[n].action[k]=4)
			{
				P.trajectory[k]=STORES[rand()%(nSTORES[P.homeZone-1])+ncSTORES[P.homeZone-1]].buildingID;	//buildingID of one of the stores which are in the zone of the person's home
			}
			if (T[n].action[k]=5)
			{
				int nn=rand()%(HOSPITALS.size());
				P.trajectory[k]=HOSPITALS[nn].buildingID;
				P.anotherZone=HOSPITALS[nn].zoneID;
			}
			if (T[n].action[k]=6)
			{
				int nn=rand()%(HOMES.size());
				P.trajectory[k]=HOMES[nn].buildingID;
				P.anotherZone=HOMES[nn].zoneID;
			}
			if (T[n].action[k]=7)
			{
				int nn=rand()%(PARCS.size());
				P.trajectory[k]=PARCS[nn].buildingID;
				P.anotherZone=PARCS[nn].zoneID;
			}
			if (T[n].action[k]=8)
			{
				bus8.push_back(k);
			}
			if (T[n].action[k]=9)
			{
				int nn=rand()%(STORES.size());
				P.trajectory[k]=STORES[nn].buildingID;
				P.anotherZone=STORES[nn].zoneID;
			}
			for (int l=0;l<bus8.size();l++)
			{
				P.trajectory[k]=BUSES[P.anotherZone].buildingID;		//a person lose one hour in stransport even if his home and his office are in the same zone
			}

		}
	return P;
}



vector<Person> typeOfTrajectory(vector<Person> P,int D,vector<Trajectory> WO,vector<Trajectory> H,vector<Trajectory>WE,vector<int> nSTORES,vector<Building> HOMES,vector<Building> STORES,vector<Building> HOSPITALS,vector<Building> PARCS,vector<Building> BUSES)	//work hospital weekend
{
	if (D<6);
	{
		for (int i=0;i<P.size();i++)
		{
			if (P[i].know==true)			//if he knows he's sick, go to hospital
			{
				P[i]=choiceOfTrajectory(P[i],H,nSTORES,HOMES,STORES,HOSPITALS,PARCS,BUSES);
			}
			else if(P[i].age=="old")
			{
				P[i]=choiceOfTrajectory(P[i],WE,nSTORES,HOMES,STORES,HOSPITALS,PARCS,BUSES);
			}

			else
			{
				P[i]=choiceOfTrajectory(P[i],WO,nSTORES,HOMES,STORES,HOSPITALS,PARCS,BUSES);
			}

		}

	}


	if (D>5)				//weekend
	{
		for (int i=0;i<P.size();i++)
		{
			if (P[i].know==true)			//if sick, go to hospital
				{
					P[i]=choiceOfTrajectory(P[i],H,nSTORES,HOMES,STORES,HOSPITALS,PARCS,BUSES);
				}
			else
				{
					P[i]=choiceOfTrajectory(P[i],WE,nSTORES,HOMES,STORES,HOSPITALS,PARCS,BUSES);
				}
		}
	}
	return P;
}
