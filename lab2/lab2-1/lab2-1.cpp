// lab2-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Complex.h"
#include <iostream>
using namespace std;
int main()
{
	Complex x, y(4.3, 8.2), z(3.3, 1.1), k;
	cout << "Enter a complex number in the form: (a, b)\n? ";
	cin >> k; // demonstrating overloaded >> 
	cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
		<< k << '\n'; // demonstrating overloaded << 
	x = y + z; // demonstrating overloaded + and = 
	cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
	x = y - z; // demonstrating overloaded - and = 
	cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
	x = y * z; // demonstrating overloaded * and = 
	cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";
	if (x != k) // demonstrating overloaded != 
		cout << x << " != " << k << '\n';
	cout << '\n';
	x = k;
	if (x == k) // demonstrating overloaded == 
		cout << x << " == " << k << '\n';
	return 0;
} // end main