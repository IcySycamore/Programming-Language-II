// main.cpp
// Processing Employee derived-class objects individually 
// and polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <stdexcept>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
using namespace std;

int main()
try {

	// set floating-point output formatting
	cout << fixed << setprecision(2);

	// create derived-class objects
	SalariedEmployee salaried_employee(
		"John", "Smith", "111-11-1111", 800, 9, 11, 2000);
	CommissionEmployee commission_employee(
		"Sue", "Jones", "333-33-3333", 10000, .06, 8, 26, 1972);
	BasePlusCommissionEmployee base_plus_commission_employee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300, 4, 12, 1995);

	cout << "Employees processed individually using static binding:\n\n";


	// create vector of three base-class pointers
	vector < Employee* > employees(3);

	// initialize vector with Employees
	employees[0] = &salaried_employee;
	employees[1] = &commission_employee;
	employees[2] = &base_plus_commission_employee;

	time_t now_sec = time(0);
	struct tm now_tm;
	errno_t err_num = localtime_s(&now_tm, &now_sec);
	if (err_num != 0) {
		cout << "Error getting local time\n";
		throw runtime_error("bad time!error: " + static_cast<char>(err_num));
	}
	for (const Employee* employeePtr : employees) {
		cout << "Employee's name: " << employeePtr->getFirstName() << " " << employeePtr->getLastName() << "\nearning: $";
		if (now_tm.tm_mon + 1 == employeePtr->getBirthDate().getMonth())
			cout << employeePtr->earnings() + 100 << endl;
		else
			cout << employeePtr->earnings() << endl;
	}// note dereferencing
} // end main
catch (const exception& e) {
	cout << "Exception: " << e.what() << endl;
} // end catch
catch (...) {
	cout << "Unknown exception\n";
} // end catch
