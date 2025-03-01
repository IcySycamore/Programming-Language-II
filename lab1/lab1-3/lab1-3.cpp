#include <iostream>
#include"HugeInteger.h"
using namespace std;
int main()
{
	HugeInteger n1(7654321);
	HugeInteger n2("7654321");
	HugeInteger n3(0);
	HugeInteger n4(7891234);
	HugeInteger n5(5);


	n1.output();
	cout << " + ";
	n4.output();
	cout << " = ";
	n1.add(n4).output();
	cout << endl;

	n4.output();
	cout << " - ";
	n5.output();
	cout << " = ";
	n4.subtract(n5).output();
	cout << endl;

	if (n1.isEqualTo(n2))
	{
		n1.output();
		cout << " is equal to ";
		n2.output();
		cout << endl;
	}

	if (n1.isNotEqualTo(n4))
	{
		n1.output();
		cout << " is not equal to ";
		n4.output();
		cout << endl;
	}

	if (n4.isGreaterThan(n1))
	{
		n4.output();
		cout << " is great than ";
		n1.output();
		cout << endl;
	}

	if (n5.isLessThan(n4))
	{
		n5.output();
		cout << " is less than ";
		n4.output();
		cout << endl;
	}

	if (n5.isLessThanOrEqualTo(n5))
	{
		n5.output();
		cout << " is less than or equal to ";
		n5.output();
		cout << endl;
	}

	if (HugeInteger{ 0 }.isGreaterThanOrEqualTo(n3))
	{
		//...
		cout << "0 is greater than or equal to ";
		n3.output();
		cout << endl;
	}

	if (n3.isZero())
	{
		cout << "n3 contains value 0";
		cout << endl;
	}
}