#include "functions.h"
#include <time.h>

vector<Building> createBuildings(vector<Building> Vect, int i, int j,bool h)//,int BuilingNum)	//zoneID, number of buildings of this type
{
	for (int k=0;k<j;k++)
	{
		Building b;
		b.zoneID=i;
		//int *pBuilingNum=&BuilingNum;
		//(*pBuilingNum)++;
		//b.buildingID=&b;//b.buildingID=BuilingNum;
		b.numOfSicks=0;
		b.newSicks=0;
		b.numOfPersons=0;
		b.isHospital=h;
		Vect.push_back(b);
		//Vect[k].buildingID=&Vect[k];
	}
	return Vect;
}


vector<Person> createPersons(vector<Person> Vect,int c,int a,int o)			//number of children, adults, olds
{
	//create children
	for (int k=0;k<c;k++)
	{
		Person person;
		person.age="child";
		person.isHealthful=true;
		person.realize=false;
		Vect.push_back(person);
	}
	//create adults
	for (int k=0;k<a;k++)
	{
		Person person;
		person.age="adult";
		person.isHealthful=true;
		person.realize=false;
		Vect.push_back(person);
	}

	for (int k=0;k<o;k++)
	{
		Person person;
		person.age="old";
		person.isHealthful=true;
		person.realize=false;
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
	for (int i=12; i<=14;i++)	//go to hospital before 1:00 pm, and go back 2 hours later
	{
		Trajectory b;
		b.action[i-2]=3;
		b.action[i-1]=8;
		b.action[i]=5;
		b.action[i+4]=8;
		b.action[i+5]=3;
		b.action[i+6]=2;
		Vect.push_back(b);
	}
	return Vect;
}


vector<Trajectory> createWeekend(vector<Trajectory> Vect)
{
	Trajectory w;
	Vect.push_back(w);		//stay at home and do nothing... I always do that... lol

	for (int i=0; i<19;i++)		//between 8:00 am and 19:00 pm, go to friends' home or shopping
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
		P[i].buildingID=P[i].homeID;		//at first, everyone stay at home
		P[i].homeZone=HOMES[rand()%(H)].zoneID;
		((*P[i].buildingID).numOfPersons)++;
		if (P[i].age=="child")
		{
			P[i].workID=SCHOOLS[rand()%(S)].buildingID;
			P[i].anotherZone=(*P[i].workID).zoneID;
		}
		if (P[i].age=="adult")
		{
			P[i].workID=OFFICES[rand()%(O)].buildingID;
			P[i].anotherZone=(*P[i].workID).zoneID;
		}
		if (P[i].age=="old")
		{
			P[i].anotherZone=(*P[i].homeID).zoneID;
		}
	}
	return P;
}

