#pragma once
#include "Toyota.h"
#include <string>
class FactoryToyota
{
public:
	static Toyota *MakeCar(std::string type);
};