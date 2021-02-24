#pragma once
#include "Guns.h"

class Rifle : public Guns
{
public:
	double getWeight()
	{
		return 7.00;
	}
	double getCost()
	{
		return 800.00;
	}
};

