/*
 * Bank.h
 *
 *  Created on: May 10, 2022
 *      Author: dane artis
 */

#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <list>

#include "Account.h"

using std::list;
class Bank {
private:
	int id;
	string name;
	list<Account> accounts;
	static int next_id;
public:
	Bank();
	Bank(const Bank &bank);
	~Bank();

	string getName();
	int getID();
	void setName();

	int size();
	ostream& output(ostream &data);
	list<Account>::iterator findAccount(int id);
	void removeAccount(int id);
	void withdrawAccount(list<Account>::iterator account, float withdraw);
	void depositAccount(list<Account>::iterator account, float deposit);
	float networth();
	void payDividends(float rate);

	Bank& operator +=(const Account &rhs);
	Bank& operator -=(const Account &rhs);
};
ostream& operator <<(ostream &out, Bank &rhs);

#endif /* BANK_H_ */
