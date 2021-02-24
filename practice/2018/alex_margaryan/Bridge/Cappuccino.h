#pragma once
#include <iostream>
#include "Coffee.h"

class Cappuccino : public Coffee
{
public:
	Cappuccino(Packaging * packaging)
		:Coffee(packaging)
	{}

	void print()
	{
		packaging->print();
	}
};

