#include "EmployeeAndOrder.h"
#include <iostream>
#include <exception>
using namespace std;
int Order::orderCount = 0;
int Employee::EmployeeCount = 0;
Order::Order(std::string dish_name, std::string t, bool b)
{
	if (orderCount < orderMaximum && orderCount >= 0)
	{
		setDishName(dish_name);
		setTime(t);
		set_deliver_to_desk(b);
		orderCount++;
	}
	else
	{
		throw runtime_error("The number of orders has exceed the maximum: " + std::to_string(orderMaximum) + "\n");
	}

}

void Order::setDishName(std::string s)
{
	dishName = s;
}

void Order::setTime(std::string s)
{
	time = s;
}

void Order::set_deliver_to_desk(bool b)
{
	deliverToDesk = b;
}

std::string Order::getDishName() const
{
	return dishName;
}

std::string Order::getTime() const
{
	return time;
}

bool Order::getRequirement() const
{
	return deliverToDesk;
}
//________________________________________EMPLOY.cpp_____________________________________________________//
Employee::Employee(std::string s, int i)
	:id(EmployeeCount + 1), name(s), age(i)
{
	EmployeeCount++;
	std::cout << "Employee object " << id << " : " << name << "(" << age << " years old) has been created.\n";
}

void Employee::setName(std::string s)
{
	name = s;
}

void Employee::setAge(int i)
{
	age = i;
	std::cout << "Success to Change employee object " << id << " : " << name << "(" << age << " years old) \n";
}

void Employee::add_orders(std::string s, std::string t, bool b)
{
	if (orders.size() < 3)//add过后要不大于3，即之前小于3
	{
		Order temp(s, t, b);
		orders.push_back(temp);
		std::cout << name << ", your order("
			<< temp.getDishName() << " " << temp.getTime() << (temp.getRequirement() ? " Send)" : " Take) ") << "has been created.\n";
	}
	else
	{
		cout << name << ", your number of orders has exceed 3.\n";
	}
}
std::vector<Order> Employee::get_orders() const
{
	return orders;
}
