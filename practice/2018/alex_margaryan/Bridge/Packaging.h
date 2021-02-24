#pragma once
#include <iostream>

class Packaging
{
public:
	virtual void print()
	{
		std::cout << "Packaging" << std::endl;
	}
};

