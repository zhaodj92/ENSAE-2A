#include <iostream>
#include <string>
using namespace std;

#ifndef GoToHospital_H
#define GoToHospital_H

class GoToHospital:public Trajectory
{
public:
	int trajectoryID;		//unnecessary
	int action[30];			//list of actions the person do at every 30 min  (6:00 am-9:00 pm)

	GoToHospital();
	~GoToHospital(void);

	void createTrajectory();
};

#endif