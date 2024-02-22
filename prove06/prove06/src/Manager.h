/*
 * Manager.h
 *
 *  Created on: May 28, 2022
 *      Author: dane artis
 */

#include "Bank.h"

#ifndef MANAGER_H_
#define MANAGER_H_

class Manager {
private:
	string name;
	list<Bank> clients;
public:
	Manager();
	~Manager();

	int size();
	string getName();
	void openBank();
	Bank& findBank(int id);
	void closeBank(int id);

	ostream& output(ostream &data);
};

ostream& operator <<(ostream &out, Manager &rhs);

#endif /* MANAGER_H_ */
