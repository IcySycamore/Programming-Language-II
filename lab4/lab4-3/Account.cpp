#include "Account.h"
#include <iostream>
#include <stdexcept>

Account::Account(double balance, TypeTag tag, std::string id = "")
	: id(id), balance(balance), tag(tag)
{
}

std::string Account::getId() const
{
	return id;
}

double Account::getBalance() const
{
	return balance;
}

TypeTag Account::getTag() const
{
	return tag;
}

void Account::debit(double amount)
{
	if (amount > balance)
	{
		throw std::invalid_argument("Debit amount exceeded account balance");
	}
	else
	{
		balance -= amount;
	}
}

void Account::credit(double amount)
{
	balance += amount;
}
/*********************************************************************/
SavingsAccount::SavingsAccount(double balance, double interestRate)
	: Account(balance, TypeTag(0)), interestRate(interestRate)
{
}

double SavingsAccount::calculateInterest()const
{
	return Account::getBalance() * interestRate;
}

CheckingAccount::CheckingAccount(double balance)
	:Account(balance, TypeTag(1)) {
};