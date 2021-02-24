#pragma once
#include <iostream>
#include "Account.h"

class YoutubeAccount: public Account
{
public:
	Account * clone()
	{
		return new YoutubeAccount;
	}
	void print()
	{
		std::cout << " The youtube account has been created! " << std::endl;
	}
};

