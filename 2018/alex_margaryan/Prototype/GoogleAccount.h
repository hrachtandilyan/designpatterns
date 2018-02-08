#pragma once
#include <iostream>
#include "Account.h"

class GoogleAccount: public Account
{
public:
	Account * clone()
	{
		return new GoogleAccount;
	}
	void print()
	{
		std::cout << " The google account has been created! " << std::endl;
	}
};

