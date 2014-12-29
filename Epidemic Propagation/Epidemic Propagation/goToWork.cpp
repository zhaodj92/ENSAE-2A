#include <iostream>
#include <string>
#include "trajectory.h"
#include "goToWork.h"
;using namespace std;


GoToWork::GoToWork()
{
	for (int i=0;i<30;i++)
	{
		action[i]=0;
	}
}

GoToWork::~GoToWork(void)
{
}