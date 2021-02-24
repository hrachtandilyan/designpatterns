#pragma once
#include <iostream>
#include "Watches.h"

class Mechanical : public Watches
{
public:
	void print()
	{
		std::cout << "This is a mechanical watch." << std::endl;
	}
};

