#include <iostream>
#include "Complex.h"
int main()
{
	Complex num_1(3, 4);
	Complex num_2(5, 12);
	Complex text_num_none{};
	text_num_none.print();
	std::cout << std::endl;
	num_1.Plus(num_2);
	std::cout << std::endl;
	num_1.Subtraction(num_2);
}