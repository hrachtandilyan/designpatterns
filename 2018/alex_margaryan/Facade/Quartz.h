#pragma once
#include <iostream>
#include "Watches.h"

class Quartz : public Watches
{
public:
	void print()
	{
		std::cout << "This is a quartz watch." << std::endl;
	}
};

