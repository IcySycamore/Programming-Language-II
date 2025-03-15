// lab2-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "HugeInt.h"
#include <iostream>
using namespace std;
int main()
{
	char num[30] = "99999999999999999999999999999";//29char + 1'/0'
	HugeInt n1(7654321L);
	cout << "n1 is " << n1 << endl;
	HugeInt n2(7891234L);
	cout << "n2 is " << n2 << endl;
	HugeInt n3(num);
	cout << "n3 is " << n3 << endl;
	HugeInt n4(1);
	cout << "n4 is " << n4 << endl;
	HugeInt n5(12341234L);
	cout << "n5 is " << n5 << endl;
	HugeInt n6(7888L);
	cout << "n6 is " << n6 << endl;
	cout << "result is 0\n\n";//??????????????????????????????????

	cout << (n1 != n2 ? "n1 is not equal to n2\n" : "");
	cout << (n1 < n2 ? "n1 is less than n2\n" : "");
	cout << (n1 <= n2 ? "n1 is less than or equal to n2\n" : "");
	cout << n1 << " + " << n2 << " = " << n1 + n2 << endl << endl;
	cout << n3 << " + " << n4 << "\n = " << n3 + n4 << endl << endl;
	cout << n1 << " + " << HugeInt(9L) << " = " << n1 + HugeInt(9L) << endl;
	cout << n2 << " + " << HugeInt(10000L) << " = " << n2 + HugeInt(10000L) << endl;
	cout << n5 << " * " << n6 << " = " << n5 * n6 << endl;
	cout << n5 << " - " << n6 << " = " << n5 - n6 << endl;
	cout << n5 << " / " << n6 << " = " << n5 / n6 << endl;
}

