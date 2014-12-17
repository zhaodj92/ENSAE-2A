#include <iostream>
#include <string>
#include "person.h"
#include "building.h"
#include "trajectory.h"

#include "goToHospital.h"
#include "goToWork.h"
#include "weekend.h"
;using namespace std;


void main()
{
	Person a;
	cout << a.age <<endl;
	GoToHospital work1;
	cout << work1.trajectoryID <<endl; 
};