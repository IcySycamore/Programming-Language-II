#pragma once
#include<iostream>
using namespace std;


#ifdef LAB1
#define DEBUG
class MyBase1 {
public:
	MyBase1() { cout << "��BaseClass1 Object is created!" << endl; }
	~MyBase1() { cout << "��BaseClass1 Object is destroyed!" << endl; }
};

class MyDerived1 : public MyBase1 {
public:
	MyDerived1()
	{
		cout << "��First layer derived Object is created!" << endl;
	}
	~MyDerived1()
	{
		cout << "��First layer derived Object is Destroyed!" << endl;
	}
};
#ifdef DEBUG



class MyDerived11 : public MyDerived1 {
public:
	MyDerived11()
	{
		cout << "��Second layer derived Object is created!" << endl;
	}
	~MyDerived11()
	{
		cout << "��Second layer derived Object is destroyed!" << endl;
	}
};

#endif // DEBUG
#endif //LAB1