//Complex.cpp
#include "Complex.h"
#include<iostream>
#include<iomanip>
#include<cmath>
std::istream& operator>>(std::istream& input, Complex& c)
{
	input.ignore(1);
	input >> std::setw(1) >> c.realPart;
	input.ignore(1);//忽略一个逗号，然后cin会自动忽略白字符读入其后数字
	input >> std::setw(1) >> c.imaginaryPart;
	input.ignore(1);
	return input;
}

std::ostream& operator<<(std::ostream& output, const Complex& c)
{
	output << "(" << c.realPart << ", " << c.imaginaryPart << ")";
	return output;
}

Complex::Complex(double r, double i)
{
	realPart = r;
	imaginaryPart = i;
}

Complex Complex::operator*(const Complex& c) const
{
	return Complex(realPart * c.realPart - imaginaryPart * c.imaginaryPart, realPart * c.imaginaryPart + c.realPart * imaginaryPart);
}

Complex Complex::operator+(const Complex& c) const
{
	return Complex(realPart + c.realPart, imaginaryPart + c.imaginaryPart);
}

Complex Complex::operator-(const Complex& c) const
{
	return Complex(realPart - c.realPart, imaginaryPart - c.imaginaryPart);
}

bool Complex::operator==(const Complex& c) const
{
	constexpr double epsilon = 1e-10;
	if (std::abs(realPart - c.realPart) < epsilon && std::abs(imaginaryPart == c.imaginaryPart) < epsilon)
		return true;
	return false;
}

bool Complex::operator!=(const Complex& c) const
{
	return !(*this == c);
}
