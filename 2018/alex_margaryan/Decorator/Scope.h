#pragma once
#include "Decorator.h"

class Scope : public Decorator
{
public:
	Scope(Guns *newGun) 
		:Decorator(newGun) 
	{}

	double getWeight()
	{
		return gun->getWeight() + 0.65;
	}
	double getCost()
	{
		return gun->getCost() + 340.00;
	}
};

