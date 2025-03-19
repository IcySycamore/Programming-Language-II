// Exercise 11.15 Solution: RationalNumber.h 
// RationalNumber class definition. 
#ifndef RATIONAL_NUMBER_H 
#define RATIONAL_NUMBER_H 
class RationalNumber
{
public:
	RationalNumber(int = 0, int = 1); // default constructor 

	RationalNumber operator+(const RationalNumber& n)const; // addition 
	RationalNumber operator-(const RationalNumber& n)const; // subtraction 
	RationalNumber operator*(const RationalNumber& n)const; // multiplication 
	RationalNumber operator/(RationalNumber& n)const; // division 
	// relational operators 
	bool operator>(const RationalNumber& n) const;
	bool operator<(const RationalNumber& n) const;
	bool operator>=(const RationalNumber& n) const;
	bool operator<=(const RationalNumber& n) const;
	// equality operators 
	bool operator==(const RationalNumber& n) const;
	bool operator!=(const RationalNumber& n) const;
	void printRational() const; // display rational number 

private:
	int numerator; // private variable numerator 
	int denominator; // private variable denominator 
	void reduction(); // function for fraction reduction 
	static int commonFactor(int a, int b);


}; // end class RationalNumber 
#endif