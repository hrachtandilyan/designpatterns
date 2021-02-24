#pragma once
#include "Packaging.h"

class Coffee
{
protected:
	Packaging * packaging;
public:
	Coffee(Packaging * new_packaging)
	{
		packaging = new_packaging;
	}
	virtual void print() = 0;
};

