#ifndef HUGEINT_H 
#define HUGEINT_H 

#include <iostream> 
using std::ostream;
class HugeInt
{
	friend ostream& operator<<(ostream&, const HugeInt&);
public:
	HugeInt(long = 0); // conversion/default constructor 
	HugeInt(const char*); // conversion constructor 
	// addition operator; HugeInt + HugeInt 
	HugeInt operator+(const HugeInt&) const;
	// addition operator; HugeInt + int 
	HugeInt operator+(int) const;
	// addition operator;  
	// HugeInt + string that represents large integer value 
	HugeInt operator+(const char*) const;
	bool operator==(const HugeInt&) const; // equality operator 
	bool operator!=(const HugeInt&) const; // inequality operator 
	bool operator<(const HugeInt&) const; // less than operator 
	// less than or equal to operator 
	bool operator<=(const HugeInt&) const;
	bool operator>(const HugeInt&) const; // greater than operator 
	// greater than or equal to operator 
	bool operator>=(const HugeInt&) const;
	HugeInt operator-(const HugeInt&) const; // subtraction operator 
	HugeInt operator*(const HugeInt&) const; // multiply two HugeInts 
	HugeInt operator/(const HugeInt&) const; // divide two HugeInts ������������a % b =a - b * (a / b)
	int getLength() const;

	HugeInt shifter(int i = 1)const;//��λ������cout<<HugeInt(100).shifter(3) =>100000
	void carry_unit();//��λ�������쳣�����ʱ����integer�д���10�Ľ�λ
	bool isEmpty()const;//��ֵ�����
private:
	short integer[30];
}; // end class HugeInt 
ostream& operator<<(ostream&, const HugeInt&);
#endif 

