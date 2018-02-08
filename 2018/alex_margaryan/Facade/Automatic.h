#pragma once
#include <iostream>
#include "Watches.h"

class Automatic : public Watches
{
public:
	void print()
	{
		std::cout << "This is an automatic watch." << std::endl;
	}
};

