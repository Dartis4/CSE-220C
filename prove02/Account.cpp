#include "Account.h"

#include <iostream>
#include <iomanip>

using namespace std;
using bank_tracker::Account;

int Account::next_id = 0;

Account::Account() : id{ 0 }, name{ "Unknown" }, balance{ 0 } { };

Account::Account(const Account& rhs)
{
	this->id = rhs.id;
	this->name = rhs.name;
	this->balance = rhs.balance;
}

Account::~Account() { }

// A method that prompts the user to enter the name and the initial balance.
void Account::prompt()
{
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the balance: ";
	cin >> balance;
	cout << endl;
	id = next_id;
	next_id++;
}

// A method that will send the data members to the output stream passed in as a parameter.
ostream& Account::output(ostream& data)
{
	data << "Account ID: " << id;
	data << "  Name: " << name;
	data << "  Balance: $" << fixed << setprecision(2) << balance << endl;
	return data;
}

Account& Account::operator+=(const float& rhs)
{
	balance += rhs;
	return *this;
}

Account& Account::operator-=(const float& rhs)
{
	balance -= rhs;
	return *this;
}
