#pragma once

#include "Account.h"

#include <iostream>
#include <list>

namespace bank_tracker
{
	using std::list;
	class Bank
	{
	private:
		list<Account> accounts;
	public:
		Bank();
		Bank(const Bank& bank);
		~Bank();

		int size();
		ostream& output(ostream& data);
		Account& findAccount(int id);
		void withdrawAccount(int id);
		void depositAccount(int id);

		Bank& operator += (const Account& rhs);
		Bank& operator -= (const Account& rhs);
		friend ostream& operator << (ostream& out, Bank& rhs)
		{
			if (rhs.size())
				rhs.output(out);
			else
				out << "No open accounts.\n";
			return out;
		}
	};
}
