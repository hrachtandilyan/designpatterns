#pragma once
#include "BikeBuilder.h"
#include "Bike.h"

class TrekBuilder: public BikeBuilder
{
private:
	Bike * bike;
public:
	TrekBuilder();
	void build_frame();
	void build_wheels();
	void build_handlebar();
	Bike *getBike();
	void print();
};

