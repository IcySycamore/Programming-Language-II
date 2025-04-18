// Fig. 12.10: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <iostream>
#include "Employee.h" // Employee class definition
using namespace std;

// constructor
Employee::Employee(const string& first, const string& last, const string& ssn, const Date& birth)
	: firstName(first), lastName(last), birthDate(birth), socialSecurityNumber(ssn)
{
	// empty body 
} // end Employee constructor

Employee::Employee(const string& first, const string& last, const std::string& ssn, int month, int day, int year)
	: firstName(first), lastName(last), birthDate(Date(month, day, year)), socialSecurityNumber(ssn)
{
}

// set first name
void Employee::setFirstName(const string& first)
{
	firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
	return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName(const string& last)
{
	lastName = last;
} // end function setLastName

// return last name
string Employee::getLastName() const
{
	return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber(const string& ssn)
{
	socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
} // end function getSocialSecurityNumber

Date Employee::getBirthDate() const
{
	return birthDate;
}

void Employee::setBirthDate(const Date& date)
{
	birthDate = date;
}

void Employee::setBirthDate(int m, int d, int y)
{
	birthDate.setDate(m, d, y);
}

// print Employee's information (virtual, but not pure virtual)

void Employee::print() const
{
	cout << getFirstName() << ' ' << getLastName()
		<< "\nsocial security number: " << getSocialSecurityNumber();
} // end function print
