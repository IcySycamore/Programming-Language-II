#include "RationalNumber.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <cmath>
RationalNumber::RationalNumber(int a, int b)// a/b
{
	if (b == 0) {
		throw std::invalid_argument("·ÖÄ¸ÎªÁã");
	}
	else if (b < 0) {
		b = -b;
		a = -a;
	}
	numerator = a;
	denominator = b;
	reduction();
}
RationalNumber RationalNumber::operator+(const RationalNumber& n)const
{

	return RationalNumber((*this).numerator * n.denominator + n.numerator * (*this).denominator, (*this).denominator * n.denominator);
}
RationalNumber RationalNumber::operator-(const RationalNumber& n)const
{
	return RationalNumber((*this).numerator * n.denominator - n.numerator * (*this).denominator, (*this).denominator * n.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& n)const
{
	return RationalNumber((*this).numerator * n.numerator, (*this).denominator * n.denominator);
}

RationalNumber RationalNumber::operator/(RationalNumber& n)const
{
	return RationalNumber((*this).numerator * n.denominator, (*this).denominator * n.numerator);
}

bool RationalNumber::operator>(const RationalNumber& n) const
{
	if (n.numerator == 0)
		return numerator > 0;

	return ((*this) - n) > RationalNumber{};
}

bool RationalNumber::operator<(const RationalNumber& n) const
{
	return !((*this) > n);
}

bool RationalNumber::operator>=(const RationalNumber& n) const
{
	return ((*this) == n || (*this) > n);
}

bool RationalNumber::operator<=(const RationalNumber& n) const
{
	return !((*this) >= n);
}

void RationalNumber::reduction()
{
	int& a = numerator;
	int& b = denominator;
	int c_f = commonFactor(a, b);
	if (c_f != 1) {
		a /= c_f;
		b /= c_f;
	}

}

int RationalNumber::commonFactor(int a, int b)//
{
	a = std::abs(a);
	b = std::abs(b);

	if (a * b == 0) {
		return std::max(a, b);
	}
	int common_factor = 1;
	for (size_t i = 1; i <= std::min(a, b); ++i) {
		if (a % i == 0 && b % i == 0)
			common_factor = i;

	}
	return common_factor;
}

bool RationalNumber::operator==(const RationalNumber& n) const
{
	return (numerator == n.numerator && denominator == n.denominator);
}

bool RationalNumber::operator!=(const RationalNumber& n) const
{
	return !((*this) == n);
}

void RationalNumber::printRational() const
{
	if (denominator == 1)
		std::cout << numerator;
	else
		std::cout << numerator << "/" << denominator;
}
