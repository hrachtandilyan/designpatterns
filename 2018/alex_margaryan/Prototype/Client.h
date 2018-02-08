#pragma once
#include <string>
#include "Account.h"

class Client
{
private:
	static Account * prototypes[3];

public:
	static Account * makeAccount(std::string);
};

