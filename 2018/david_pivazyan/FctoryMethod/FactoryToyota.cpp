#include "Toyota.h"
#include "Corolla.h"
#include "Camry.h"
#include <string>
#include "FactoryToyota.h"

Toyota* FactoryToyota::MakeCar(std::string type)
{
	if (type == "Corolla")
	{
		return new Corolla();
	}
	else if (type == "Camry")
	{
		return new Camry();
	}
	else return 0;
}