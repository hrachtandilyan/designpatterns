#pragma once
#include "BikeBuilder.h"
#include "Bike.h"

class Engineer
{
private:
	BikeBuilder * _bikeBuilder;

public:
	Engineer(BikeBuilder *bikeBuilder)
	{
		_bikeBuilder = bikeBuilder;
	}
	void buildBike()
	{
		_bikeBuilder->build_frame();
		_bikeBuilder->build_wheels();
		_bikeBuilder->build_handlebar();
	}
	Bike * getBike()
	{
		return _bikeBuilder->getBike();
	}
};