vector<int> vectorCumuler(vector<int> V)
{
	vector<int> W;
	W.push_back(0);
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
	for (int k=0;k<32;k++)
		{
			if (T[n].action[k]==0)//T[n].action[k];				//define actions of a person
			{
				P.trajectory[k]=0;
			}
			if (T[n].action[k]==1)
			{
				P.trajectory[k]=P.workID;
			}
			if (T[n].action[k]==2)
			{
				P.trajectory[k]=P.homeID;
			}
			if (T[n].action[k]==3)
			{
				P.trajectory[k]=BUSES[P.homeZone-1].buildingID;
			}
			if (T[n].action[k]==4)
			{
				P.trajectory[k]=STORES[rand()%(nSTORES[P.homeZone-1])+ncSTORES[P.homeZone-1]].buildingID;	//buildingID of one of the stores which are in the zone of the person's home
			}
			if (T[n].action[k]==5)
			{
				int nn=rand()%(HOSPITALS.size());
				P.trajectory[k]=HOSPITALS[nn].buildingID;
				P.anotherZone=HOSPITALS[nn].zoneID;
			}
			if (T[n].action[k]==6)
			{
				int nn=rand()%(HOMES.size());
				P.trajectory[k]=HOMES[nn].buildingID;
				P.anotherZone=HOMES[nn].zoneID;
			}
			if (T[n].action[k]==7)
			{
				int nn=rand()%(PARCS.size());
				P.trajectory[k]=PARCS[nn].buildingID;
				P.anotherZone=PARCS[nn].zoneID;
			}
			if (T[n].action[k]==8)
			{
				P.trajectory[k]=BUSES[P.anotherZone-1].buildingID;;
			}
			if (T[n].action[k]==9)
			{
				int nn=rand()%(STORES.size());
				P.trajectory[k]=STORES[nn].buildingID;
				P.anotherZone=STORES[nn].zoneID;
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
			if (P[i].realize==true)			//if he knows he's sick, go to hospital
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
			if (P[i].realize==true)			//if he knows he's sick, go to hospital
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





vector<Person> mouvementAndInfected(vector<Person> P,int T,int* pS)
{
	for (int i=0;i<P.size();i++)
	{
		if (P[i].trajectory[T]!=0)
		{
			if (P[i].isHealthful==false)
			{
				((*P[i].buildingID).newSicks)--;		//before infection

			}
			((*P[i].buildingID).numOfPersons)--;
			((*P[i].trajectory[T]).numOfPersons)++;
			P[i].buildingID=P[i].trajectory[T];

			//infection and after movement
			float p=rand()%100000001/100000000.0;
			if((*P[i].buildingID).isHospital==false && P[i].isHealthful==true)
			{
				if (p<0.0001*(*P[i].buildingID).numOfSicks && P[i].age=="adult")			//probability to be infected for a adult
				{
					P[i].isHealthful=false;
					(*pS)++;
				}

				if (p<0.0003*(*P[i].buildingID).numOfSicks && P[i].age=="child")
				{
					P[i].isHealthful=false;
					(*pS)++;
				}

				if (p<0.0002*(*P[i].buildingID).numOfSicks && P[i].age=="old")
				{
					P[i].isHealthful=false;
					(*pS)++;
				}
			}

			if((*P[i].buildingID).isHospital==true && P[i].isHealthful==false)
			{
				if (p<0.05)			//probability to be cured
				{
					P[i].isHealthful=true;
					(*pS)--;
				}
			}
			
			if (P[i].isHealthful==false)
			{
				((*P[i].trajectory[T]).newSicks)++;
			}


		}

		//if no movement
		if (P[i].trajectory[T]==0)
		{
			//infection
			float p=rand()%100000001/100000000.0;
			if((*P[i].buildingID).isHospital==false && P[i].isHealthful==true)
			{
				if (p<0.0001*(*P[i].buildingID).numOfSicks && P[i].age=="adult")			//probability to be infected for a adult
				{
					P[i].isHealthful=false;
					(*pS)++;
					((*P[i].buildingID).newSicks)++;
				}

				if (p<0.0003*(*P[i].buildingID).numOfSicks && P[i].age=="child")
				{
					P[i].isHealthful=false;
					(*pS)++;
					((*P[i].buildingID).newSicks)++;
				}

				if (p<0.0002*(*P[i].buildingID).numOfSicks && P[i].age=="old")
				{
					P[i].isHealthful=false;
					(*pS)++;
					((*P[i].buildingID).newSicks)++;
				}
			}

			if((*P[i].buildingID).isHospital==true && P[i].isHealthful==false)
			{
				if (p<0.05)			//probability to be cured
				{
					P[i].isHealthful=true;
					(*pS)--;
					((*P[i].buildingID).newSicks)--;
				}
			}
			
		}

		//cout << "after infection" << endl;
		//cout << (*P[i].buildingID).numOfPersons << endl;
	}

	return P;
}

void newSicks(vector<Building*> B)
{
	for (int i=0; i<B.size();i++)
	{
		(*B[i]).numOfSicks=(*B[i]).numOfSicks+(*B[i]).newSicks;
		(*B[i]).newSicks=0;
	}

}

vector<Person> createSicks(vector<Person> P,int n)//,vector<Building> HOMES,vector<Building> OFFICES,vector<Building> STORES,vector<Building> HOSPITALS,vector<Building> SCHOOLS,vector<Building> PARCS,vector<Building> BUSES)
{
	vector<int> A;
	while (A.size()!=n)
	{
		int r=rand()%(P.size());
		bool t=false;			//false if r is not an element of A
		for (int i=0;i<A.size();i++)
		{
			if (A[i]==r)
			{
				t=true;
			}
		}
		if (t==false)
		{
			A.push_back(r);
			P[r].isHealthful=false;
			((*P[r].buildingID).numOfSicks)++;
		}
	}
	return P;
}


vector<Person> realize(vector<Person> P)
{
	for (int i=0; i<P.size();i++)
	{
		if (P[i].realize==false && P[i].isHealthful==false && rand()%100<20)
		{
			P[i].realize=true;
		}

	}
	return P;
}
