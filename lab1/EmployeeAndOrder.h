#pragma once
#include <string>
#include <vector>

class Order
{
private:
	std::string dishName;
	std::string time;
	bool deliverToDesk;
	static int orderCount;
	static const int orderMaximum = 12;
public:
	Order(std::string dish_name, std::string time, bool b);
	void setDishName(std::string s);
	void setTime(std::string s);
	void set_deliver_to_desk(bool b);
	std::string getDishName() const;
	std::string getTime() const;
	bool getRequirement() const;
};




class Employee
{
private:
	std::string name;
	int age;
	const int id;
	static int EmployeeCount;
	std::vector<Order> orders;
public:
	Employee(std::string s, int i);
	void setName(std::string s);
	void setAge(int i);
	void add_orders(std::string s, std::string t, bool b = false);
	std::vector<Order> get_orders()const;
};


