// prove03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Account.h"
#include "Bank.h"

#include <iostream>

using namespace bank_tracker;
using std::cout;
using std::cin;
using std::endl;

void display_menu(void) {
	cout << "Account Menu:" << endl;
	cout << "0. Quit Program" << endl;
	cout << "1. Display Account Information" << endl;
	cout << "2. Add a deposit to an account" << endl;
	cout << "3. Withdraw from an account" << endl;
	cout << "4. Add new account" << endl;
	cout << "5. Find account by ID" << endl;
}

int id() {
	int id = 0;
	cout << "Enter the ID of the account to find: ";
	cin >> id;
	return id;
}

void menu(Bank& bank)
{
	int option = 1;

	display_menu();
	cout << "Your choice: ";
	cin >> option;

	switch (option) {
	case 1:
		cout << bank;
		break;
	case 2:
		bank.depositAccount(id());
		break;
	case 3:
		bank.withdrawAccount(id());
		break;
	case 4:
		Account newAccount = new Account();
		newAccount.create();
		bank += newAccount;
		break;
	case 5:
		bank.findAccount(id());
		break;
	default:
		break;
	}
	cout << endl;

	if (option)
		menu(bank);
}

int main(void) {
	Bank myBank;
	menu(myBank);
}