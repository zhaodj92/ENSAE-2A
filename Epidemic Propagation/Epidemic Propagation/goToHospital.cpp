#include <iostream>
#include <string>
#include "trajectory.h"
#include "goToHospital.h"
;using namespace std;


GoToHospital::GoToHospital()
{
	trajectoryID=1;			//test
	for (int i=0;i<30;i++)
	{
		action[i]=0;
	}
}

GoToHospital::~GoToHospital(void)
{
}