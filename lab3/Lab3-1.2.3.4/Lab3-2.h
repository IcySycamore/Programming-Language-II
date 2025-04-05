#pragma once
#include<iostream>
using namespace std;
#ifdef LAB2
#define LAB22

class MyBase31 {
	int a, b, c;
public:
	MyBase31(int x, int y, int z) :a(x), b(y), c(z)
	{
		cout << "¡­BaseClass31 Object is created!" << endl;
		cout << a << " " << b << " " << c << endl;
	}
	~MyBase31() { cout << "¡­BaseClass31 Object is destroyed!" << endl; }
	int getA() const { return a; }
	int getB() const { return b; }
	int getC() const { return c; }
};

#ifdef LAB21
class MyBase32 {
	int a, b, c;
public:
	MyBase32(int x, int y, int z)
	{
		cout << "¡­BaseClass32 Object is created!" << endl;
		cout << a << " " << b << " " << c << endl;
		a = x, b = y, c = z;
		cout << a << " " << b << " " << c << endl;
	}
	~MyBase32() { cout << "¡­BaseClass32 Object is destroyed!" << endl; }
};
#endif // LAB21
#ifdef LAB22
class MyDerived1 : protected MyBase31 {
	MyBase31 a{ 5, 6, 7 };
	int c;
public:
	MyDerived1(int x) : c(x), MyBase31(x, 8, 9)
	{
		cout << "¡­Base Object has been created!" << endl;
		cout << "¡­Member Object has been created! " << a.getA() << " " << a.getB() << " " << a.getC() << endl;
		cout << "¡­Derived Object is created! " << c << endl;
	}
};
#endif // LAB22
#endif // LAB2
