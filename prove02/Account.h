#pragma once

#include <string>
using std::string;
using std::ostream;

namespace bank_tracker
{
	class Account
	{
	private:
		int id;
		string name;
		float balance;
		static int next_id;
	public:
		Account();
		Account(const Account& rhs);
		~Account();
		void prompt();
		ostream& output(ostream& data);
		Account& operator += (const float& rhs);
		Account& operator -= (const float& rhs);
		friend ostream& operator << (ostream& out, Account& rhs)
		{
			rhs.output(out);
			return out;
		}
	};
}