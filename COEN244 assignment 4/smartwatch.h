#ifndef __smartwatch
#define __smartwatch
#include <iostream>
#include "electronic_device.h"

class smartwatch : public electronic_device
{

protected:

	int battery_life;

public:

	smartwatch() :electronic_device()
	{
		battery_life = 0;
	}
	smartwatch(std::string b, int s, std::string c, double p, int x) :electronic_device(b, s, c, p)
	{
		battery_life = x;
	}
	void set_battery_life(int x)
	{
		battery_life = x;
	}
	 int get_battery_life()
	{
		return battery_life;
	}
	 virtual std::string print()
	 {

		 std::string x = brand + " " + std::to_string(serial_number) + " " + color + " " + std::to_string(price) + " " + std::to_string(battery_life);
		 return x;
	 }

};
#endif 
