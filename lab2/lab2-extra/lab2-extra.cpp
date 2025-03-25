#include<iostream>
#include "IntegerSet.h"
using namespace std;
int main() {
	IntegerSet set1;
	IntegerSet set2;
	std::cout << "Please input the set!(end with -1)" << std::endl;
	std::cin >> set1;
	set1 = set1 + 5;
	set1 = set1 + 10;
	set2 = set2 + 10;
	set2 = set2 + 20;
	IntegerSet set3 = set1 + set2;
	std::cout << "Set 1: " << set1 << std::endl;
	std::cout << "Set 2: " << set2 << std::endl;
	std::cout << "Set 3 (Union of Set 1 and Set 2): " << set3 << std::endl;
	set1 = set1 - 10;
	std::cout << "Set 1 after removing 10: " << set1 << std::endl;
	std::cout << "Set 1 == Set 2: " << (set1 == set2) << std::endl;
	std::cout << "Set 1 != Set 2: " << (set1 != set2) << std::endl;
	return 0;
}