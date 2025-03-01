#include "SimpleCalculator.h"

SimpleCalculator::SimpleCalculator(std::string s) :name{ s }
{
}

double SimpleCalculator::add(double a, double b)
{
	return a + b;
}

double SimpleCalculator::subtract(double a, double b)
{
	return a - b;
}

double SimpleCalculator::multiply(double a, double b)
{
	return a * b;
}

double SimpleCalculator::divide(double a, double b)
{
	return a / b;
}

void SimpleCalculator::setName(std::string s)
{
	name = s;
}
