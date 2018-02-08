#pragma once
#include "Guns.h"

class Decorator : public Guns
{
public:
	Guns *gun;

	Decorator(Guns *newGun)
	{
		gun = newGun;
	}

	double getWeight()
	{
		return gun->getWeight();
	}
	double getCost()
	{
		return gun->getCost();
	}
};

