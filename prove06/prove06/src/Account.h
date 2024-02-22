/*
 * Account.h
 *
 *  Created on: May 3, 2022
 *      Author: dane artis
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <memory>
#include <string>

#include "Contact.h"

using std::string;
using std::ostream;
using std::unique_ptr;
using std::shared_ptr;

class Account {
private:
	int id;
	string name;
	float balance;
	static int next_id;
	shared_ptr<Contact> contact_info;

public:
	Account();
	Account(string new_name, float new_balance);
	Account(const Account &rhs);
	~Account();

	int getID() const;
	float getBalance() const;
	void setContactInfo();

	ostream& output(ostream &data);

	Account& operator=(const Account &rhs);
	float operator+(const float rhs);
	float operator-(const float rhs);
	Account& operator +=(const float rhs);
	Account& operator +=(const Account &rhs);
	Account& operator -=(const float rhs);
	Account& operator *=(const float rhs);
};

bool operator ==(const Account &lhs, const int rhs);
bool operator !=(const Account &lhs, const int rhs);
bool operator ==(const Account &lhs, const Account &rhs);
bool operator !=(const Account &lhs, const Account &rhs);
ostream& operator <<(ostream &out, Account &rhs);

#endif /* ACCOUNT_H_ */
