#pragma once
#include "Date.h"
#include <string>
class FinalTest
{
private:
	std::string title;
	Date date;
public:

	FinalTest(std::string t, Date dat = Date{}) :title(t), date(dat) {};
	void print() { std::cout << "Title: " << title << "\nTest Date: " << date.getYear() << "-" << date.getMonth() << "-" << date.getDay() << std::endl; }
	void setDue(Date d) { date.setDate(d.getYear(), d.getMonth(), d.getDay()); }
};

