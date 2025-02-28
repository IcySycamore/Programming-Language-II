#pragma once
class Complex
{
public:
	double realPart;
	double imaginaryPart;
public:
	Complex(double = 0, double = 0);
	Complex Plus(const Complex&);
	Complex Subtraction(const Complex&);
	void print()const;

};

