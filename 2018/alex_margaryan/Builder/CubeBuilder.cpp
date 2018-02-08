#include "CubeBuilder.h"
#include <iostream>


CubeBuilder::CubeBuilder()
{
	bike = new Bike();
}

void CubeBuilder::build_frame()
{
	bike->set_frame("Cube frame");
}

void CubeBuilder::build_wheels()
{
	bike->set_wheels("Cube wheels");
}

void CubeBuilder::build_handlebar()
{
	bike->set_handlebar("Cube handlebar");
}

Bike * CubeBuilder::getBike()
{
	print();
	return bike;
}

void CubeBuilder::print()
{
	std::cout << bike->get_frame() << endl << bike->get_wheels() << endl << bike->get_handlebar() << endl;
}

