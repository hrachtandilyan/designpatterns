#pragma once
#include "Decorator.h"

class Muffler : public Decorator
{
public:
	Muffler(Guns *newGun)
		:Decorator(newGun)
	{}

	double getWeight()
	{
		return gun->getWeight() + 0.45;
	}
	double getCost()
	{
		return gun->getCost() + 150.00;
	}
};

