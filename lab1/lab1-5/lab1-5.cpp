#include "IntegerSet.h"
#include <iostream>

int main()
{
	IntegerSet A{};
	std::cout << "Enter set A:\nEnter an element(-1 to end): ";
	for (int a = 0; std::cin >> a && (a != -1 ? true : false && std::cout << "Entry complete\n");)
	{
		A.insertElement(a);
		std::cout << "Enter an element(-1 to end): ";
	}
	std::cout << "Entry complete\n\n";

	IntegerSet B{};
	std::cout << "Enter set B:\nEnter an element(-1 to end): ";
	for (int a = 0; std::cin >> a && a != -1;)
	{
		B.insertElement(a);
		std::cout << "Enter an element(-1 to end): ";
	}
	std::cout << "Entry complete\n\n";

	std::cout << "Union of A and B is: ";
	A.unionOfSets(B).printSet();
	std::cout << "Intersection of A and B is: ";
	A.intersectionOfSets(B).printSet();
	if (!A.isEqualTo(B))
		std::cout << "Set A is not equal to B\n\n";

	A.insertElement(77);
	std::cout << "\nInserting 77 into Set A...\nSet A is now:\n";
	A.printSet();

	A.deleteElement(77);
	std::cout << "\nDeleting 77 into Set A...\nSet A is now : \n";
	A.printSet();

	A.insertElement(101);
	B.insertElement(-1);

	int arr[IntegerSet::set_size] = {};
	arr[1] = arr[2] = arr[9] = arr[25] = arr[45] = arr[67] = arr[99] = arr[100] = 1;
	IntegerSet e(arr);
	std::cout << "\nSet e is:\n";
	e.printSet();

}
