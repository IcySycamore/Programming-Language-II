// Fig. 12.16: BasePlusCommissionEmployee.cpp
// BasePlusCommissionEmployee member-function definitions.
#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor 
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string& first, const string& last, const string& ssn,
	double sales, double rate, double salary, Date date)
	: CommissionEmployee(first, last, ssn, sales, rate, date)
{
	setBaseSalary(salary); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first, const std::string& last,
	const std::string& ssn, double sales, double rate, double salary, int month, int day, int year)
	: CommissionEmployee(first, last, ssn, sales, rate, month, day, year)
{
	setBaseSalary(salary); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
		baseSalary = salary;
	else
		throw invalid_argument("Salary must be >= 0.0");
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
} // end function getBaseSalary

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const
{
	return getBaseSalary() + CommissionEmployee::earnings();
} // end function earnings

// print BasePlusCommissionEmployee's information 
void BasePlusCommissionEmployee::print() const
{
	cout << "base-salaried ";
	CommissionEmployee::print(); // code reuse
	cout << "; base salary: " << getBaseSalary();
} // end function print


