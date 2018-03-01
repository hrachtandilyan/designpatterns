#include <iostream>
#include "FactoryToyota.h"
using namespace std;

int main()
{
	FactoryToyota* Car = new FactoryToyota();
	Toyota* NewCar = Car->MakeCar("Camry");
	NewCar->print();
	Toyota* NewCar2 = Car->MakeCar("Corolla");
	NewCar2->print();
	return 0;
}
