#include "HugeInteger.h"
#include <iostream>

HugeInteger::HugeInteger(int a) : integer{ 0 }
{
	for (int i = 0; i < integer_size; ++i)
	{
		integer[i] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < integer_size / 2; ++i)
	{
		std::swap(integer[i], integer[integer_size - 1 - i]);
	}
}

HugeInteger::HugeInteger(const char* p) : integer{ 0 }
{
	size_t len = strlen(p);
	for (int i = 0; i < len && *p != '\0'; ++i, ++p)
	{
		integer[integer_size - len + i] = *p - '0';
	}
	output();
}

HugeInteger HugeInteger::add(const HugeInteger& n)
{
	HugeInteger temp;
	int carry = 0;
	for (int i = integer_size - 1; i >= 0; --i)
	{
		int sum = integer[i] + n.integer[i] + carry;
		temp.integer[i] = sum % 10;
		carry = sum / 10;
	}
	return temp;
}

HugeInteger HugeInteger::add(int num)
{
	HugeInteger temp_1(num);
	return this->add(temp_1);
}

HugeInteger HugeInteger::add(const char* num)
{
	HugeInteger temp_2(num);
	return this->add(temp_2);
}

HugeInteger HugeInteger::subtract(const HugeInteger& n)
{
	HugeInteger temp;
	int borrow = 0;
	for (int i = integer_size - 1; i >= 0; --i)
	{
		int diff = integer[i] - n.integer[i] - borrow;
		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		temp.integer[i] = diff;
	}
	return temp;
}

HugeInteger HugeInteger::subtract(int num)
{
	HugeInteger temp_3(num);
	return this->subtract(temp_3);
}

HugeInteger HugeInteger::subtract(const char* num)
{
	HugeInteger temp_4(num);
	return this->subtract(temp_4);
}

bool HugeInteger::isEqualTo(HugeInteger& n)
{
	for (int i = 0; i < integer_size; ++i)
		if (integer[i] != n.integer[i])
			return false;
	return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger& n)
{
	return !isEqualTo(n);
}

bool HugeInteger::isGreaterThan(HugeInteger& n)
{
	for (int i = 0; i < integer_size; ++i)
	{
		if (integer[i] < n.integer[i])
			return false;
		if (integer[i] > n.integer[i])
			return true;
	}
	return false;
}

bool HugeInteger::isLessThan(HugeInteger& n)
{
	return !isGreaterThan(n);
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger& n)
{
	return isGreaterThan(n) || isEqualTo(n);
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger& n)
{
	return !isGreaterThanOrEqualTo(n);
}

bool HugeInteger::isZero()
{
	for (int i = 0; i < integer_size; ++i)
		if (integer[i] != 0)
			return false;
	return true;
}

void HugeInteger::input(const char* numarr)
{
	if (isZero())
		add(numarr);
}

void HugeInteger::output()
{
	if (isZero())
		std::cout << "0";
	else
	{
		bool non_zero_begin = false;
		for (int item : integer)
		{
			if (item != 0 || non_zero_begin)
			{
				non_zero_begin = true;
				std::cout << item;
			}
		}
	}
}
