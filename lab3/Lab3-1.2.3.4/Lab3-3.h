#pragma once
#include<iostream>
using namespace std;
#ifdef LAB3
#define LAB31
class MyBase3 {
	int x;
	void fun1() { cout << "MyBase3---fun1()" << endl; }
protected:
	int y;
	void fun2() { cout << "MyBase3---fun2()" << endl; }
public:
	int z;
	MyBase3(int a, int b, int c) { x = a; y = b; z = c; }
	int getX() const { cout << "MyBase3---x:" << endl; return x; }
	int getY() const { cout << "MyBase3---y:" << endl; return y; }
	int getZ() const { cout << "MyBase3---z:" << endl; return z; }
	void fun3() { cout << "MyBase3-- - fun3()" << endl; }
};
#ifdef LAB31
class MyDerived1 : public MyBase3 {
#endif

#ifdef LAB32
	class MyDerived1 : private MyBase3 {
#endif

#ifdef LAB33
		class MyDerived1 : protected MyBase3 {
#endif

			int p;
		public:
			MyDerived1(int a) : p(a), MyBase3(1, 2, 3)
				int getP() { cout << "MyDerived---p:" << endl; return p; }
			int disply()
			{
				cout << p << " " << x << " " << y << " " << z << " " << endl
					<< fun1() << endl << fun2() << endl << fun3() << endl;
			}
}//´íÎóµÄ´úÂë
#endif