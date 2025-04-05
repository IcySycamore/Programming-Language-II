#pragma once
#include<iostream>

class Date
{
public:
	Date(int y = 2014, int m = 1, int d = 1) :year(y), month(m), day(d) {}
	void setDate(int y, int m, int d) { year = y; month = m; day = d; }
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
private:
	int year;
	int month;
	int day;
};

