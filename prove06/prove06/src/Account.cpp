/*
 * Account.cpp
 *
 *  Created on: May 3, 2022
 *      Author: dane artis
 */

#include "Account.h"

#include <iomanip>

#include "Contact.h"

using namespace std;

int Account::next_id = 0;

Account::Account() {
	this->name = "Unknown";
	this->balance = 0;
	this->id = this->next_id;
	this->next_id++;
	this->contact_info = nullptr;
}

Account::Account(string new_name, float new_balance) {
	this->name = new_name;
	this->balance = new_balance;
	this->id = this->next_id;
	this->next_id++;
	this->contact_info = nullptr;
}

Account::Account(const Account &rhs) {
	this->id = rhs.id;
	this->name = rhs.name;
	this->balance = rhs.balance;
	this->contact_info = rhs.contact_info;
}

Account::~Account() {}

int Account::getID() const {
	return this->id;
}

float Account::getBalance() const {
	return this->balance;
}

void Account::setContactInfo() {
	this->contact_info = make_shared<Contact>();
	this->contact_info->prompt();
}

ostream& Account::output(ostream &data) {
	data << "Account ID: " << this->id;
	data << "  Name: " << this->name;
	data << "  Balance: $" << fixed << setprecision(2) << this->balance;
	if (this->contact_info != nullptr) {
		cout << endl;
		this->contact_info->output(data);
	}
	return data;
}

Account& Account::operator =(const Account &rhs) {
	this->balance = rhs.balance;
	return *this;
}

float Account::operator +(const float rhs) {
	return this->balance + rhs;
}

float Account::operator -(const float rhs) {
	return this->balance - rhs;
}

Account& Account::operator +=(const float rhs) {
	this->balance += rhs;
	return *this;
}

Account& Account::operator +=(const Account &rhs) {
	this->balance += rhs.balance;
	return *this;
}

Account& Account::operator -=(const float rhs) {
	this->balance -= rhs;
	return *this;
}

Account& Account::operator *=(const float rhs) {
	this->balance *= rhs;
	return *this;
}

bool operator ==(const Account &lhs, const int rhs) {
	return lhs.getID() == rhs;
}

bool operator !=(const Account &lhs, const int rhs) {
	return lhs.getID() != rhs;
}

bool operator ==(const Account &lhs, const Account &rhs) {
	return lhs.getID() == rhs.getID();
}

bool operator !=(const Account &lhs, const Account &rhs) {
	return lhs.getID() != rhs.getID();
}

ostream& operator <<(ostream &out, Account &rhs) {
	rhs.output(out);
	return out;
}
