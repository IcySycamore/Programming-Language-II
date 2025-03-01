#include<iostream>
#include"Time.h"
#include <stdexcept>
#include <iomanip>
using namespace std;
void tick(Time& t);
int main()
{

	Time alarm_1(23, 59, 57);
	for (int i = 0; i < 15; ++i)
	{
		alarm_1.printStandard();
		tick(alarm_1);
#ifdef TICK_IN_TIME
		alarm_1.tick();
#endif
	}
}
void tick(Time& t)
try
{
	t.setSecond(t.second + 1);
}
catch (invalid_argument& e)
{
	t.second = 0;
	try
	{
		t.setMinute(t.minute + 1);
	}
	catch (invalid_argument& q)
	{
		t.minute = 0;
		try
		{
			t.setHour(t.hour + 1);
		}
		catch (invalid_argument& r)
		{

			t.hour = 0;
		}
	}
}