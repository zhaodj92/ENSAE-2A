#include <iostream>
#include <string>
using namespace std;


#ifndef Trajectory_H
#define Trajectory_H

class Trajectory:public Person
{
public:
	int t1;				//for every n between 1 and 10, tn=i means: change his position to building which identification is i
	int t2;				//changes take place at the moment tn
	int t3;				//t1 corresponds to 6:00 am; t2= 7:00am...
	int t4;
	int t5;
	int t6;
	int t7;
	int t8;
	int t9;
	int t10;
	int t11;
	int t12;

	Trajectory(int,int,int,int,int,int,int,int,int,int,int,int);
	~Trajectory(void);
	void functionInTrajectory();

};

#endif