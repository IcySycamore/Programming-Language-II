#pragma once
#include<string>
enum TypeTag { Savings_Account, Checking_Account };
class Account {
public:
	Account(double balance, TypeTag tag, std::string id);
	std::string getId() const;
	void debit(double amount);
	void credit(double amount);
	double getBalance() const;
	TypeTag getTag()const;
	~Account() = default;
	virtual double calculateInterest()const = 0;

private:
	std::string id;
	TypeTag tag;
	double balance;
};
class SavingsAccount : public Account {
public:
	SavingsAccount(double balance, double interestRate);
private:
	double calculateInterest()const;
	double interestRate;

};
class CheckingAccount : public Account {
public:
	CheckingAccount(double balance);
	double calculateInterest()const { return 0.0; };
};