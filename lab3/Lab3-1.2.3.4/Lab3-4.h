#pragma once
#include<iostream>
using namespace std;
class MyBase {
	int x;
public:
	MyBase(int a) :x(a) {};
	int getX() const { cout << " " << endl; return x; }
};
class MyDerived : public MyBase {
	int y;
public:
	MyDerived(int a) :y(a), MyBase(a + 4) {};
	int getY() { cout << " " << endl; return y; }
};