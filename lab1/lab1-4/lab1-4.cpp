#include "SimpleCalculator.h"
#include <iostream>
using namespace std;
int main()
{
	double a = 10;
	double b = 20;
	cout << "the value of a is " << a << endl;
	cout << "the value of b is " << b << endl;
	SimpleCalculator sc{};
	cout << "Adding a and b yields " << sc.add(a, b) << endl;
	cout << "Subtracting b from a yields " << sc.subtract(a, b) << endl;
	cout << "Multiplying a by b yields " << sc.multiply(a, b) << endl;
	cout << "Dividing a by b yields " << sc.divide(a, b) << endl;
}

