#include <iostream>
#include <string>
using namespace std;

#ifndef GoToHospital_H
#define GoToHospital_H

class GoToHospital:public Trajectory
{
public:
	int trajectoryID;
	int action[14];			//list of actions the person do at each hour

	GoToHospital();
	~GoToHospital(void);

	void createTrajectory();
};

#endif