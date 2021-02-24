#pragma once
#include <iostream>
#include "Coffee.h"

class Espresso : public Coffee 
{
public:
	Espresso(Packaging * packaging)
		:Coffee(packaging)
	{}

	void print()
	{
		packaging->print();
	}
};

