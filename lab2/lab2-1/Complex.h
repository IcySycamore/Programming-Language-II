//complex.h
#pragma once
#include<iostream>
class Complex
{
	friend std::istream& operator>>(std::istream& input, Complex& c);
	friend std::ostream& operator<<(std::ostream& output, const Complex& c);
private:
	double realPart;
	double imaginaryPart;
public:
	Complex(double r = 0, double i = 0);
	Complex operator*(const Complex& c)const;
	Complex operator+(const Complex& c)const;
	Complex operator-(const Complex& c)const;
	bool operator==(const Complex& c)const;
	bool operator!=(const Complex& c)const;
};

std::istream& operator>>(std::istream& input, Complex&);
std::ostream& operator<<(std::ostream& output, const Complex&);
