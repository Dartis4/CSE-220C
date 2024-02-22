/*
 * Manager.cpp
 *
 *  Created on: May 28, 2022
 *      Author: dane artis
 */

#include "Manager.h"

#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

Manager::Manager() {
	cout << "What would you like to name your management company? \n";
	getline(cin, this->name);
}

Manager::~Manager() {}

int Manager::size() {
	return this->clients.size();
}

string Manager::getName(){
	return this->name;
}

void Manager::openBank(){
	Bank bank;
	bank.setName();
	this->clients.push_back(bank);
}

Bank& Manager::findBank(int id) {
	bool bank_found = false;
	auto client_it = this->clients.begin();
	for (client_it = this->clients.begin(); client_it != this->clients.end(); client_it++) {
		if ((*client_it).getID() == id) {
			cout << (*client_it).getName() << endl;
			bank_found = true;
			break;
		}
	}
	if (!bank_found)
		cout << "Bank not found.\n";
	return *client_it;
}

void Manager::closeBank(int id) {
	this->clients.erase(
			remove_if(this->clients.begin(), this->clients.end(),
					[&](auto bank) {
						return bank.getID() == id;
					}),
			this->clients.end());
}

ostream& Manager::output(ostream &data) {
	data << this->name << endl;
	for_each(this->clients.begin(), this->clients.end(), [&](auto bank) {
		data << bank.getName() << " ID: " << bank.getID() << endl;
	});
	data << endl;
	return data;
}

ostream& operator <<(ostream &out, Manager &rhs) {
	if (rhs.size())
		rhs.output(out);
	else
		out << "No banks open.\n";
	return out;
}



