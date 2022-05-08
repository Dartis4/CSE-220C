#include "Account.h"

#include <iostream>
#include <iomanip>

using namespace std;
using bank_tracker::Account;

Account::Account() : id{ 0 }, name{ "Unknown" }, balance{ 0 } { };
Account::Account(const Account& rhs) : id{ rhs.id }, name{ rhs.name }, balance{ rhs.balance } { };
Account::~Account() { }

void Account::create()
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
	data << "Account ID: " << this->id;
	data << "  Name: " << this->name;
	data << "  Balance: $" << fixed << setprecision(2) << this->balance;
	return data;
}

int Account::getID() const
{
	return this->id;
}

Account& Account::operator+=(const float& rhs)
{
	this->balance += rhs;
	return *this;
}

Account& Account::operator-=(const float& rhs)
{
	this->balance -= rhs;
	return *this;
}
