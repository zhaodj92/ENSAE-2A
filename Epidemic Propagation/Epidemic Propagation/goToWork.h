#include <iostream>
#include <string>
using namespace std;

#ifndef GoToWork_H
#define GoToWork_H

class GoToWork:public Trajectory
{
public:
	int trajectoryID;
	int action[14];			//list of actions the person do at each hour

	GoToWork();
	~GoToWork(void);

	void createTrajectory();
};

#endif