#pragma once
#include<iostream>
#include <stdexcept>
class IntegerSet
{
	friend std::istream& operator>>(std::istream& input, IntegerSet& s);
	friend std::ostream& operator<<(std::ostream& output, const IntegerSet& s);//without a \n at the end;
public:
	static constexpr int set_size = 101;//contains 0-set_size-1(set_size=101,0-100)
	IntegerSet();//default initializaton
	IntegerSet(const int(&)[set_size]);//initialization with arr;the size of the array must be set_Size 
	IntegerSet operator+(IntegerSet a)const;
	IntegerSet operator-(IntegerSet a)const;
	IntegerSet& operator=(IntegerSet a);
	IntegerSet& operator+(int i);
	IntegerSet& operator-(int i);

	bool operator==(IntegerSet a) const;
	bool operator!=(IntegerSet a) const
	{
		return!((*this) == a);
	}
	bool isEmpty()const;
	bool validEntry(int i)const;
private:
	int set_exist_state[set_size];

};

