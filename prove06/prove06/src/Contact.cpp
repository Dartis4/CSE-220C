/*
 * Contact.cpp
 *
 *  Created on: May 17, 2022
 *      Author: dane artis
 */

#include "Contact.h"

#include <iostream>

using namespace std;

Contact::Contact() {
	this->street_address = "### street";
	this->city = "city";
	this->state = "state";
	this->zip_code = "#####";
	this->phone_number = "###-###-####";
}

Contact::Contact(const Contact &rhs) {
	this->street_address = rhs.street_address;
	this->city = rhs.city;
	this->state = rhs.state;
	this->zip_code = rhs.zip_code;
	this->phone_number = rhs.phone_number;
}

Contact::~Contact() {}

void Contact::prompt() {
	// Ignore newline characters from last user input
	cin.ignore(256, '\n');

	cout << "Enter Address: ";
	getline(cin, this->street_address);

	cout << "Enter City: ";
	getline(cin, this->city);

	cout << "Enter State: ";
	getline(cin, this->state);

	cout << "Enter Zip Code: ";
	cin >> this->zip_code;
	cout << "Enter Phone Number: ";
	cin >> this->phone_number;
}

ostream& Contact::output(ostream &data) {
	data << "+ Contact Information:";
	data << " Address: " << this->street_address;
	data << " City: " << this->city;
	data << " State:" << this->state;
	data << " Zip: " << this->zip_code;
	data << " Phone: " << this->phone_number << endl;
	return data;
}

ostream& operator <<(ostream &out, Contact& rhs) {
	rhs.output(out);
	return out;
}
