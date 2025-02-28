#pragma once
class Time
{
	friend void tick(Time& t); // increment one second 
public:
	explicit Time(int = 0, int = 0, int = 0);

	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	unsigned int getHour()const;
	unsigned int getMinute()const;
	unsigned int getSecond()const;

	void printUniversal()const;
	void printStandard()const;
#ifdef TICK_IN_TIME
	void tick();
#endif
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;

};

