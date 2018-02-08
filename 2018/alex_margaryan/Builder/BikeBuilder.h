#pragma once
#include "Bike.h"

class BikeBuilder
{
public:
	virtual void build_frame() = 0;
	virtual void build_wheels() = 0;
	virtual void build_handlebar() = 0;
	virtual Bike *getBike() = 0;
	virtual void print() = 0;
};

