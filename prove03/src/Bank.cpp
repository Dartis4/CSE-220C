#include "Bank.h"

#include <iostream>

using namespace std;
using bank_tracker::Account;
using bank_tracker::Bank;

Bank::Bank() {}

Bank::Bank(const Bank& bank) { this->accounts = bank.accounts; }

Bank::~Bank() {}

int Bank::size() { return accounts.size(); }

ostream& Bank::output(ostream& data)
{
	for (auto account_it = this->accounts.begin(); account_it != this->accounts.end(); account_it++)
		data << *account_it << endl;
	return data;
}

Account& Bank::findAccount(int id) {
	auto account_it = this->accounts.begin();
	for (account_it; account_it->getID() != id && account_it != this->accounts.end(); account_it++) {
		if (account_it->getID() == id)
			cout << "Found account: " << *account_it << endl;
	}
	cout << "Account not found.\n";
	return *account_it;
}

void Bank::withdrawAccount(int id) {
	float withdraw = 0.0;
	cout << "Amount to withdraw: ";
	cin >> withdraw;
	findAccount(id) -= withdraw;
}

void Bank::depositAccount(int id) {
	float deposit = 0.0;
	cout << "Amount to deposit: ";
	cin >> deposit;
	findAccount(id) += deposit;
}

Bank& Bank::operator+=(const Account& rhs)
{
	this->accounts.push_back(rhs);
	return *this;
}

Bank& Bank::operator-=(const Account& rhs)
{
	this->accounts.remove(rhs);
	return *this;
}

