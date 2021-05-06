#ifndef __TA
#define __TA
#include<iostream>
#include<string>

class TA {

	//data members are public so we can access them from the testdriver so we can directly edit them when we read
	// them from the intended file so we don't have to use accessing functions

public:
	// start year and end year are year hired 
	int id, startYear, endYear, workingHours;

	//class spec is class specification ie( Grad,Grads,Alum)
	std::string classSpec;
	std::string firstName;
	std::string lastName;

	
};

#endif // !__TA

