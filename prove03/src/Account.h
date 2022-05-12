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

		void create();
		ostream& output(ostream& data);
		int getID() const;

		Account& operator += (const float& rhs);
		Account& operator -= (const float& rhs);
		friend bool operator == (const Account& lhs, const Account& rhs) {
			return lhs.getID() == rhs.getID();
		}
		friend bool operator != (const Account& lhs, const Account& rhs) {
			return lhs.getID() != rhs.getID();
		}
		friend ostream& operator << (ostream& out, Account& rhs)
		{
			rhs.output(out);
			return out;
		}
	};
}