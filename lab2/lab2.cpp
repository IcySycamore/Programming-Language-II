#include<iostream>
#include"Time.h"
int main()
{

	Time alarm_1(23, 59, 57);
	for (int i = 0; i < 15; ++i)
	{
		alarm_1.printStandard();
		alarm_1.tick();

	}
}