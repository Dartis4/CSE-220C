//============================================================================
// Name        : prove06.cpp
// Author      : Dane Artis
//============================================================================

#include <iostream>
#include <list>
#include <string>
#include <iomanip>

#include "Account.h"
#include "Bank.h"
#include "Manager.h"

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

void display_menu(void) {
	cout << "Account Menu:" << endl;
	cout << " 0. Exit" << endl;
	cout << " 1. Display Account Information" << endl;
	cout << " 2. Add a deposit to an account" << endl;
	cout << " 3. Withdraw from an account" << endl;
	cout << " 4. Add new account" << endl;
	cout << " 5. Find account by ID" << endl;
	cout << " 6. Remove account" << endl;
	cout << " 7. Show total balance for all accounts" << endl;
	cout << " 8. Add a dividend to all accounts" << endl;
	cout << " 9. Add contact information to an account" << endl;
}

void main_menu(){
	cout << "Main Menu:" << endl;
	cout << "0. Quit" << endl;
	cout << "1. Open a bank" << endl;
	cout << "2. Close a bank" << endl;
	cout << "3. Manage a bank" << endl;
	cout << "4. Show banks" << endl;
}

int id() {
	int id = 0;
	cout << "Enter the ID of the account to find: ";
	cin >> id;
	return id;
}

int bank_id(){
	int id = 0;
	cout << "Enter the ID of the bank: ";
	cin >> id;
	cout << endl;
	return id;
}

void menu(Bank &bank) {
	int option = 1;

	display_menu();
	cout << "Your choice: ";
	cin >> option;

	switch (option) {
	case 1:
		cout << bank;
		break;
	case 2: {
		list<Account>::iterator account = bank.findAccount(id());
		float deposit = 0.0;
		cout << "Amount to deposit: ";
		cin >> deposit;
		bank.depositAccount(account, deposit);
		break;
	}
	case 3: {
		list<Account>::iterator account = bank.findAccount(id());
		float withdraw = 0.0;
		cout << "Amount to withdraw: ";
		cin >> withdraw;
		bank.withdrawAccount(account, withdraw);
		break;
	}
	case 4: {
		string name;
		float balance;
		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the balance: ";
		cin >> balance;
		Account newAccount(name, balance);
		bank += newAccount;
		break;
	}
	case 5:
		bank.findAccount(id());
		break;
	case 6: {
		int remove_id = 0;
		cout << "Enter account ID to remove: ";
		cin >> remove_id;
		bank.removeAccount(remove_id);
		break;
	}
	case 7: {
		cout << "Total in all accounts: $" << fixed << setprecision(2)
				<< bank.networth() << endl;
		break;
	}
	case 8: {
		float rate = 0.0;
		cout << "Enter the dividend as a percentage: ";
		cin >> rate;
		bank.payDividends(rate);
		break;
	}
	case 9:{
		bank.findAccount(id())->setContactInfo();
		break;
	}
	default:
		break;
	}
	cout << endl;

	if (option)
		menu(bank);
}

int main(void) {
	Manager manager;
	int opt = 1;
	while (opt){
		main_menu();
		cout << "Your choice: ";
		cin >> opt;
		cout << endl;
		switch(opt) {
		case 1:
			manager.openBank();
			cout << endl;
			break;
		case 2:
			manager.closeBank(bank_id());
			break;
		case 3:
			menu(manager.findBank(bank_id()));
			break;
		case 4:
			cout << manager;
			break;
		default:
			break;
		}
	}
}
