#include "EmployeeAndOrder.h"
#include <iostream>
using namespace std;
int main()
try {
	Employee employee1("Mike Smith", 26);
	Employee employee2("Reimu", 19);
	Employee employee3("Remilia Scarrett", 5);
	Employee employee4("Yuyuko", 672);
	Employee employee5("weapon a", 666);

	employee1.add_orders("honey-stewed BBQ pork", "12:30:00", true);
	employee1.add_orders("oily bean curd", "12:30:00", false);
	employee1.add_orders("eggs Benedict", "12:30:00", false);
	employee1.add_orders("humberger", "12:30:00", true);

	employee2.add_orders("Seafood miso soup", "11:50:00", true);
	employee2.add_orders("Seafood miso soup", "11:50:00", true);
	employee2.add_orders("Seafood miso soup", "11:50:00", true);

	employee3.add_orders("duck blood", "11:00:00");
	employee3.add_orders("dog blood", "12:00:00");
	employee3.add_orders("red tea", "13:00:00", true);

	employee4.add_orders("bird", "12:00:00");
	employee4.add_orders("bird", "12:00:00");
	employee4.add_orders("bird", "12:00:00");
	employee4.add_orders("bird", "12:00:00");
	employee4.add_orders("bird", "12:00:00");

	employee5.add_orders("Moon", "23:00:00", true);

	employee3.setAge(500);

}
catch (runtime_error& e)
{
	cout << e.what() << endl;
}
