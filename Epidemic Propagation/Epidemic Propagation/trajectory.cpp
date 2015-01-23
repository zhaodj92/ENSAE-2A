#include <iostream>
#include "trajectory.h"
;using namespace std;


Trajectory::Trajectory()
{
	for (int i=0;i<32;i++)
	{
		action[i]=0;
	}
}

Trajectory::~Trajectory(void)
{
}