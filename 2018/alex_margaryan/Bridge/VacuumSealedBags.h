#pragma once
#include <iostream>
#include "Packaging.h"

class VacuumSealedBags : public Packaging
{
public:
	void print()
	{
		std::cout << "The coffee is packaged in vacuum-sealed bags! " << std::endl;
	}
};

