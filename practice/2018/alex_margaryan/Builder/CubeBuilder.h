#pragma once
#include "BikeBuilder.h"
#include "Bike.h"

class CubeBuilder: public BikeBuilder
{
private:
	Bike * bike;
public:
	CubeBuilder();
	void build_frame();
	void build_wheels();
	void build_handlebar();
	Bike *getBike();
	void print();
};

