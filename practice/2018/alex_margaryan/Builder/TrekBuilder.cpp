#include "TrekBuilder.h"
#include <iostream>


TrekBuilder::TrekBuilder()
{
	bike = new Bike();
}

void TrekBuilder::build_frame()
{
	bike->set_frame("Trek frame");
}

void TrekBuilder::build_wheels()
{
	bike->set_wheels("Trek wheels");
}

void TrekBuilder::build_handlebar()
{
	bike->set_handlebar("Trek handlebar");
}

Bike * TrekBuilder::getBike()
{
	print();
	return bike;
}

void TrekBuilder::print()
{
	std::cout << bike->get_frame() << endl << bike->get_wheels() << endl << bike->get_handlebar() << endl;
}

