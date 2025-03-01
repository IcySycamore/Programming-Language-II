#pragma once
#include <string>
class SimpleCalculator
{
public:
	SimpleCalculator(std::string = "");
	static double add(double, double);
	static double subtract(double, double);
	static double multiply(double, double);
	static double divide(double, double);
	void setName(std::string);
private:
	std::string name;
};

