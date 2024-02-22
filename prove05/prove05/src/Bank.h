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
	list<Account> accounts;
public:
	Bank();
	Bank(const Bank &bank);
	~Bank();

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
