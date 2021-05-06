#ifndef __electronic_device
#define __electronic_device
#include<iostream>
#include<string>

class electronic_device {
protected:
	std::string brand;
	int serial_number;
	std::string color;
	double price;

public:
	electronic_device()
	{
		brand = "";
		serial_number = 0;
		color = "";
		price = 0;
	}
	electronic_device(std::string b, int s, std::string c,double p)
	{
		brand = b;
		serial_number = s;
		color = c;
		price = p;
	}
	void set_brand(std::string b)
	{
		brand = b;
	}
	std::string get_brand()
	{
		return brand;
	}
	void set_serial_number(int x)
	{
		serial_number = x;
	}
	int get_serial_number()
	{
		return serial_number;
	}
	void set_color(std::string x)
	{
		color = x;
	}
	std::string get_color()
	{
		return color;
	}
	void set_price(double x)
	{
		price = x;
	}
	double get_price()
	{
		return price;
	}
	virtual std::string print()
	{

		std::string x = brand + " " + std::to_string(serial_number) + " " + color + " " + std::to_string(price);
		return x;
	}

};

#endif // !__electronic_device