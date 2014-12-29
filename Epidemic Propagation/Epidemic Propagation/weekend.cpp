#include <iostream>
#include <string>
#include "trajectory.h"
#include "weekend.h"
;using namespace std;


Weekend::Weekend()
{
	for (int i=0;i<30;i++)
	{
		action[i]=0;
	}
}

Weekend::~Weekend(void)
{
}