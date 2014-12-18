#include <iostream>
#include <string>
using namespace std;

#ifndef Weekend_H
#define Weekend_H

class Weekend:public Trajectory
{
public:
	int trajectoryID;
	int action[14];			//list of actions the person do at each hour

	Weekend();
	~Weekend(void);

	void createTrajectory();
};

#endif