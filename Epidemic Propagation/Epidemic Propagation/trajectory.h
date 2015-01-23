#include <iostream>
#include <string>
using namespace std;

//0 no movement		1 office school		2 home		3 bus(home zone)		4 shop		5 hospital		6 friend	7 parc
//8 bus(not home zone)
#ifndef Trajectory_H
#define Trajectory_H

class Trajectory
{
public:
	int action[32];			//list of actions the person do at every 30 min  (6:00 am-10:00 pm)

	Trajectory();
	~Trajectory(void);

};

#endif