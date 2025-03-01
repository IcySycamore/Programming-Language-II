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

IntegerSet IntegerSet::unionOfSets(IntegerSet a) const
{
	IntegerSet temp;
	for (int i = 0; i < set_size; ++i)
	{
		if (set_exist_state[i] || a.set_exist_state[i])
		{
			temp.insertElement(i);
		}
	}
	return temp;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet a) const
{
	IntegerSet temp;
	for (int i = 0; i < set_size; ++i)
	{
		if (set_exist_state[i] && a.set_exist_state[i])
		{
			temp.insertElement(i);
		}
	}
	return temp;
}

void IntegerSet::insertElement(int i)
{
	if (validEntry(i))
		set_exist_state[i] = 1;
	else
		std::cout << "Invalid insert attempted\n";
}

void IntegerSet::deleteElement(int i)
{
	if (validEntry(i))
		set_exist_state[i] = 0;
	else
		std::cout << "Invalid delete attempted\n";

}

void IntegerSet::printSet() const
{
	if (isEmpty())
		std::cout << "---\n";
	else
	{
		std::cout << "{\t";
		for (int i = 0; i < set_size; ++i)
		{
			if (set_exist_state[i])
				std::cout << i << "\t";
		}
		std::cout << "}\n";
	}
}

bool IntegerSet::isEqualTo(IntegerSet a) const
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
