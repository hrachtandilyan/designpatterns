#pragma once
#include <iostream>
#include "Account.h"

class FacebookAccount: public Account
{
public:
	Account * clone()
	{
		return new FacebookAccount;
	}
	void print()
	{
		std::cout << " The facebook account has been created! " << std::endl;
	}
};

