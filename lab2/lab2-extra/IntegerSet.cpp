#include "IntegerSet.h"
#include <iostream>
#include <stdexcept> // Corrected include directive

IntegerSet::IntegerSet() : set_exist_state{ 0 }
{
}

IntegerSet::IntegerSet(const int(&a)[set_size])
{
	for (int i = 0; i < set_size; ++i)
	{
		if (a[i] != 1 && a[i] != 0)
			throw std::invalid_argument("failed to initialize err: set provided beyond exception");;

	}
	for (int i = 0; i < set_size; ++i)
	{
		set_exist_state[i] = a[i];
	}
}

IntegerSet IntegerSet::operator+(IntegerSet a) const
{
	IntegerSet temp;
	for (int i = 0; i < set_size; ++i)
	{
		if (set_exist_state[i] || a.set_exist_state[i])
		{
			temp + i;
		}
	}
	return temp;
}

IntegerSet IntegerSet::operator-(IntegerSet a) const
{
	IntegerSet temp;
	for (int i = 0; i < set_size; ++i)
	{
		if (set_exist_state[i] && a.set_exist_state[i])
		{
			temp + i;
		}
	}
	return temp;
}

IntegerSet& IntegerSet::operator=(IntegerSet a)
{
	for (size_t i = 0; i < set_size; ++i)
	{
		set_exist_state[i] = a.set_exist_state[i];
	}
	return (*this);
}

IntegerSet& IntegerSet::operator+(int i)
{
	if (validEntry(i))
		set_exist_state[i] = 1;
	else
		std::cout << "Invalid insert attempted\n";
	return (*this);
}

IntegerSet& IntegerSet::operator-(int i)
{
	if (validEntry(i))
		set_exist_state[i] = 0;
	else
		std::cout << "Invalid delete attempted\n";
	return (*this);
}

bool IntegerSet::operator==(IntegerSet a) const
{
	for (int i = 0; i < set_size; ++i)
	{
		if (set_exist_state[i] != a.set_exist_state[i])
			return false;
	}
	return true;
}

bool IntegerSet::isEmpty()const
{
	for (int item : set_exist_state)
		if (item == 1)
			return false;
	return true;
}

bool IntegerSet::validEntry(int i) const
{
	if (i < set_size && i >= 0)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream& output, const IntegerSet& s) //with a \n at the end
{
	if (s.isEmpty())
		std::cout << "---\n";
	else
	{

		for (int i = 0; i < s.set_size; ++i)
		{
			if (s.set_exist_state[i])
				std::cout << i << " ";
		}
	}
	return output;
}
std::istream& operator>>(std::istream& input, IntegerSet& s)
{
	for (int inp = 0; (input >> inp) && (inp != -1);)
	{
		if ((inp < 0) || (inp > 100)) {
			std::cout << ("Input must be 0-100");
			continue;
		}
		else {
			s + inp;
		}
	}
	return input;
}