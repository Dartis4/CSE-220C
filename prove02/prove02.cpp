// prove02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Account.h"
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
}

void menu(Account& account)
{
	int option = 1;
	float deposit;
	float withdrawal;
	while (option) {
		deposit = 0.0;
		withdrawal = 0.0;

		display_menu();

		cout << "Your choice: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << account;
			break;
		case 2:
			cout << "Amount to deposit: ";
			cin >> deposit;
			account += deposit;
			break;
		case 3:
			cout << "Amount to withdraw: ";
			cin >> withdrawal;
			account -= withdrawal;
			break;
		default:
			break;
		}
		cout << endl;
	}
	cout << "Goodbye.";
}

int main(void) {
	Account bank_account;
	bank_account.prompt();
	menu(bank_account);
}