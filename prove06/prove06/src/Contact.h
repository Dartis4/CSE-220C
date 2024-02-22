/*
 * Contact.h
 *
 *  Created on: May 17, 2022
 *      Author: dane artis
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Contact {
private:
	string street_address;
	string city;
	string state;
	string zip_code;
	string phone_number;
public:
	Contact();
	Contact(const Contact &rhs);
	~Contact();

	void prompt();
	ostream& output(ostream &data);
};

ostream& operator <<(ostream &out, Contact &rhs);

#endif /* CONTACT_H_ */
