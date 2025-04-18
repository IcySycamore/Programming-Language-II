// Fig. 12.9: Employee.h
// Employee abstract base class.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"Date.h"
#include <string> // C++ standard string class

class Employee
{
public:
	Employee(const std::string&, const std::string&, const std::string&, const Date&);
	Employee(const std::string&, const std::string&, const std::string&, int month, int day, int year);
	virtual ~Employee() {} // virtual destructor

	void setFirstName(const std::string&); // set first name
	std::string getFirstName() const; // return first name

	void setLastName(const std::string&); // set last name
	std::string getLastName() const; // return last name

	void setSocialSecurityNumber(const std::string&); // set SSN
	std::string getSocialSecurityNumber() const; // return SSN
	Date getBirthDate() const; // return birth date
	void setBirthDate(const Date&); // set birth date
	void setBirthDate(int, int, int); // set birth date
	// pure virtual function makes Employee abstract base class
	virtual double earnings() const = 0; // pure virtual
	virtual void print() const; // virtual
protected:
	Date birthDate;
	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
}; // end class Employee

#endif // EMPLOYEE_H
