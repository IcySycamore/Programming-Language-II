// lab3-5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define LAB4




#include <iostream>
using namespace std;


#ifdef LAB1
#include "Lab3-1.h"
int main()
{
	MyBase1 a;
	MyDerived1 b;
#ifdef DEBUG
	MyDerived11 c;
#endif // DEBUG
}
#endif //LAB1
#ifdef LAB2
#include "Lab3-2.h"
int main()
{
	MyBase31 a(1, 2, 3);
#ifdef LAB21
	MyBase32 b(4, 5, 6);
#endif // LAB21
#ifdef LAB22
	MyDerived1 b(88);
#endif // LAB22

}
#endif//LAB2

#ifdef LAB3
#include "Lab3-3.h"
int main()
{
	MyDerived1 a(3);
	a.disply();

	cout << a.x << " " << a.p << " " << a.y << " " << a.z << endl;
	cout << a.getX() << " " << a.getP() << " " << a.getY() << " " << a.getZ() << endl;
}
#endif//LAB3

#ifdef LAB35
#include "Lab35.h"
int main()
{
	MyDerived a;
	a.f1(); a.f2(); a.f3(); a.f22();
}
#endif

#ifdef LAB4
#include "Lab3-4.h"
int main()
{
	MyBase a(2), * p = &a;
	MyDerived b(4), * q = &b;
	MyBase& c = a;
	MyBase& d = b;
	cout << a.getX() << " " << p->getX() << endl;
	cout << b.getY() << " " << q->getY() << b.getX() << " " << q->getX() << endl;
	a = b;
	//cout << a.getX() << " " << a.getY() << endl;
	p = q;
	//cout << p->getX() << " " << p->getY() << endl;

	//cout << c.getX() << " " << d.getX() << " " << d.getY() << endl;
	// 
	//b = a;
	//cout << b.getX() << " " << b.getY() << endl;
}
#endif