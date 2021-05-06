#ifndef __cellphone
#define __cellphone
#include <iostream>
#include "electronic_device.h"

class cellphone : public electronic_device 
{

protected:

	int number_of_cameras;

public:

	cellphone():electronic_device()
	{
		number_of_cameras = 0;
	}
	cellphone(std::string b, int s, std::string c, double p, int x) :electronic_device(b, s, c, p)
	{
		number_of_cameras = x;
	}
	void set_number_of_cameras(int x)
	{
		number_of_cameras = x;
	}
	 int get_number_of_cameras()
	{
		return number_of_cameras;
	}
	 virtual std::string print()
	 {

		 std::string x = brand + " " + std::to_string(serial_number) + " " + color + " " + std::to_string(price)+" "+std::to_string(number_of_cameras);
		 return x;
	 }

};
#endif 

