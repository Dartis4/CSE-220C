//============================================================================
// Name        : prove01_cpp_basics.cpp
// Author      : Dane Artis
// Version     : 1
// Copyright   : MIT license
// Description : Basic accounting program
//============================================================================

#include <iostream>
#include <iomanip>

void display_menu(void);
void display_account(int id, std::string name, float balance);
float deposit_account(float balance);
float withdraw_account(float balance);

int main() {
	int id = 0;
	std::string name;
	float balance = 0.0;

	std::cout << "Enter the name: ";
	std::cin >> name;

	std::cout << "Enter the balance: ";
	std::cin >> balance;

	int option = 1;
	while (option) {
		display_menu();
		std::cout << "Your choice: ";
		std::cin >> option;
		switch (option) {
		case 1:
			display_account(id, name, balance);
			break;
		case 2:
			balance = deposit_account(balance);
			break;
		case 3:
			balance = withdraw_account(balance);
			break;
		default:
			break;
		}
		std::cout << std::endl;
	}
	std::cout << "Goodbye.";
}

void display_menu(void) {
	std::cout << "Account Menu:" << std::endl;
	std::cout << "0. Quit Program" << std::endl;
	std::cout << "1. Display Account Information" << std::endl;
	std::cout << "2. Add a deposit to an account" << std::endl;
	std::cout << "3. Withdraw from an account" << std::endl;
}

void display_account(int id, std::string name, float balance) {
	std::cout << "Account ID: " << id << "  Name: " << name << "  Balance: $"
		<< std::fixed << std::setprecision(2) << balance << std::endl;
}

float deposit_account(float balance) {
	float deposit = 0.0;
	std::cout << "Amount to deposit: ";
	std::cin >> deposit;
	return balance + deposit;
}

float withdraw_account(float balance) {
	float withdrawal = 0.0;
	std::cout << "Amount to withdraw: ";
	std::cin >> withdrawal;
	return balance - withdrawal;
}
