#ifndef __laptop
#define __laptop
#include <iostream>
#include "electronic_device.h"

class laptop : public electronic_device
{

protected:

	int number_of_cores;

	bool touchscreen;

public:

	laptop() :electronic_device()
	{
		number_of_cores = 0;

		touchscreen = 0;
	}
	laptop(std::string b, int s, std::string c, double p, int x,bool y) :electronic_device(b, s, c, p)
	{
		number_of_cores = x;

		touchscreen = y;
	}
	void set_number_of_cores(int x)
	{
		number_of_cores = x;
	}
	void set_touchscreen(bool x)
	{
		touchscreen = x;
	}
	 bool get_touchscreen()
	{
		return touchscreen;
	}
	 int get_number_of_cores()
	{
		return number_of_cores;
	}
	 virtual std::string print()
	 {

		 std::string x = brand + " " + std::to_string(serial_number) + " " + color + " " + std::to_string(price) + " " + std::to_string(number_of_cores)+" "+std::to_string(touchscreen);
		 return x;
	 }

};
#endif 
