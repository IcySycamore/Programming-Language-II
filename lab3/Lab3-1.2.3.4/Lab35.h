#pragma once
#include<iostream>
using namespace std;
class MyBase {
public:
	void f1() { cout << "��MyBase f1-----!" << endl; }
	void f2() { cout << "��MyBase f2-----!" << endl; }
};
class MyDerived : public MyBase {
public:
	void f2() { cout << "��MyDerived f2-----!" << endl; }
	void f22() { MyBase::f2(); cout << "��MyDerived f2-----!" << endl; }
	void f3() { cout << "��MyDerived f3-----!" << endl; }
};