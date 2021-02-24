#pragma once
#include <iostream>
#include "Packaging.h"

class ValveSealedBags : public Packaging
{
public:
	void print()
	{
		std::cout << "The coffee is packaged in valve-sealed bags! " << std::endl;
	}
};

