#include "Complex.h"
#include <iostream>
Complex::Complex(double a, double b)
	:realPart(a), imaginaryPart(b)
{
#if 0
	std::cout << "A Complex Object: ";
	this->print();
	std::cout << "has been initialzed!\n";
#endif
}

Complex Complex::Plus(const Complex& c)
{
	Complex temp{ realPart + c.realPart,imaginaryPart + c.imaginaryPart };
	print();
	std::cout << " + ";
	c.print();
	std::cout << " = ";
	temp.print();
	return temp;

}
Complex Complex::Subtraction(const Complex& c)
{
	Complex temp{ realPart - c.realPart,imaginaryPart - c.imaginaryPart };
	print();
	std::cout << " - ";
	c.print();
	std::cout << " = ";
	temp.print();
	return temp;
}

void Complex::print() const
{
	std::cout << "(" << realPart << "," << imaginaryPart << ")";
}
