/*
 * Bank.cpp
 *
 *  Created on: May 10, 2022
 *      Author: dane artis
 */

#include "Bank.h"

#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int Bank::next_id = 0;

Bank::Bank() {
	this->id = this->next_id;
	this->name = "Company";
	this->next_id++;
}

Bank::Bank(const Bank &bank) {
	this->id = bank.id;
	this->name = bank.name;
	this->accounts = bank.accounts;
}

Bank::~Bank() {
}

int Bank::getID(){
	return this->id;
}

string Bank::getName(){
	return this->name;
}

void Bank::setName(){
	cout << "What is the name of this location?\n";
	cin.ignore(256, '\n');
	getline(cin, this->name);
}

int Bank::size() {
	return accounts.size();
}

ostream& Bank::output(ostream &data) {
	for_each(this->accounts.begin(), this->accounts.end(), [&](auto account) {
		data << account << endl;
	});
	return data;
}

list<Account>::iterator Bank::findAccount(int id) {
	bool account_found = false;
	auto account_it = this->accounts.begin();
	for (account_it = this->accounts.begin(); account_it != this->accounts.end(); account_it++) {
		if (account_it->getID() == id) {
			cout << "Found account: " << *account_it << endl;
			account_found = true;
			break;
		}
	}
	if (!account_found)
		cout << "Account not found.\n";
	return account_it;
}

void Bank::removeAccount(int id) {
	this->accounts.erase(
			remove_if(this->accounts.begin(), this->accounts.end(),
					[&](auto account) {
						return account.getID() == id;
					}),
			this->accounts.end());
}

void Bank::withdrawAccount(list<Account>::iterator account, float withdraw) {
	if (account != this->accounts.end())
		*account -= withdraw;
}

void Bank::depositAccount(list<Account>::iterator account, float deposit) {
	if (account != this->accounts.end())
		*account += deposit;
}

float Bank::networth() {
	return accumulate(this->accounts.begin(), this->accounts.end(), 0,
			[&](float accumulator, auto account) {
				return account + accumulator;
			});
}

void Bank::payDividends(float rate) {
	transform(this->accounts.begin(), this->accounts.end(),
			this->accounts.begin(), [&](auto account) {
				return account *= (1 + (rate / 100));
			});
}

Bank& Bank::operator+=(const Account &rhs) {
	this->accounts.push_back(rhs);
	return *this;
}

Bank& Bank::operator-=(const Account &rhs) {
	this->accounts.remove(rhs);
	return *this;
}

ostream& operator <<(ostream &out, Bank &rhs) {
	cout << " " << rhs.getName() << ":\n";
	if (rhs.size())
		rhs.output(out);
	else
		out << "No open accounts.\n";
	return out;
}

