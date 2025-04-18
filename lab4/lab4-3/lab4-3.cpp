#include "Account.h"  
#include <vector>  
#include <iostream>  
#include <sstream>
using namespace std;

int main()
{
	SavingsAccount ac1(1000, 0.05);
	CheckingAccount ac2(2000);
	vector<Account*> acvec{ &ac1, &ac2 };

	for (Account* acptr : acvec)
	{
		if (acptr->getTag() == TypeTag(0))
		{
			acptr->credit(acptr->calculateInterest());
		}

		ostringstream os; // Use std::ostringstream instead of std::ostream  
		os << "\nID: " << acptr->getId();
		cout << (acptr->getId() == "" ? "\0" : os.str()) << "\nbalance: $" << acptr->getBalance();
	}
}
