// lab3-5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"Date.h"
#include"FinalTest.h"
#include <iostream>

int main()
{
	FinalTest item1("C++ Test", Date(2014, 6, 2));
	item1.print();
	FinalTest item2("Java");
	item2.print();
	item2.setDue(Date(2014, 6, 10));
	item2.print();
}

